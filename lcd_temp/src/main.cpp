#include "Arduino.h"
#include "LiquidCrystal.h"
#include "DHT.h"

#define DHTPIN 6     // what digital pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Serial.begin(9600);
  // Serial.println("DHTxx test!");
  dht.begin();
  lcd.begin(16, 2);
  lcd.print("init temp display..");
  delay(1000);
  lcd.clear();
}

void fillLines(String line_one, String line_two) {
  lcd.setCursor(0, 0);
  lcd.print(line_one);
  lcd.setCursor(0, 1);
  lcd.print(line_two);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(1700);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    fillLines("Failed to read", "from DHT sensor!");
    return;
  }

  // Compute heat index in Celsius (isFahreheit = false)
  float heat_index = dht.computeHeatIndex(temperature, humidity, false);
  fillLines(
    "Temp: " + String(heat_index, 2) + "C",
    "Humidity: " + String(humidity, 2) + "%"
  );
}