#include "Arduino.h"
#include <FastLED.h>
//#define NUM_LEDS 1
//#define DATA_PIN 12
#define CYCLE_DELAY 20
#define GND 12
#define LIGHT_SENSOR_PIN A5

int LED[3] = {9, 10, 11};

void initRGBLed(int led[3]) {
  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  pinMode(led[2], OUTPUT);
  pinMode(LIGHT_SENSOR_PIN, INPUT);
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
  Serial.begin(9600);
}

// the loop function runs over and over again forever
  // showAnalogRGB(LED, CRGB::Blue);
  // static uint8_t hue;
  // hue = hue + 1;
void loop() {
  // for (uint16_t i=0; i<255; i++) {
  //   showAnalogRGB(LED, CHSV(i, 255, 255));
  //   delay(CYCLE_DELAY);
  // }
  // digitalWrite(GND, LOW);
  int analog_value = analogRead(LIGHT_SENSOR_PIN);
  if (analog_value > 800) {
    analog_value = 1023;
  }
  int light_intensity = map(analog_value, 0, 1023, 255, 0);
  showAnalogRGB(LED, CHSV(200, 255, light_intensity));
  Serial.println(analog_value);

  delay(100);
}
