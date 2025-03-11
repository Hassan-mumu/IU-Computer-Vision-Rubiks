import cv2
import kociemba
import numpy as np
import serial
from time import sleep


class Constante:
    WIDTH_CANVAS = 800
    HEIGHT_CANVAS = 680
    NEXT = 13
    TOT_FACES = 6
    CANCEL = ord('z')
    QUIT = ord('q')
    COM = "COM8"


def get_color_name(h, s, v):
    """
    A simple heuristic to classify a color (in HSV) into one of the Rubik's cube colors.
    These thresholds may need tuning based on your lighting conditions.
    """
    color = "unknown"
    print(h, s, v)

    # Check for white (low saturation, high brightness)
    if s < 70:
        color = "white"
    # Red can wrap around in hue (0 and near 180)
    elif h > 130 and s > 100:
        color = "red"
    # Orange typically appears in the lower hue range
    elif h < 20:
        color = "orange"
    # Yellow (around 25-35 hue)
    elif 20 <= h < 40:
        color = "yellow"
    # Green (35-85 hue)
    elif 60 <= h < 90:
        color = "green"
    # Blue (85-130 hue)
    elif 90 <= h < 130:
        color = "blue"

    return color


def detect_face_colors(frame):
    """
    Processes the frame by defining a 3x3 grid in the center.
    For each cell, it calculates the mean HSV value and assigns a color.
    """
    height, width, _ = frame.shape
    grid_size = 300  # Size of the square region for the grid
    top_left_x = width // 2 - grid_size // 2
    top_left_y = height // 2 - grid_size // 2
    cell_size = grid_size // 3

    face_colors = []
    for i in range(3):
        row_colors = []
        for j in range(3):
            # Define cell coordinates
            x = top_left_x + j * cell_size
            y = top_left_y + i * cell_size
            cell = frame[y+round(cell_size/3):y+round(cell_size/3*2),
                         x+round(cell_size/3):x+round(cell_size/3*2)]

            # Convert cell from BGR to HSV and compute average color
            hsv_cell = cv2.cvtColor(cell, cv2.COLOR_BGR2HSV)
            h, s, v = cv2.mean(hsv_cell)[:3]
            color = get_color_name(h, s, v)
            row_colors.append(color)
        face_colors.append(row_colors)
    return face_colors


