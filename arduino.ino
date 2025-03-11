//access the built-in servo library
#include "khaibao.h"
#include <Servo.h>

Servo Serv1a; // Create a servo object named Serv1a
Servo Serv1b; // Create a servo object named Serv1b
Servo Serv2a; // Create a servo object named Serv2a
Servo Serv2b; // Create a servo object named Serv2b
Servo Serv3a; // Create a servo object named Serv3a
Servo Serv3b; // Create a servo object named Serv3b
Servo Serv4a; // Create a servo object named Serv4a
Servo Serv4b; // Create a servo object named Serv4b
int spd = 200;
int spda = 200;

void ini() {
  // Vertical
  Serv1a.write(dung1a);
  Serv2a.write(dung2a);
  Serv3a.write(dung3a);
  Serv4a.write(dung4a);
  // Backward
  Serv1b.write(xa1b);
  Serv2b.write(xa2b);
  Serv3b.write(xa3b);
  Serv4b.write(xa4b);
  delay(100);

  // Attach the servo motors to their pins
  Serv1b.attach(pinServ1b);
  Serv2b.attach(pinServ2b);
  Serv3b.attach(pinServ3b);
  Serv4b.attach(pinServ4b);
  delay(500);

  Serv1a.attach(pinServ1a);
  delay(500);
  Serv2a.attach(pinServ2a);
  delay(500);
  Serv3a.attach(pinServ3a);
  delay(500);
  Serv4a.attach(pinServ4a);
  delay(500);
}


/////////////////////////////////// Write your own functions ///////////////////////////////////
void Start() {    // Grab the Rubik cube when type START
Serv1a.write(dung1a);
Serv2a.write(dung2a);
Serv3a.write(dung3a);
Serv4a.write(dung4a);

Serv1b.write(140);
Serv2b.write(140);
Serv3b.write(130);
Serv4b.write(140);

}

void End() {    // Release the Rubik cube when type END
delay(250);
Serv1b.write(5);
Serv2b.write(5);
Serv3b.write(5);
Serv4b.write(5);
}
/////////////////////////////////// Write your own functions ///////////////////////////////////



void setup() {
  Serial.begin(9600);
  ini();
  Serial.println("Done!");
  Serial.println("Input the rubik cube");
  Serial.println("Type START to grab");
}

void home() {
  Serv1a.write(home1a);
  Serv2a.write(home2a);
  Serv3a.write(home3a);
  Serv4a.write(home4a);
}

