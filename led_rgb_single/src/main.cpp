#include "Arduino.h"
#include <FastLED.h>
//#define NUM_LEDS 1
//#define DATA_PIN 12
#define CYCLE_DELAY 50
#define GND 12

int LED[3] = {9, 10, 11};

void initRGBLed(int led[3]) {
  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  pinMode(led[2], OUTPUT);
  pinMode(GND, OUTPUT);
}

void showAnalogRGB(int led[3], const CRGB& rgb)
{
  analogWrite(led[0], rgb.r);
  analogWrite(led[1], rgb.g);
  analogWrite(led[2], rgb.b);
}

void setup() {
  initRGBLed(LED);
  showAnalogRGB(LED, CRGB::Red );   delay(100);
  showAnalogRGB(LED, CRGB::Green );   delay(100);
  showAnalogRGB(LED, CRGB::Blue );   delay(100);
  showAnalogRGB(LED, CRGB::Black );   delay(100);
}

// the loop function runs over and over again forever
  // showAnalogRGB(LED, CRGB::Blue);
  // static uint8_t hue;
  // hue = hue + 1;
void loop() {
  for (uint16_t i=0; i<255; i++) {
    showAnalogRGB(LED, CHSV(i, 255, 255));
    delay(CYCLE_DELAY);
  }
  digitalWrite(GND, LOW);
  delay(100);
}
