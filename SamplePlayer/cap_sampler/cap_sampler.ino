#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
  
  int touchpin1 = 23;
  int reading1 = 0;
  int threshold = 1400;
  bool pinState;
  bool noteState;
  unsigned long lastDebounce;
  unsigned long debounceDelay = 20;
  

void setup() {
  Serial.begin(9600);
}

void loop() {

  bool tripped = touchRead(touchpin1) > threshold;
  if (pinState != tripped) {
    lastDebounce = millis();
    pinState = tripped;
  }
  else if(noteState != pinState && (millis() - lastDebounce) > debounceDelay) {
    Serial.println(pinState);
    noteState = pinState;
  }
  delay(10);
//  Serial.println(touchRead(touchpin1));
}
