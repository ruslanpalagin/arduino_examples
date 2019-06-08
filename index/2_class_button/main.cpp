#include "main.h"

// timer

#define MY_D1 5
#define MY_LED 2

bool isLedOn;
Button button;

void setup2(void) {
    Serial.begin(115200);

    delay(300);
    Serial.println("bootup...\n");

    // put your setup code here, to run once:
    pinMode(MY_D1, INPUT);
    pinMode(MY_LED, OUTPUT);

    isLedOn = false;
    button.onTap([](void) -> void { isLedOn = !isLedOn; });
    button.onDown([](void) -> void { return; });
    button.onUp([](void) -> void { return; });
}

void loop2() {
    bool isPressed = !digitalRead(MY_D1);
    button.loop(isPressed);
    digitalWrite(MY_LED, isLedOn ? LOW : HIGH);
}
