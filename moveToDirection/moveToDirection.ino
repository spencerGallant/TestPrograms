//Created: Spencer Gallant
//Date last working: August 3rd
//Description: Enter in angle and moves in that direction

//Libraries for Motors
#include <math.h>
#include <SoftwareSerial.h>
#include <PololuQik.h>


PololuQik2s12v10 qik(10, 8, 11); //qik's: (TX, RX. RSET), don't have to have
PololuQik2s12v10 qik1(49, 53, 42);//reset pin is not necessary

float percentSpeed = 75; //base speed (0%-100%)

void setup() {
  Serial.begin(115200); //baud rate. Only used for printing in this program so can change
  
  qik.init(); //initalizing qiks
  qik1.init();

}

void loop() {
  angle(90); //function: angle(degree u want it to go) 0 = forward; counterclockwise going up;
}


double angle(double angle) {
  int s = (percentSpeed/100)*127; //changes percent speed no number
  double LF = (sin((angle+270+45)*0.0174532925))*s; //left front motor speed
  double LB = (sin((angle+180+45)*0.0174532925))*s; //left back
  double RB = (sin((angle+90+45)*0.0174532925))*s; //right back
  double RF = (sin((angle+45)*0.0174532925))*s; //right front
  
  qik1.setM1Speed(LF); // returns sine of angle; // left front
  qik1.setM0Speed(LB); // left back
  qik.setM1Speed(RB); //right back ; >0 is forwad
  qik.setM0Speed(RF); // right front >0 is forward
}
