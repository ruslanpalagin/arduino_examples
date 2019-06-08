#include "main.h"

// timer

#define DIGITAL_INPUT 5
#define LED_NONE 0
#define LED_GREEN 4
#define LED_YELLOW 14
#define LED_RED 12

Button button;
int currentLed;

void setup2(void) {
    Serial.begin(115200);
    Serial.println("bootup...\n");

    pinMode(DIGITAL_INPUT, INPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_RED, OUTPUT);

    currentLed = LED_NONE;

    button.onTap([](void) -> void {
        Serial.println("onTap...\n");
        if (currentLed == LED_NONE) {
            currentLed = LED_GREEN;
            return;
        }
        if (currentLed == LED_GREEN) {
            currentLed = LED_YELLOW;
            return;
        }
        if (currentLed == LED_YELLOW) {
            currentLed = LED_RED;
            return;
        }
        if (currentLed == LED_RED) {
            currentLed = LED_NONE;
        }
    });
    button.onDown([](void) -> void { return; });
    button.onUp([](void) -> void { return; });
}

void loop2() {
    bool isPressed = !digitalRead(DIGITAL_INPUT);
    button.loop(isPressed);

    if (currentLed == LED_NONE) {
                  digitalWrite(LED_GREEN, LOW);
                  digitalWrite(LED_YELLOW, LOW);
                  digitalWrite(LED_RED, LOW);
                }
                if (currentLed == LED_GREEN) {
                  digitalWrite(LED_GREEN, HIGH);
                  digitalWrite(LED_YELLOW, LOW);
                  digitalWrite(LED_RED, LOW);
                }
                if (currentLed == LED_YELLOW) {
                  digitalWrite(LED_GREEN, LOW);
                  digitalWrite(LED_YELLOW, HIGH);
                  digitalWrite(LED_RED, LOW);
                }
                if (currentLed == LED_RED) {
                  digitalWrite(LED_GREEN, LOW);
                  digitalWrite(LED_YELLOW, LOW);
                  digitalWrite(LED_RED, HIGH);
                }
}

