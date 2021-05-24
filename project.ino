#include <SoftwareSerial.h>
#include <AFMotor.h>
#include<Servo.h>

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

SoftwareSerial bluetooth(13, 2);
String t;
char sp = 180;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);



  // set the data rate for the SoftwareSerial port
  bluetooth.begin(9600);

}

void loop() { // run over and over
  if (bluetooth.available()) {
    t = bluetooth.readString();
    Serial.println(t);
  }
  if (t == "forward") {          //move forward(all motors rotate in forward direction)
    Serial.println("Forward");
    motor1.setSpeed(sp);
    motor1.run(FORWARD);
    motor2.setSpeed(sp);
    motor2.run(FORWARD);
    motor3.setSpeed(sp);
    motor3.run(FORWARD);
    motor4.setSpeed(sp);
    motor4.run(FORWARD);
  }

  else if (t == "backward") {    //move reverse (all motors rotate in reverse direction)
    Serial.println("Reverse");
    motor1.setSpeed(sp);
    motor1.run(BACKWARD);
    motor2.setSpeed(sp);
    motor2.run(BACKWARD);
    motor3.setSpeed(sp);
    motor3.run(BACKWARD);
    motor4.setSpeed(sp);
    motor4.run(BACKWARD);
  }

  else if (t == "left") {    //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
    Serial.println("Left");
    motor1.run(BACKWARD);
    motor1.setSpeed(sp);
    motor2.run(BACKWARD);
    motor2.setSpeed(sp);
    motor3.run(FORWARD);
    motor3.setSpeed(sp);
    motor4.run(FORWARD);
    motor4.setSpeed(sp);
    delay(2000);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    t="";
  }

  else if (t == "right") {    //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
    Serial.println("Right");
    motor1.run(FORWARD);
    motor1.setSpeed(sp);
    motor2.run(FORWARD);
    motor2.setSpeed(sp);
    motor3.run(BACKWARD);
    motor3.setSpeed(sp);
    motor4.run(BACKWARD);
    motor4.setSpeed(sp);
    delay(2000);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    t="";
  }


  else if (t == "stop") {    //STOP (all motors stop)
    Serial.println("Stop");
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }
  delay(100);
}

\
