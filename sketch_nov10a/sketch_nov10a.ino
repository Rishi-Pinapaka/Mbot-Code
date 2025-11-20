

#include <Arduino.h>
#include <MeMCore.h>


MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeRGBLed led(0,30); 

void moveForward(){
  led.setColor(0,255,0);
   led.show(); 
  motor1.run(100);
  motor2.run(-100);
  delay(4000);
}

void moveForward2(){
  led.setColor(0,255,0);
   led.show(); 
  motor1.run(100);
  motor2.run(-100);
  delay(3200);
 
}


void waitSeconds(){
  led.setColor(255,0,0);
  led.show();
  motor1.stop();
  motor2.stop();
  delay(3000);
}
  
void turnRight(){
  led.setColor(0,255,0);
   led.show();
  motor1.run(-95);
  motor2.run(-95);
  delay(560);
  
}

void turnLeft(){
  led.setColor(0,255,0);
  led.show();
  //motor1.run(120); change to 100
  //motor2.run(120); change to 100
  motor1.run(95); 
  motor2.run(95);
  delay(560);
}
void moveBackward(){
  led.setColor(0,255,0);
  led.show();
  motor1.run(-100); 
  motor2.run(100);
  delay(560);
}
void turn180(){
  led.setColor(0,255,0);
  led.show();
  motor1.run(200); 
  motor2.run(200);
  delay(560);
}
void setup() {
  // put your setup code here, to run once:
led.setpin(13);
     pinMode(A7,INPUT);



  moveForward();
  waitSeconds();
  turnRight();
  moveForward2();
  waitSeconds();
  turnLeft();
  moveForward();
  waitSeconds();
  moveBackward();
  turn180();
  motor1.stop();
  motor2.stop();
 
}


void loop() {
  // put your main code here, to run repeatedly:

}