def draw_captured_faces(canvas, cube_faces):
    canvas.fill(255)
    cell_size = 50
    margin = 10
    for f_idx, face in enumerate(cube_faces):
        x_offset = (f_idx % 3) * (3 * cell_size + margin)
        y_offset = (f_idx // 3) * (3 * cell_size + margin)
        for i, row in enumerate(face):
            for j, color in enumerate(row):
                color_bgr = {
                    "white": (255, 255, 255), "red": (0, 0, 255), "orange": (0, 165, 255),
                    "yellow": (0, 255, 255), "green": (0, 255, 0), "blue": (255, 0, 0),
                    "unknown": (128, 128, 128)
                }[color]
                cv2.rectangle(canvas, (x_offset + j * cell_size, y_offset + i * cell_size),
                              (x_offset + (j + 1) * cell_size,
                               y_offset + (i + 1) * cell_size),
                              color_bgr, -1)

# cube table:
# All scanned cube faces:
# Face 1:
# ['white', 'white', 'white']
# ['blue', 'green', 'green']
# ['blue', 'green', 'blue']
# Face 2:
# ['blue', 'blue', 'blue']
# ['white', 'white', 'white']
# ['blue', 'white', 'white']
# Face 3:
# ['blue', 'blue', 'blue']
# ['blue', 'blue', 'red']
# ['blue', 'blue', 'white']
# Face 4:
# ['green', 'green', 'green']
# ['blue', 'blue', 'blue']
# ['blue', 'blue', 'blue']
# Face 5:
# ['blue', 'red', 'red']
# ['blue', 'red', 'red']
# ['red', 'red', 'red']
# Face 6:
# ['green', 'green', 'red']
# ['blue', 'blue', 'blue']
# ['blue', 'blue', 'green']

# BLLBLLBLL BUUFUUFUU LLLBRBBBB UUFUUBUUB FFUBBUBBU FFUFFUBBU
# DRBDFFDUB FBLBLLLLB DRBDFFDUB FLURBUBRF FBLBLLLLB FLURBUBRF
# scan order UP, Right, front, down, left, back


def cubeTableToString(cube):
    # convert all faces to string
    cubestring = ""
    cubeFaces = []
    for i, face in enumerate(cube):
        facestring = ""
        for row in face:
            for color in row:
                match color:
                    case "green":
                        facestring += "F"
                    case "orange":
                        facestring += "L"
                    case "red":
                        facestring += "R"
                    case "yellow":
                        facestring += "D"
                    case "white":
                        facestring += "U"
                    case "blue":
                        facestring += "B"
                    case "unknown":
                        facestring += "U"
        cubeFaces.append(facestring)
    # putting it in right order
    print("\ncubefaces:")
    for i, face in enumerate(cubeFaces):
        print(f"Face {i+1}:")
        print(face)
    newCubeFaces = [None] * 6
    for face in cubeFaces:
        print(face[4])
        match face[4]:
            case "U":
                newCubeFaces[0] = face
            case "R":
                newCubeFaces[1] = face
                print('test')
                print(face)
            case "F":
                newCubeFaces[2] = face
            case "D":
                newCubeFaces[3] = face
            case "L":
                newCubeFaces[4] = face
            case "B":
                newCubeFaces[5] = face
    print("\ncubefaces:")
    for i, face in enumerate(newCubeFaces):
        print(f"Face {i+1}:")
        print(face)
    for face in newCubeFaces:
        cubestring += face
    print(cubestring)
    return cubestring

# convert cubestring to instructions using kociemba algorithm kociemba.solve(cubeTableToString(cube_faces))


def draw_cube(canvas, cube_faces):
    canvas.fill(30)
    cell_size = 50
    positions = {
        "green": (3, 3),  # Face avant (centre)
        "yellow": (3, 6),  # Face du bas
        "red": (6, 3),  # Face de droite
        "orange": (0, 3),  # Face de gauche
        "white": (3, 0),  # Face du dessus
        "blue": (9, 3)  # Face arrière
    }

    for face in cube_faces:
        center_color = face[1][1]
        if center_color not in positions:
            continue
        x_offset, y_offset = positions[center_color]
        for i, row in enumerate(face):
            for j, color in enumerate(row):
                color_bgr = {
                    "white": (255, 255, 255), "red": (0, 0, 255), "orange": (0, 165, 255),
                    "yellow": (0, 255, 255), "green": (0, 255, 0), "blue": (255, 0, 0),
                    "unknown": (128, 128, 128)
                }[color]
                cv2.rectangle(canvas, ((x_offset + j) * cell_size, (y_offset + i) * cell_size),
                              ((x_offset + j + 1) * cell_size,
                               (y_offset + i + 1) * cell_size),
                              color_bgr, -1)
                cv2.rectangle(canvas, ((x_offset + j) * cell_size, (y_offset + i) * cell_size),
                              ((x_offset + j + 1) * cell_size,
                               (y_offset + i + 1) * cell_size),
                              (50, 50, 50), 1)


def detect_face_colors(frame):

    height, width, _ = frame.shape
    grid_size = 300
    top_left_x = width // 2 - grid_size // 2
    top_left_y = height // 2 - grid_size // 2
    cell_size = grid_size // 3

    face_colors = []
    for i in range(3):
        row_colors = []
        for j in range(3):
            x = top_left_x + j * cell_size
            y = top_left_y + i * cell_size
            cell = frame[y+round(cell_size/3):y+round(cell_size/3*2),
                         x+round(cell_size/3):x+round(cell_size/3*2)]
            hsv_cell = cv2.cvtColor(cell, cv2.COLOR_BGR2HSV)
            h, s, v = cv2.mean(hsv_cell)[:3]
            color = get_color_name(h, s, v)
            row_colors.append(color)
        face_colors.append(row_colors)
    return face_colors


def main():
    cap = cv2.VideoCapture(0)
    if not cap.isOpened():
        print("Cannot open webcam")
        return

    canvas = np.ones((Constante.HEIGHT_CANVAS, Constante.WIDTH_CANVAS,
                     3), dtype=np.uint8) * 30  # dark screen

    # open serial communications
    ser = serial.Serial(Constante.COM, 9600, timeout=1)

    face_count = 0
    cube_faces = []
    print("Position the cube face inside the grid and press 'Enter' to capture.")
    print("Press 'q' to quit anytime.")
    rescan = False

    while True:

        ret, frame = cap.read()
        if not ret:
            print("Failed to grab frame")
            break

        # Draw a 3x3 grid in the center of the frame
        height, width, _ = frame.shape
        grid_size = 300
        top_left_x = width // 2 - grid_size // 2
        top_left_y = height // 2 - grid_size // 2

        cell_size = grid_size // 3

        for i in range(4):
            # Draw vertical grid lines
            cv2.line(frame, (top_left_x + i * cell_size, top_left_y),
                     (top_left_x + i * cell_size, top_left_y + grid_size), (0, 255, 0), 2)
            # Draw horizontal grid lines
            cv2.line(frame, (top_left_x, top_left_y + i * cell_size),
                     (top_left_x + grid_size, top_left_y + i * cell_size), (0, 255, 0), 2)

        cv2.putText(frame, f"Face {face_count}/6", (10, 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

        if rescan:
            cv2.putText(frame, f"wrong scan, try again", (200, 30),
                        cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

        cv2.imshow("Cube Scanner", frame)
        draw_cube(canvas, cube_faces)
        cv2.imshow("Captured Faces", canvas)

        key = cv2.waitKey(1) & 0xFF

        # Check if Enter key (ASCII 13) is pressed to capture the face

        if key == Constante.NEXT and face_count < 6:
            captured_frame = frame.copy()
            face_colors = detect_face_colors(captured_frame)
            draw_captured_faces(canvas, cube_faces)
            cube_faces.append(face_colors)
            face_count += 1
            print(f"\nCaptured face {face_count}:")
            for row in face_colors:
                print(row)

            print("Reposition the cube for the next face...\n")
            cv2.waitKey(500)  # Brief pause to allow repositioning

        # Quit if 'q' is pressed
        elif key == Constante.QUIT:
            goodScan = True
            try:
                print(cubeTableToString(cube_faces))
                message = kociemba.solve(cubeTableToString(cube_faces))
                print(message)

                ser.write("START\n".encode('utf-8'))
                ser.flush()

                sleep(2)

                ser.write((message + "\n").encode('utf-8'))
                ser.flush()
                
                while True :
                    if ser.readline().decode("utf-8") == "STOP":
                        break   
                

            except ValueError:
                goodScan = False
                cube_faces.clear()
                face_count = 0
                rescan = True

            if goodScan:
                print("scan sucessful")
                break

        elif key == Constante.CANCEL:
            cube_faces.pop()
            face_count -= 1
            print("previous face canceled")

    cap.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
