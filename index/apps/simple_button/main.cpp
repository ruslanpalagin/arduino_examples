#include "main.h"

#define MY_D1 5
#define MY_LED 2

void main2(void) {
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

// LED https://www.google.com/search?biw=1920&bih=983&tbm=isch&sa=1&ei=uWTxXK-_Lv2Fk74Pzo6DmAI&q=esp12+LED&oq=esp12+LED&gs_l=img.3...679614.681207..681701...0.0..0.89.466.6......0....1..gws-wiz-img.......0j0i30.qljBr5olMnE#imgrc=trIPBCu6ZQX2CM:
// PINS http://grobotronics.com/images/companies/1/datasheets/NodeMcu-ESP8266-12-2.jpg?1518180803402