#include <FastLED.h>

const bool _ = false;
const bool X = true;
const int buttonpin = 39;
const int ledpin = 27;
const int numleds = 25;
int hue = 0;

CRGB leds[numleds];

const bool faces[] = {
  _,_,_,  _,_,X,  X,_,_,  X,_,X,  X,_,X,  X,_,X,
  _,X,_,  _,_,_,  _,X,_,  _,_,_,  _,X,_,  X,_,X,
  _,_,_,  X,_,_,  _,_,X,  X,_,X,  X,_,X,  X,_,X,
};

void setup() {
    pinMode(buttonpin, INPUT);

    FastLED.addLeds < WS2812B, ledpin, GRB > (leds, numleds);
    FastLED.setBrightness(20);

    FastLED.showColor(CRGB::Blue);
    delay(500);
    FastLED.showColor(CRGB::Black);
}

void loop() {
    for (int i = 0; i < 10; i++) {
        int n = random(0, 5);

        for (int i = 0; i < numleds; i++) leds[i] = CRGB::Black;

        CRGB color = CHSV(hue, 255, 255);
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                if (faces[y*18 + n*3 + x]) leds[ (y+1)*5 + x+1 ] = color;
            }
        }
        FastLED.show();
        delay(100);

        hue += 3;
    }

    while (digitalRead(buttonpin));
}
