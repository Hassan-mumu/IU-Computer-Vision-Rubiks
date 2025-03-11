// PWM pins
int pinServ1a = 2;
int pinServ1b = 3;
int pinServ2a = 4;
int pinServ2b = 5;
int pinServ3a = 6;
int pinServ3b = 7;
int pinServ4a = 8;
int pinServ4b = 9;



/////////////////// Calibrate Servo parameters //////////////
// MOREPRESSURE
int gan1b = 145; 
int gan2b = 155;
int gan3b = 145;
int gan4b = 150;

// LESSPRESSURE
// int gan1b = 140;
// int gan2b = 140;
// int gan3b = 130;
// int gan4b = 140;

int xa1b = 1;
int xa2b = 1;
int xa3b = 1;
int xa4b = 1;

//home

int home1a = 170; // 140 170
int home2a = 17; // 13
int home3a = 151; //
int home4a = 14;

// vertical

int dung1a = 179; // 140 170
int dung2a = 17; // 13
int dung3a = 161; //
int dung4a = 5;

// Horizontal

int ngang1a = 70;
int ngang2a = 121; //120
int ngang3a = 55; //68
int ngang4a = 120;

//Serv1a.write(160);
//Serv2a.write(18);
//Serv3a.write(167);
//Serv4a.write(15);



/////////////////// Calibrate Servo parameters //////////////



// Variables
String data = "";
int count = 0;
int L = 0;
int index = 0;
int trash = 0;
bool solved = true;
