#include "main.h"

// timer

#define MY_D1 5
#define MY_LED 2

Button button;

void setup2(void) {
    Serial.begin(115200);

    delay(300);
    Serial.println("bootup...\n");

    // put your setup code here, to run once:
    pinMode(MY_D1, INPUT);
    pinMode(MY_LED, OUTPUT);
}

void loop2() {
    bool isIdle = digitalRead(MY_D1);
    button.loop(!isIdle);
//    digitalWrite(MY_LED, is_led_on ? LOW : HIGH);
}