void loop()
{
  if (solved == false) {
    // wait for moves
    if (Serial.available() > 0) {
      data = Serial.readStringUntil('\n');
      Serial.print("data: ");
      Serial.println(data);

      // Get "END": release the Rubik cube
      if (data == "END") {
        solved = true;
        Serial.println("STOP");
        End();
        Serial.print("START?");
      } else {
        L = data.length();
        index = 1;
        String S[int(L / 2) + 1];

        /*String analyze*/
        trash = 0;
        /*Data tracking*/
        count = 0;
        while (index > 0) {
          index = data.indexOf(' ');
          //                          Serial.println(index);
          if (index > 0) {
            S[trash] = data.substring(0, index);
          } else {
            S[trash] = data.substring(0, L);
          }
          //                          Serial.println(S[trash]);
          trash = trash + 1;
          count = index + 1;
          data = data.substring(count, L);
        }
        /* OUTPUT: s (sequence of solve steps)*/
        trash = 0;
        while (trash < int(L / 2) + 1) {

/////////////////////////////////// Write your own code ///////////////////////////////////
          // Example:
          if (S[trash] == "F") {    // Rotate Front Clockwise
            Serial.println("Got F");
            Serv1a.write(dung1a);
            delay(spda);
            Serv1b.write(xa1b);
            delay(spd);
            Serv1a.write(ngang1a);
            delay(spda);
            Serv1b.write(gan1b);
            delay(spd);
            Serv1a.write(dung1a);
            delay(spda);
            
          }
          if (S[trash] == "F2") {    // Rotate Front Clockwise  twice
            Serial.println("Got F2");
            Serv1a.write(dung1a);
            delay(spda);
            Serv1b.write(xa1b);
            delay(spd);
            Serv1a.write(ngang1a);
            delay(spda);
            Serv1b.write(gan1b);
            delay(spd);
            Serv1a.write(dung1a); //rotate 2
            delay(spda);
            Serv1b.write(xa1b);
            delay(spd);
            Serv1a.write(ngang1a);
            delay(spda);
            Serv1b.write(gan1b);
            delay(spda);
            Serv1a.write(dung1a);
            delay(spda);

            home();
          }
          else if (S[trash] == "F'") {    // Rotate Front counter-Clockwise
            Serial.println("Got F'");
            Serv1a.write(dung1a);
            delay(spda);
            Serv1b.write(gan1b);
            delay(spd);
            Serv1a.write(ngang1a);
            delay(spda);
            Serv1b.write(xa1b);
            delay(spd);
            Serv1a.write(dung1a);
            delay(spda);
            Serv1b.write(gan1b);
            delay(spd);

            home();

          }
          else if (S[trash] == "F'2") {    // Rotate Front counter-Clockwise
            Serial.println("Got F'2");
            Serv1a.write(dung1a);
            delay(spda);
            Serv1b.write(gan1b);
            delay(spd);
            Serv1a.write(ngang1a);
            delay(spda);
            Serv1b.write(xa1b);
            delay(spd);
            Serv1a.write(dung1a);
            delay(spda);
            Serv1b.write(gan1b);
            delay(spd);
            Serv1a.write(dung1a);
            delay(spda);
            Serv1b.write(gan1b);
            delay(spd);
            Serv1a.write(ngang1a);
            delay(spda);
            Serv1b.write(xa1b);
            delay(spd);
            Serv1a.write(dung1a);
            delay(spda);
            Serv1b.write(gan1b);
            delay(spd);

            home();

          }
          else if (S[trash] == "R'") {    // Rotate right counter Clockwise
            Serial.println("Got R'");
            Serv4b.write(xa4b);
            delay(spd);
            Serv4a.write(ngang4a); // horizontal
            delay(spda);
            Serv4b.write(gan4b); // closer
            delay(spd);
            Serv4a.write(dung4a);
            delay(spda);

            home();

          }
          else if (S[trash] == "R'2") {    // Rotate right Clockwise twice
            Serial.println("Got R'2");
            Serv4b.write(xa4b);
            delay(spd);
            Serv4a.write(ngang4a); // horizontal
            delay(spda);
            Serv4b.write(gan4b); // closer
            delay(spd);
            Serv4a.write(dung4a);
            delay(spda);
            Serv4b.write(xa4b);
            delay(spd);
            Serv4a.write(ngang4a); // horizontal
            delay(spda);
            Serv4b.write(gan4b); // closer
            delay(spd);
            Serv4a.write(dung4a);
            delay(spda);

            home();

          }

          else if (S[trash] == "R") {    // Rotate right counter Clockwise
            Serial.println("Got R");
            Serv4a.write(ngang4a); // horizontal
            delay(spda);
            Serv4b.write(xa4b);// AWAY
            delay(spd);
            Serv4a.write(dung4a);
            delay(spda);
            Serv4b.write(gan4b); // closer
            delay(spd);

            home();

          }
          else if (S[trash] == "R2") {    // Rotate right Clockwise twice
            Serial.println("Got R2");
            Serv4a.write(ngang4a); // horizontal
            delay(spda);
            Serv4b.write(xa4b);// AWAY
            delay(spd);
            Serv4a.write(dung4a);
            delay(spda);
            Serv4b.write(gan4b); // closer
            delay(spd);
            Serv4a.write(ngang4a); // horizontal
            delay(spda);
            Serv4b.write(xa4b);// AWAY
            delay(spd);
            Serv4a.write(dung4a);
            delay(spda);
            Serv4b.write(gan4b); // closer
            delay(spd);

            home();

           
          }
          else if (S[trash] == "L") {    // Rotate right counter Clockwise
            Serial.println("Got L");
            Serv3b.write(xa3b);
            delay(spd);
            Serv3a.write(ngang3a); // horizontal
            delay(spd);
            Serv3b.write(gan3b); // closer
            delay(spd);
            Serv3a.write(dung3a);
            delay(spd);

            home();

          }
          else if (S[trash] == "L2") {    // Rotate right Clockwise twice
            Serial.println("Got L2");
            Serv3b.write(xa3b);
            delay(spd);
            Serv3a.write(ngang3a); // horizontal
            delay(spd);
            Serv3b.write(gan3b); // closer
            delay(spd);
            Serv3a.write(dung3a);
            delay(spd);
            Serv3b.write(xa3b);
            delay(spd);
            Serv3a.write(ngang3a); // horizontal
            delay(spd);
            Serv3b.write(gan3b); // closer
            delay(spd);
            Serv3a.write(dung3a);
            delay(spd);

            home();

          }

          else if (S[trash] == "L'") {    // Rotate right counter Clockwise
            Serial.println("Got L'");
            Serv3a.write(ngang3a); // horizontal
            delay(spd);
            Serv3b.write(xa3b);// AWAY
            delay(spd);
            Serv3a.write(dung3a);
            delay(spd);
            Serv3b.write(gan3b); // closer
            delay(spd);

            home();

          }
          else if (S[trash] == "L'2") {    // Rotate right Clockwise twice
            Serial.println("Got L'2");
            Serv3a.write(ngang3a); // horizontal
            delay(spd);
            Serv3b.write(xa3b);// AWAY
            delay(spd);
            Serv3a.write(dung3a);
            delay(spd);
            Serv3b.write(gan3b); // closer
            delay(spd);
            Serv3a.write(ngang3a); // horizontal
            delay(spd);
            Serv3b.write(xa3b);// AWAY
            delay(spd);
            Serv3a.write(dung3a);
            delay(spd);
            Serv3b.write(gan3b); // closer
            delay(spd);

            home();

           
          }
          else if (S[trash] == "B'") {    // Rotate right counter Clockwise
            Serial.println("Got B'");
            Serv2b.write(xa2b);
            delay(spd);
            Serv2a.write(ngang2a); // horizontal
            delay(spd);
            Serv2b.write(gan2b); // closer
            delay(spd);
            Serv2a.write(dung2a);
            delay(spd);

            home();

          }
          else if (S[trash] == "B'2") {    // Rotate right Clockwise twice
            Serial.println("Got B'2");
            Serv2b.write(xa2b);
            delay(spd);
            Serv2a.write(ngang2a); // horizontal
            delay(spd);
            Serv2b.write(gan2b); // closer
            delay(spd);
            Serv2a.write(dung2a);
            delay(spd);
            Serv2b.write(xa2b);
            delay(spd);
            Serv2a.write(ngang2a); // horizontal
            delay(spd);
            Serv2b.write(gan2b); // closer
            delay(spd);
            Serv2a.write(dung2a);
            delay(spd);

            home();

          }

          else if (S[trash] == "B") {    // Rotate right counter Clockwise
            Serial.println("Got B");
            Serv2a.write(ngang2a); // horizontal
            delay(spd);
            Serv2b.write(xa2b);// AWAY
            delay(spd);
            Serv2a.write(dung2a);
            delay(spd);
            Serv2b.write(gan2b); // closer
            delay(spd);

            home();
          }
          else if (S[trash] == "B2") {    // Rotate right Clockwise twice
            Serial.println("Got B2");
            Serv2a.write(ngang2a); // horizontal
            delay(spd);
            Serv2b.write(xa2b);// AWAY
            delay(spd);
            Serv2a.write(dung2a);
            delay(spd);
            Serv2b.write(gan2b); // closer
            delay(spd);
            Serv2a.write(ngang2a); // horizontal
            delay(spd);
            Serv2b.write(xa2b);// AWAY
            delay(spd);
            Serv2a.write(dung2a);
            delay(spd);
            Serv2b.write(gan2b); // closer
            delay(spd);

            home();

           
          }
          
          else if (S[trash] == "U") {    // Rotate up Clockwise
            Serial.println("Got U");
            Serv1b.write(xa1b); // body goes away
            Serv2b.write(xa2b); // body goes away
            delay(spd);


            Serv1a.write(ngang1a);
            Serv2a.write(ngang2a); // hands turn
            delay(spda);

            Serv1b.write(gan1b);
            Serv2b.write(gan2b); // they are now both close (body)
            delay(spd);

            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 now both away
            delay(spd);

            Serv1a.write(dung1a);
            Serv2a.write(dung2a); // hands turn
            delay(spda);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are all close (body)
            delay(spd);
            // copy until here for U, U', D, D'

            Serv4a.write(ngang4a); //U movement is done change here if needed !!
            delay(spda);


            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 are now both away (body)
            delay(spd);

            Serv4a.write(dung4a); // 4 back to position
            delay(spda);

            Serv1a.write(ngang1a);
            Serv2a.write(ngang2a); // they are now back horizontaly
            delay(spda);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are now all close (body)
            delay(spd);

            Serv1b.write(xa1b);
            Serv2b.write(xa2b); // they are now both close (body)
            delay(spd);

            Serv1a.write(dung1a);
            Serv2a.write(dung2a); // they are now both horizontal
            delay(spda);

            Serv1b.write(gan1b);
            Serv2b.write(gan2b); // they are all back 2 position
            delay(spd);

            home();

          }
          else if (S[trash] == "U2") {    // Rotate up Clockwise
            Serial.println("Got U");
            Serv1b.write(xa1b); // body goes away
            Serv2b.write(xa2b); // body goes away
            delay(spd);

            Serv1a.write(ngang1a);
            Serv2a.write(ngang2a); // hands turn
            delay(spda);

            Serv1b.write(gan1b);
            Serv2b.write(gan2b); // they are now both close (body)
            delay(spd);

            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 now both away
            delay(spd);

            Serv1a.write(dung1a);
            Serv2a.write(dung2a); // hands turn
            delay(spda);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are all close (body)
            delay(spd);
            // copy until here for U, U', D, D'

            Serv4a.write(ngang4a); //U movement is done change here if needed !!
            delay(spda);


            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 are now both away (body)
            delay(spd);

            Serv4a.write(dung4a); // 4 back to position
            delay(spda);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(spd);

            Serv4a.write(ngang4a); //U movement is done 2
            delay(spda);

            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 are now both away (body)
            delay(spd);

            Serv4a.write(dung4a); // 4 back to position
            delay(spda);



            Serv1a.write(ngang1a);
            Serv2a.write(ngang2a); // they are now back horizontaly
            delay(spda);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are now all close (body)
            delay(spd);

            Serv1b.write(xa1b);
            Serv2b.write(xa2b); // they are now both close (body)
            delay(spd);

            Serv1a.write(dung1a);
            Serv2a.write(dung2a); // they are now both horizontal
            delay(spda);

            Serv1b.write(gan1b);
            Serv2b.write(gan2b); // they are all back 2 position
            delay(spd);

            home();

          }
          

          else if (S[trash] == "U'") {    // Rotate up Clockwise
            Serial.println("Got U");
            Serv1b.write(xa1b); // body goes away
            Serv2b.write(xa2b); // body goes away
            delay(spd);

            Serv1a.write(ngang1a);
            Serv2a.write(ngang2a); // hands turn
            delay(spda);

            Serv1b.write(gan1b);
            Serv2b.write(gan2b); // they are now both close (body)
            delay(spd);

            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 now both away
            delay(spd);

            Serv1a.write(dung1a);
            Serv2a.write(dung2a); // hands turn
            delay(spda);

            Serv4a.write(ngang4a);
            delay(spda);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are all close (body)
            delay(spd);
            // copy until here for U, U', D, D'

            Serv4a.write(dung4a); //U movement is done change here if needed !!
            delay(spda);


            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 are now both away (body)
            delay(spd);

            Serv1a.write(ngang1a);
            Serv2a.write(ngang2a); // they are now back horizontaly
            delay(spda);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are now all close (body)
            delay(spd);

            Serv1b.write(xa1b);
            Serv2b.write(xa2b); // they are now both close (body)
            delay(spd);

            Serv1a.write(dung1a);
            Serv2a.write(dung2a); // they are now both horizontal
            delay(spda);

            Serv1b.write(gan1b);
            Serv2b.write(gan2b); // they are all back 2 position
            delay(spd);

            home();

          }
          else if (S[trash] == "U'2") {    // Rotate up Clockwise
            Serial.println("Got U");
            Serv1b.write(xa1b); // body goes away
            Serv2b.write(xa2b); // body goes away
            delay(spd);

            Serv1a.write(ngang1a);
            Serv2a.write(ngang2a); // hands turn
            delay(spda);

            Serv1b.write(gan1b);
            Serv2b.write(gan2b); // they are now both close (body)
            delay(spd);

            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 now both away
            delay(spd);

            Serv1a.write(dung1a);
            Serv2a.write(dung2a); // hands turn
            delay(spda);

            Serv4a.write(ngang4a);
            delay(spda);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are all close (body)
            delay(spd);
            // copy until here for U, U', D, D'

            Serv4a.write(dung4a); //U movement is done change here if needed !!
            delay(spda);

            Serv4b.write(xa4b);
            delay(spd);

            Serv4a.write(ngang4a);
            delay(spda);

            Serv4b.write(gan4b);
            delay(spd);

            Serv4a.write(dung4a);
            delay(spda);


            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 are now both away (body)
            delay(spd);

            Serv1a.write(ngang1a);
            Serv2a.write(ngang2a); // they are now back horizontaly
            delay(spda);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are now all close (body)
            delay(spd);

            Serv1b.write(xa1b);
            Serv2b.write(xa2b); // they are now both close (body)
            delay(spd);

            Serv1a.write(dung1a);
            Serv2a.write(dung2a); // they are now both horizontal
            delay(spda);

            Serv1b.write(gan1b);
            Serv2b.write(gan2b); // they are all back 2 position
            delay(spd);

            home();


          }
          else if (S[trash] == "D'") {    // Rotate up Clockwise
            Serial.println("Got D");
            Serv1b.write(xa1b); // body goes away
            Serv2b.write(xa2b); // body goes away
            delay(spd);

            Serv1a.write(ngang1a);
            Serv2a.write(ngang2a); // hands turn
            delay(spda);

            Serv1b.write(gan1b);
            Serv2b.write(gan2b); // they are now both close (body)
            delay(spd);

            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 now both away
            delay(spd);

            Serv1a.write(dung1a);
            Serv2a.write(dung2a); // hands turn
            delay(spda);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are all close (body)
            delay(spd);
            // copy until here for U, U', D, D'

            Serv3a.write(ngang3a); //U movement is done change here if needed !!
            delay(spd);


            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 are now both away (body)
            delay(spd);

            Serv3a.write(dung3a); // 4 back to position
            delay(spd);

            Serv1a.write(ngang1a);
            Serv2a.write(ngang2a); // they are now back horizontaly
            delay(spda);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are now all close (body)
            delay(spd);

            Serv1b.write(xa1b);
            Serv2b.write(xa2b); // they are now both close (body)
            delay(spd);

            Serv1a.write(dung1a);
            Serv2a.write(dung2a); // they are now both horizontal
            delay(spda);

            Serv1b.write(gan1b);
            Serv2b.write(gan2b); // they are all back 2 position
            delay(spd);

            home();


          }
          else if (S[trash] == "D'2") {    // Rotate up Clockwise
            Serial.println("Got D2");
            Serv1b.write(xa1b); // body goes away
            Serv2b.write(xa2b); // body goes away
            delay(spd);

            Serv1a.write(ngang1a);
            Serv2a.write(ngang2a); // hands turn
            delay(spda);

            Serv1b.write(gan1b);
            Serv2b.write(gan2b); // they are now both close (body)
            delay(spd);

            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 now both away
            delay(spd);

            Serv1a.write(dung1a);
            Serv2a.write(dung2a); // hands turn
            delay(spda);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are all close (body)
            delay(spd);
            // copy until here for U, U', D, D'

            Serv3a.write(ngang3a); //U movement is done change here if needed !!
            delay(spd);


            Serv3b.write(xa3b);
            //Serv4b.write(xa4b); // 3 and 4 are now both away (body)
            delay(spd);

            Serv3a.write(dung3a); // 4 back to position
            delay(spd);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(spd);

            Serv3a.write(ngang3a); //U movement is done 2
            delay(spd);

            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 are now both away (body)
            delay(spd);

            Serv3a.write(dung3a); // 4 back to position
            delay(spd);


            Serv1a.write(ngang1a);
            Serv2a.write(ngang2a); // they are now back horizontaly
            delay(spda);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are now all close (body)
            delay(spd);

            Serv1b.write(xa1b);
            Serv2b.write(xa2b); // they are now both close (body)
            delay(spd);

            Serv1a.write(dung1a);
            Serv2a.write(dung2a); // they are now both horizontal
            delay(spda);

            Serv1b.write(gan1b);
            Serv2b.write(gan2b); // they are all back 2 position
            delay(spd);

            home();


          }
          else if (S[trash] == "D") {    // Rotate up Clockwise
            Serial.println("Got D");
            Serv1b.write(xa1b); // body goes away
            Serv2b.write(xa2b); // body goes away
            delay(spd);

            Serv1a.write(ngang1a);
            Serv2a.write(ngang2a); // hands turn
            delay(spda);

            Serv1b.write(gan1b);
            Serv2b.write(gan2b); // they are now both close (body)
            delay(spd);

            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 now both away
            delay(spd);

            Serv1a.write(dung1a);
            Serv2a.write(dung2a); // hands turn
            delay(spda);

            Serv3a.write(ngang3a);
            delay(spd);
            

            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are all close (body)
            delay(spd);
            // copy until here for U, U', D, D'

            Serv3a.write(dung3a); //U movement is done change here if needed !!
            delay(spd);


            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 are now both away (body)
            delay(spd);

            Serv3a.write(dung3a); // 4 back to position
            delay(spd);

            Serv1a.write(ngang1a);
            Serv2a.write(ngang2a); // they are now back horizontaly
            delay(spda);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are now all close (body)
            delay(spd);

            Serv1b.write(xa1b);
            Serv2b.write(xa2b); // they are now both close (body)
            delay(spd);

            Serv1a.write(dung1a);
            Serv2a.write(dung2a); // they are now both horizontal
            delay(spda);

            Serv1b.write(gan1b);
            Serv2b.write(gan2b); // they are all back 2 position
            delay(spd);

            home();

          }
          else if (S[trash] == "D2") {    // Rotate up Clockwise
            Serial.println("Got D2");
            Serv1b.write(xa1b); // body goes away
            Serv2b.write(xa2b); // body goes away
            delay(spd);

            Serv1a.write(ngang1a);
            Serv2a.write(ngang2a); // hands turn
            delay(spda);

            Serv1b.write(gan1b);
            Serv2b.write(gan2b); // they are now both close (body)
            delay(spd);

            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 now both away
            delay(spd);

            Serv1a.write(dung1a);
            Serv2a.write(dung2a); // hands turn
            delay(spda);

            Serv3a.write(ngang3a);
            delay(spd);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are all close (body)
            delay(spd);
            // copy until here for U, U', D, D'

            Serv3a.write(dung3a); //U movement is done change here if needed !!
            delay(spd);

            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // 3 and 4 now both away
            delay(spd);

            Serv3a.write(ngang3a);
            delay(spd);

            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are all close (body)
            delay(spd);

            Serv3a.write(dung3a); //U movement is done change here if needed !!
            delay(spd);

            Serv3b.write(xa3b);
            Serv4b.write(xa4b); // they are now all close (body)
            delay(spd);


            Serv1a.write(ngang1a);
            Serv2a.write(ngang2a); // they are now back horizontaly
            delay(spda);


            Serv3b.write(gan3b);
            Serv4b.write(gan4b); // they are now both close (body)
            delay(spd);

            Serv1b.write(xa1b);
            Serv2b.write(xa2b); // they are now both close (body)
            delay(spd);


            Serv1a.write(dung1a);
            Serv2a.write(dung2a); // they are now both horizontal
            delay(spda);

            Serv1b.write(gan1b);
            Serv2b.write(gan2b); // they are all back 2 position
            delay(spd);

            home();


          }
          

          
          
          else if (S[trash] == "F'") {    // Rotate up counter-Clockwise
            Serial.println("Got F'");
            Serv1a.write(dung1a);
            delay(spda);
            Serv1b.write(gan1b);
            delay(spd);
            Serv1a.write(ngang1a);
            delay(spda);
            Serv1b.write(xa1b);
            delay(spd);
            Serv1a.write(dung1a);
            delay(spda);
            Serv1b.write(gan1b);
            delay(spd);

            home();

          
          
          }

          else if (S[trash] == "F'") {    // Rotate up counter-Clockwise
            Serial.println("Got F'");
            Serv1a.write(dung1a);
            delay(spda);
            Serv1b.write(gan1b);
            delay(spd);
            Serv1a.write(ngang1a);
            delay(spda);
            Serv1b.write(xa1b);
            delay(spd);
            Serv1a.write(dung1a);
            delay(spda);
            Serv1b.write(gan1b);
            delay(spd);

            home();

          }
          
/////////////////////////////////// Write your own code ///////////////////////////////////
          Serial.print(S[trash]);
          Serial.print(" ");
          trash = trash + 1;

        }
        Serial.println(" ");
        Serial.println("Completed!");
        Serial.println("Type END to release");
        data = "";
      }
    }
  } else {
    if (Serial.available() > 0) {
      data = Serial.readStringUntil('\n');
      if (data == "START") {
        Start();
        solved = false;
        Serial.println("Input solving steps");
      }
      data = "";
    }
    data = "";
  }
}
