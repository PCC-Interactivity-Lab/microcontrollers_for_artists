#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

int myNotes[5] = {261, 344, 777, 222, 153};

int myTimer;
int note;


// GUItool: begin automatically generated code
AudioSynthWaveformPWM    pwm1;           //xy=252,316
AudioMixer4              mixer1;         //xy=449,357
AudioOutputAnalog        dac1;           //xy=655,371
AudioConnection          patchCord1(pwm1, 0, mixer1, 0);
AudioConnection          patchCord2(mixer1, dac1);
// GUItool: end automatically generated code



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  AudioMemory(10);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH); // turn on the amplifier
  delay(10);             // allow time to wake up
  mixer1.gain(0, 1);

}

void loop() {
  // put your main code here, to run repeatedly:
  note = note%5;
  myTimer = myTimer%10;
  if(myTimer == 0){
      note++;
      pwm1.amplitude(0.1);
      pwm1.frequency(myNotes[note]); 
  }
delay(10);
myTimer++;
}
