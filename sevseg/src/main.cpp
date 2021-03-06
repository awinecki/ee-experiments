/* SevSeg Counter Example
 
 Copyright 2017 Dean Reading
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 
 
 This example demonstrates a very simple use of the SevSeg library with a 4
 digit display. It displays a counter that counts up, showing deci-seconds.
 */

#include "Arduino.h"
#include "SevSeg.h"

SevSeg segleft;
SevSeg segright;

void setup() {
  byte numDigits = 1;
  byte digitPinsLeft[] = {12};
  byte digitPinsRight[] = {11};
  byte segmentPinsLeft[] = {2,3,4,5,6,7,8,9};
  byte segmentPinsRight[] = {32,33,34,35,36,37,38,39};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE;
  bool updateWithDelays = false;
  bool leadingZeros = false;

  segleft.begin(hardwareConfig, numDigits, digitPinsLeft, segmentPinsLeft,
      resistorsOnSegments, updateWithDelays, leadingZeros);
  segright.begin(hardwareConfig, numDigits, digitPinsRight, segmentPinsRight,
      resistorsOnSegments, updateWithDelays, leadingZeros);
  segleft.setBrightness(90);
  segright.setBrightness(90);
}

void numba(int num) {
  segleft.setNumber(num / 10);
  segright.setNumber(num % 10);
}

void loop() {
  static unsigned long timer = millis();
  static int deciSeconds = 0;

  if (millis() >= timer) {
    deciSeconds++; // 100 milliSeconds is equal to 1 deciSecond
    // timer += 100;
    timer += 75;
    if (deciSeconds == 100) { // Reset to 0 after counting for 1000 seconds.
      deciSeconds=0;
    }
    numba(deciSeconds);
  }
  //
  segleft.refreshDisplay(); // Must run repeatedly
  segright.refreshDisplay(); // Must run repeatedly
}

/// END ///
