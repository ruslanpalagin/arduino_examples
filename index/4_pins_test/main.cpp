#include "main.h"

#define MY_LED 2

void setup2(void) {
  Serial.begin(115200);

    pinMode(MY_LED, OUTPUT);

//    pinMode(1, INPUT); // NO BOOTUP
//    pinMode(3, INPUT); // -> RX - inversed
//    pinMode(4, INPUT); // perfect
//    pinMode(5, INPUT); // perfect
//    pinMode(6, INPUT); // NO BOOTUP
//    pinMode(7, INPUT); // NO BOOTUP
//    pinMode(8, INPUT); // NO BOOTUP
//    pinMode(9, INPUT); // NONE responding, some rebooting
//    pinMode(10, INPUT); // NONE responding, some rebooting
//    pinMode(11, INPUT);
//    pinMode(12, INPUT); // perfect
//    pinMode(13, INPUT);
//    pinMode(14, INPUT); // perfect
//    pinMode(15, INPUT);

    pinMode(4, OUTPUT); // perfect
    pinMode(5, OUTPUT); // perfect
    pinMode(12, OUTPUT); // perfect
    pinMode(14, OUTPUT); // perfect
      delay(300);
      Serial.println("bootup...\n");
}

void loop2() {
//  testIn(12);
  delay(500);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(14, HIGH);
}

void testIn(int i) {
        Serial.print("test");
        Serial.print(i);
        Serial.print(":");
        Serial.println(digitalRead(i));
}