#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise1;         //xy=341,203.5
AudioOutputAnalog        dac1;           //xy=491.5,208.5
AudioConnection          patchCord1(noise1, dac1);
// GUItool: end automatically generated code

  
int touchpin1 = 23;
int reading1 = 0;
int threshold = 1200;
bool pinState;
bool noteState;
unsigned long lastDebounce;
unsigned long debounceDelay = 20;
  

void setup() {
  Serial.begin(9600);

  AudioMemory(10);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH); // turn on the amplifier
  delay(10);             // allow time to wake up
  

}

void loop() {

  bool tripped = touchRead(touchpin1) > threshold;
  if (pinState != tripped) {
    lastDebounce = millis();
    pinState = tripped;
  }
  else if(noteState != pinState && (millis() - lastDebounce) > debounceDelay) {
    Serial.println(pinState);
    noise1.amplitude(pinState);
    noteState = pinState;
  }
  delay(10);
}
