#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Button.h>        //https://github.com/JChristensen/Button

Button btn1(2, true, true, 50);    //Declare the button
Button btn2(3, true, true, 50);    //Declare the button
Button btn3(4, true, true, 50);    //Declare the button
Button btn4(5, true, true, 50);    //Declare the button

int track_cursor = 0;

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void printDetail(uint8_t type, int value);
// int currentSong = 1;

void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  Serial.println();
  Serial.println("DFRobot DFPlayer Mini Demo");
  Serial.println("Initializing DFPlayer ... (May take 3~5 seconds)");

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println("Unable to begin:");
    Serial.println("1.Please recheck the connection!");
    Serial.println("2.Please insert the SD card!");
    while(true);
  }
  Serial.println("DFPlayer Mini online.");

  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
  // myDFPlayer.playMp3Folder(currentSong);  //Play the first mp3
  // delay(2000);
  // myDFPlayer.playMp3Folder(2);  //Play the first mp3
}

void loop()
{
  // static unsigned long timer = millis();

  btn1.read();
  btn2.read();
  btn3.read();
  btn4.read();
  if (btn1.wasPressed()) {
    Serial.println("PRESSED 1");
    myDFPlayer.playMp3Folder(track_cursor + 1);
  }
  if (btn2.wasPressed()) {
    Serial.println("PRESSED 2");
    myDFPlayer.playMp3Folder(track_cursor + 2);
  }
  if (btn3.wasPressed()) {
    Serial.println("PRESSED 3");
    myDFPlayer.playMp3Folder(track_cursor + 3);
  }
  if (btn4.wasPressed()) {
    Serial.println("PRESSED 4");
    // myDFPlayer.playMp3Folder(4);
    track_cursor += 3;
    if (track_cursor > 20) {
      track_cursor = 0;
    }
  }

  // if (millis() - timer > 10000) {
  //   timer = millis();
  //   // myDFPlayer.next();  //Play next mp3 every 3 second.
  //   currentSong++;
  //   if (currentSong > 4) {
  //     currentSong = 1;
  //   }
  //   myDFPlayer.playMp3Folder(currentSong);  //Play the first mp3
  // }

  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read());
  }
}

void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println("Time Out!");
      break;
    case WrongStack:
      Serial.println("Stack Wrong!");
      break;
    case DFPlayerCardInserted:
      Serial.println("Card Inserted!");
      break;
    case DFPlayerCardRemoved:
      Serial.println("Card Removed!");
      break;
    case DFPlayerCardOnline:
      Serial.println("Card Online!");
      break;
    case DFPlayerPlayFinished:
      Serial.print("Number:");
      Serial.print(value);
      Serial.println(" Play Finished!");
      break;
    case DFPlayerError:
      Serial.print("DFPlayerError:");
      switch (value) {
        case Busy:
          Serial.println("Card not found");
          break;
        case Sleeping:
          Serial.println("Sleeping");
          break;
        case SerialWrongStack:
          Serial.println("Get Wrong Stack");
          break;
        case CheckSumNotMatch:
          Serial.println("Check Sum Not Match");
          break;
        case FileIndexOut:
          Serial.println("File Index Out of Bound");
          break;
        case FileMismatch:
          Serial.println("Cannot Find File");
          break;
        case Advertise:
          Serial.println("In Advertise");
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }

}
