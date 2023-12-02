#include<Servo.h>

#define ESC_PIN1 2
#define ESC_PIN2 3
#define ESC_PIN3 4
#define ESC_PIN4 5
#define ESC_PIN5 6
#define ESC_PIN6 7


Servo esc1;
Servo esc2;
Servo esc3;
Servo esc4;
Servo esc5;
Servo esc6;

void setup() 
{
  Serial.begin(9600);
  esc1.attach(ESC_PIN1,  1000, 2000);
  esc1.write(0);
  esc2.attach(ESC_PIN2,  1000, 2000);
  esc2.write(0);
  esc3.attach(ESC_PIN3,  1000, 2000);
  esc3.write(0);
  esc4.attach(ESC_PIN4,  1000, 2000);
  esc4.write(0);
  esc5.attach(ESC_PIN5,  1000, 2000);
  esc5.write(0);
  esc6.attach(ESC_PIN6,  1000, 2000);
  esc6.write(0);
  delay(2000);
}

void loop() 
{
  int joystickValue1 = analogRead(A0);
  int joystickValue2 = analogRead(A1);
  int joystickValue3 = analogRead(A2);
  int joystickValue4 = analogRead(A3);
  int joystickValue5 = analogRead(A4);
  int joystickValue6 = analogRead(A5);
  joystickValue1 = constrain(joystickValue1, 0, 1023);  //Read upper half of joystick value from center.
  int mmotorSpeed1 = map(joystickValue1, 0, 1023, 0, 180);
  joystickValue2 = constrain(joystickValue2, 0, 1023);  //Read upper half of joystick value from center.
  int mmotorSpeed2 = map(joystickValue2, 0, 1023, 0, 180);

  joystickValue3 = constrain(joystickValue3, 0, 1023);  //Read upper half of joystick value from center.
  int mmotorSpeed3 = map(joystickValue3, 0, 1023, 0, 180);
  joystickValue4 = constrain(joystickValue4, 0, 1023);  //Read upper half of joystick value from center.
  int mmotorSpeed4 = map(joystickValue4, 0, 1023, 0, 180);

  joystickValue5 = constrain(joystickValue5, 0, 1023);  //Read upper half of joystick value from center.
  int mmotorSpeed5 = map(joystickValue5, 0, 1023, 0, 180);
  joystickValue6 = constrain(joystickValue6, 0, 1023);  //Read upper half of joystick value from center.
  int mmotorSpeed6 = map(joystickValue6, 0, 1023, 0, 180);
  esc1.write(mmotorSpeed1);  
  esc2.write(mmotorSpeed2);
  esc3.write(mmotorSpeed3);  
  esc4.write(mmotorSpeed4);
  esc5.write(mmotorSpeed5);  
  esc6.write(mmotorSpeed6);
  Serial.print(joystickValue1);
  Serial.print("  ");
  Serial.print(joystickValue2);
  Serial.print("  ");
  Serial.print(joystickValue3);
  Serial.print("  ");
  Serial.print(joystickValue4);
  Serial.print("  ");
  Serial.print(joystickValue5);
  Serial.print("  ");
  Serial.print(joystickValue6);
  Serial.print("  ");
  Serial.println();
}