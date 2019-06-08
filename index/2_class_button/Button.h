#ifndef Button_H
#define Button_H

class Button
{
    int lastStatus;
    int loopsCount;
    int loopsBeforeTrigger;

public:

    Button();
    void loop(bool);
};

#endif
