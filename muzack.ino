#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
char val; // Data received from the serial port
uint8_t counter = 0;
int lastBright = 0;

void setup() {
  Serial.begin(9600);  
  matrix.begin(0x70);  // pass in the address
  matrix.clear();
  matrix.fillRect(0, 0, 8, 8, LED_RED);
  matrix.writeDisplay();
  matrix.setBrightness(1);
}

void loop() {
  if (Serial.available()) {
    val = Serial.read();
    if (val == 0){
      matrix.setBrightness(2);
    } else if (val == 1) {
      matrix.setBrightness(3);
    } else if (val == 2) {
      matrix.setBrightness(4);
    } else if (val == 3) {
      matrix.setBrightness(5); 
    } else if (val == 4) {
      matrix.setBrightness(6);    
    } else if (val == 5){
      matrix.setBrightness(7);
    } else if (val == 6) {
      matrix.setBrightness(8);
    } else if (val == 7) {
      matrix.setBrightness(9);
    } else if (val == 8) {
      matrix.setBrightness(10);
    } else if (val == 9) {
      matrix.setBrightness(11);
    } else if (val == 10) {
      matrix.setBrightness(12);
    } else if (val == 11) {
      matrix.setBrightness(13);
    } else if (val == 12) {
      matrix.setBrightness(14);
    } else if (val >= 13) {
      matrix.setBrightness(15);
    } 
    Serial.println(val);
  } 
}
