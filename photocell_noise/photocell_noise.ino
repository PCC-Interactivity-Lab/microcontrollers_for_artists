/* Photocell simple testing sketch. 
 
Connect one end of the photocell to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground 
Connect LED from pin 11 through a resistor to ground 
For more information see http://learn.adafruit.com/photocells */


#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

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

 
int photocellPin = 14;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider
int LEDpin = 13;          // connect Red LED to pin 11 (PWM pin)
int LEDbrightness;        // 
int filterFreq = 0;

void setup(void) {
  // We'll send debugging information via the Serial monitor
  AudioMemory(10);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH); // turn on the amplifier
  delay(10);             // allow time to wake up
  Serial.begin(9600);   
}
 
void loop(void) {
  photocellReading = analogRead(photocellPin);  
 
  Serial.print("Analog reading = ");
  Serial.println(photocellReading);     // the raw analog reading
  filterFreq = map(photocellReading, 300, 830, 20000, 0);
  pink1.amplitude(1);
  filter1.frequency(filterFreq);
  // LED gets brighter the darker it is at the sensor
  // that means we have to -invert- the reading from 0-1023 back to 1023-0
  photocellReading = 1023 - photocellReading;
  //now we have to map 0-1023 to 0-255 since thats the range analogWrite uses
  LEDbrightness = map(photocellReading, 0, 1023, 0, 255);
  analogWrite(LEDpin, LEDbrightness);
 
  delay(100);
}
