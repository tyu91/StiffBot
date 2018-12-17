#include <Servo.h>

Servo myServo;
int input = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach (3);
  Serial.begin(9600);
}

/*ANNOTATIONS:
 * 0 is clockwise
 * 180 is counter clockwise
 * 90 is 0
 */

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    input = Serial.parseInt();
    myServo.write(writeScaled(input));
    Serial.println(input);
    delay (1000);
  } else {
  myServo.write(writeScaled(input));
  delay(1000);
  }
}

//takes in servo value from -100 to 100 and maps to 0 to 180
int writeScaled (int servoValue){
  return map(servoValue, -100, 100, 0, 180);
}

