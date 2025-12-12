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
  motor1.run(90); 
  motor2.run(90);

}
void turnRight(){
  
  motor1.run(-90);
  motor2.run(-90);
 
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
 
  if (ultraSonic.distanceCm()<=12){
     turnRight();
     delay(620);
 
     if(ultraSonic.distanceCm()<=12){
      turnLeft();
      delay(1240);
      
      }
  }
  else{
    moveForward();
    delay(500);
     
  }
}
