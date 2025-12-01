#include <Arduino.h>
#include <MeMCore.h>

 MeDCMotor motor1(M1);
MeDCMotor motor2(M2);

MeLineFollower lineFinder(PORT_2);
void moveForward(){

  motor1.run(70);
  motor2.run(-70);

}
void turnLeft(){
  motor1.run(70); 
  motor2.run(70);

}
void turnRight(){
  
  motor1.run(-70);
  motor2.run(-70);
  
}
void moveBackward(){
  motor1.run(-70); 
  motor2.run(70);
  
}
void setup()

{

  Serial.begin(9600);

}

 

void loop()

{

   if (lineFinder.readSensor1()==0 && lineFinder.readSensor2()==0)

    {

      Serial.println("Sensor 1 on black and Sensor2 on black");
moveForward();
delay(100);
    }

  else if (lineFinder.readSensor1()==1 && lineFinder.readSensor2()==0)

   {

     Serial.println("Sensor 1 on white and Sensor 2 on black");
turnRight();
delay(100);
motor1.stop();
motor2.stop();
    }

  else if (lineFinder.readSensor1()==0 && lineFinder.readSensor2()==1)

    {

    Serial.println("Sensor 1 on Black and Sensor 2 on White");
turnLeft();
delay(100);
motor1.stop();
motor2.stop();
    }

  else //(lineFinder.readSensor1()==1 && lineFinder.readSensor2()==1)

    {

    Serial.println("Sensor 1 on White and Sensor 2 on White");
moveBackward();
delay(100);
motor1.stop();
motor2.stop();
    }


}

 