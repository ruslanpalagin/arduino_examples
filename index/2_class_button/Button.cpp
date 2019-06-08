#include "Button.h"
#include "Arduino.h"

Button::Button()
{
    lastStatus = 0;
    loopsCount = 0;
    loopsBeforeTrigger = 5000;
}

void Button::loop(bool isPressed)
{
    if (lastStatus == isPressed) {
        return;
    }
    loopsCount++;
    if (loopsCount >= loopsBeforeTrigger) {
        Serial.println("Pushed!...\n");
        lastStatus = isPressed;
        loopsCount = 0;
    }
};
