#ifndef Button_H
#define Button_H

#include <functional>

class Button
{

    int lastStatus;
    int loopsCount;
    int loopsBeforeTrigger;
    std::function<void(void)> onTapHandler;
    std::function<void(void)> onDownHandler;
    std::function<void(void)> onUpHandler;

public:

    Button();
    void loop(bool);
    void onTap(std::function<void(void)>);
    void onDown(std::function<void(void)>);
    void onUp(std::function<void(void)>);
};

#endif
