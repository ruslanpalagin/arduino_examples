#include "Button.h"

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
        if (isPressed) {
            onTapHandler();
        }

        lastStatus = isPressed;
        loopsCount = 0;
    }
};

void Button::onTap(std::function<void(void)> onTapHandler_)
{
    onTapHandler = onTapHandler_;
};

void Button::onDown(std::function<void(void)> onDownHandler_)
{
    onDownHandler = onDownHandler_;
};

void Button::onUp(std::function<void(void)> onUpHandler_)
{
    onUpHandler = onUpHandler_;
};
