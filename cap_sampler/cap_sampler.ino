#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "AudioSampleGong.h"         // http://www.freesound.org/people/juskiddink/sounds/86773/
  
  int touchpin1 = 23;
  int reading1 = 0;
  int threshold = 1400;
  bool pinState;
  bool noteState;
  unsigned long lastDebounce;
  unsigned long debounceDelay = 20;

// GUItool: begin automatically generated code
AudioPlayMemory          playMem1;       //xy=109.14285278320312,136.71428298950195
AudioSynthNoisePink      pink1;          //xy=124.00001907348633,246.5000343322754
AudioFilterStateVariable filter1;        //xy=278.1111259460449,190.22221565246582
AudioMixer4              mixer1;         //xy=402.36510848999023,140.93650245666504
AudioOutputAnalog        dac1;           //xy=516.222225189209,201.1111307144165
AudioConnection          patchCord1(playMem1, 0, mixer1, 0);
AudioConnection          patchCord2(pink1, 0, filter1, 0);
AudioConnection          patchCord3(filter1, 0, mixer1, 1);
AudioConnection          patchCord4(mixer1, dac1);
// GUItool: end automatically generated code

  

void setup() {
  Serial.begin(9600);
  AudioMemory(10);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH); // turn on the amplifier
  delay(10);             // allow time to wake up
  mixer1.gain(0, 1);
  mixer1.gain(1, 1);
}

void loop() {

  bool tripped = touchRead(touchpin1) > threshold;
  if (pinState != tripped) {
    lastDebounce = millis();
    pinState = tripped;
  }
  else if(noteState != pinState && (millis() - lastDebounce) > debounceDelay) {
    Serial.println(pinState);
    if (pinState == 1){
      playMem1.play(AudioSampleGong);
    }
     noteState = pinState;
  }
  delay(10);
//  Serial.println(touchRead(touchpin1));
}
