#include <Arduino.h>
#include <MeMCore.h>

 MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeUltrasonicSensor ultraSonic(PORT_3);
void moveForward(){

  motor1.run(100);
  motor2.run(-100);

}
void turnLeft(){
  motor1.run(100); 
  motor2.run(100);

}
void turnRight(){
  
  motor1.run(-100);
  motor2.run(-100);
 
  }
void moveBackward(){
  motor1.run(-100); 
  motor2.run(100);
  
}
void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.print("Distance: ");
  Serial.print(ultraSonic.distanceCm());
  Serial.println(" cm");

  if (ultraSonic.distanceCm()<=6.7){
     turnLeft();
     delay(560);
  if(ultraSonic.distanceCm()<=6.7){
    turnRight();
    delay(1120);
  }
  if(ultraSonic.distanceCm()<=6.7){
    turnRight();
    delay(560);
  }
  if(ultraSonic.distanceCm()<=6.7){
    turnRight();
    delay(1680);
  }
}
else{
  moveForward();
}
}
