#include "Arduino.h"
#include <ST_HW_HC_SR04.h>
#include <FastLED.h>
#define CYCLE_DELAY 20
#define TRIG 6
#define ECHO 5

bool spotted = true;

ST_HW_HC_SR04 ultrasonicSensor(TRIG, ECHO);
int LED[3] = {9, 10, 11};

void initRGBLed(int led[3]) {
  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  pinMode(led[2], OUTPUT);
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
  // Serial.begin(9600);
}

void loop() {
  // for (uint16_t i=0; i<255; i++) {
  //   showAnalogRGB(LED, CHSV(i, 255, 255));
  //   delay(CYCLE_DELAY);
  // }
  // digitalWrite(GND, LOW);

  int hitTime = ultrasonicSensor.getHitTime();
  int distanceInCm = hitTime / 58;
  int intensity = map(distanceInCm, 0, 33, 255, 0);
  if (intensity == 255) {
    intensity = 0;
  }
  if (spotted) {
    showAnalogRGB(LED, CHSV(200, 255, intensity));
  } else {
    showAnalogRGB(LED, CHSV(0, 0, 0));
  }
  // Serial.println(distanceInCm);
  // Serial.println(intensity);

  delay(30);
}

