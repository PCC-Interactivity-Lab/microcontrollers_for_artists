#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoisePink     pink1;         //xy=341,203.5
AudioOutputAnalog       dac1;           //xy=491.5,208.5
AudioConnection         patchCord1(pink1, dac1);
// GUItool: end automatically generated code


void setup() {
  AudioMemory(10);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH); // turn on the amplifier
  delay(10);             // allow time to wake up
}

void loop() {
  // put your main code here, to run repeatedly:
  pink1.amplitude(1);
}
