#include "main.h"

// timer

#define MY_D1 5
#define MY_LED 2

#define MODE_IDLE 0
#define MODE_PUSHED 1
#define MODE_TRIGGER 100000

int current_mode;
int current_mode_ticks_count;

void setup2(void) {
    Serial.begin(115200);

    delay(300);
    Serial.println("bootup...\n");

    // put your setup code here, to run once:
    pinMode(MY_D1, INPUT);
    pinMode(MY_LED, OUTPUT);

    current_mode_ticks_count = 0;
    current_mode = MODE_IDLE;
}

void loop2() {
    bool isIdle = digitalRead(MY_D1);
    if (isIdle) {
      digitalWrite(MY_LED, HIGH);
      checkAndSetMode(MODE_PUSHED, MODE_IDLE);
    } else {
      digitalWrite(MY_LED, LOW );
      checkAndSetMode(MODE_IDLE, MODE_PUSHED);
    }
}

void checkAndSetMode(int prevModeExpectation, int newMode) {
    if (current_mode == prevModeExpectation) {
              current_mode_ticks_count++;
              if (current_mode_ticks_count >= MODE_TRIGGER) {
                  setMode(newMode);
              }
          }
}

void setMode(int newMode) {
    Serial.println("setMode");
    Serial.println(newMode);
    current_mode_ticks_count = 0;
    current_mode = newMode;
    if (newMode == MODE_PUSHED) {
      onKeyPress();
    }
}

void onKeyUp() {
    Serial.println("onKeyUp!!!!");
}

void onKeyDown() {
    Serial.println("onKeyDown!!!!");
}

void onKeyPress() {
    Serial.println("onKeyPress!!!!");
}

// LED https://www.google.com/search?biw=1920&bih=983&tbm=isch&sa=1&ei=uWTxXK-_Lv2Fk74Pzo6DmAI&q=esp12+LED&oq=esp12+LED&gs_l=img.3...679614.681207..681701...0.0..0.89.466.6......0....1..gws-wiz-img.......0j0i30.qljBr5olMnE#imgrc=trIPBCu6ZQX2CM:
// PINS http://grobotronics.com/images/companies/1/datasheets/NodeMcu-ESP8266-12-2.jpg?1518180803402