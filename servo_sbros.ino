#include <iarduino_MultiServo.h>  //  Подключаем библиотеку iarduino_MultiServo
iarduino_MultiServo MSS;
void setup();
void loop();
void setup() {
  MSS.servoSet(SERVO_ALL, SERVO_MG996R);
  MSS.begin();
  Serial.begin(9600);
  Serial.println("RF receiver button decode");
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(13, INPUT);
  MSS.servoWrite(SERVO_ALL, 2);
}

void loop() {
  if (digitalRead(6) == HIGH && digitalRead(13) == HIGH) {
    MSS.servoWrite(0, 2);
  }
  if (digitalRead(6) == HIGH && digitalRead(13) == LOW) {
    MSS.servoWrite(0, 36);
  }

  if (digitalRead(7) == HIGH && digitalRead(13) == HIGH) {
    MSS.servoWrite(1, 2);
    MSS.servoWrite(2, 2);
  }
  if (digitalRead(7) == HIGH && digitalRead(13) == LOW) {
    MSS.servoWrite(1, 36);
    MSS.servoWrite(2, 36);
  }

  if (digitalRead(4) == HIGH && digitalRead(13) == HIGH) {
    MSS.servoWrite(3, 2);
    MSS.servoWrite(4, 2);
  }
  if (digitalRead(4) == HIGH && digitalRead(13) == LOW) {
    MSS.servoWrite(3, 36);
    MSS.servoWrite(4, 36);
  }

  if (digitalRead(5) == HIGH) {
    MSS.servoWrite(SERVO_ALL, 2);
  }
}
