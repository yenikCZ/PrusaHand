#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
int button = 5;
int pressed = 0;
int emg = 6;
int flexed = 0;
boolean toggle = true;

void setup() {
  // put your setup code here, to run once:

  servo1.attach(10);
  servo2.attach(9);
  servo3.attach(11);

  pinMode(button, INPUT_PULLUP);
  pinMode(flexed, INPUT);

  digitalWrite(button, HIGH);
  
  servo1.write(90);
  servo2.write(0);
  servo3.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:

  pressed = digitalRead(button);
  flexed = digitalRead(emg);

  if (pressed == LOW)
  //if (pressed == LOW || flexed == HIGH)
  {
    if (toggle)
    {
      servo1.write(90);
      servo2.write(0);
      servo3.write(90);
      toggle = !toggle;
      delay(750);
    }
    else
    {
      servo1.write(0);
      servo2.write(45);
      servo3.write(0);
      toggle = !toggle;
      delay(750);
    }
  }
  delay(10);
}
