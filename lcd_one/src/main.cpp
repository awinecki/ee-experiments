#include "Arduino.h"
#include "LiquidCrystal.h"

/*
  LiquidCrystal Library - Hello World
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 *
 */

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("initializing..");
  delay(2000);
  lcd.clear();
}

int pos = 0;
int text_delay = 2500;
int counter = 10;
String star_wars = "It is a period of civil war. Rebel spaceships, striking from a hidden base, have won their first victory against the evil Galactic Empire. During the battle, Rebel spies managed to steal secret plans to the Empire's ultimate weapon, the DEATH STAR, an armored space station with enough power to destroy an entire planet. Pursued by the Empire's sinister agents, Princess Leia races home aboard her starship, custodian of the stolen plans that can save her people and restore freedom to the galaxy....";

void fillLines(String line_one, String line_two) {
  lcd.setCursor(0, 0);
  lcd.print(line_one);
  lcd.setCursor(0, 1);
  lcd.print(line_two);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // pos += 1;
  // if (pos > 16) pos = 0;
  // lcd.clear();
  // lcd.setCursor(pos, 0);
  // lcd.print("SWAG");
  // delay(500);
  // lcd.scrollDisplayRight();
  //
  //
  lcd.clear();

  // if (counter > 0) {
  //   lcd.print(String(counter, DEC));
  //   counter -= 1;
  //   delay(400);
  // } else {
  //   lcd.print("> niekoniecznie");
  //   // lcd.setCursor(0, 1);
  //   // lcd.print("^__^");
  //   delay(2000);
  // }

  fillLines("A long time ago ", "in a galaxy far,");
  delay(text_delay);

  lcd.clear();
  fillLines(" far away....", "");
  delay(text_delay);

  lcd.clear();
  for (uint16_t i=0; i < 500; i += 32) {
    lcd.clear();
    fillLines(
        star_wars.substring(i, i + 16),
        star_wars.substring(i + 16, i + 32));
    delay(text_delay);
  }

  // print the number of seconds since reset:
  // lcd.print(millis() / 1000);
}

