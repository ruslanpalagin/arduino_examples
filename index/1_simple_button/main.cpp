#include "main.h"

#define MY_D1 5
#define MY_LED 2

void setup2(void) {
  Serial.begin(115200);

      delay(300);
      Serial.println("bootup...\n");

    // put your setup code here, to run once:
    pinMode(MY_D1, INPUT);
    pinMode(MY_LED, OUTPUT);
}

void loop2() {
  bool val = digitalRead(MY_D1);
//  Serial.print(val);

  if (val) {
    digitalWrite(MY_LED, HIGH);
    } else {
      digitalWrite(MY_LED, LOW );
  }
}
