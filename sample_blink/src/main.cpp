/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void blink(uint8_t times, uint8_t high_duration, uint8_t low_duration)
{
  for (int i=0; i<times; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(high_duration);
    digitalWrite(LED_BUILTIN, LOW);
    delay(low_duration);
  }
}

void loop()
{
  blink(3, 500, 100);
  delay(2500);
}
