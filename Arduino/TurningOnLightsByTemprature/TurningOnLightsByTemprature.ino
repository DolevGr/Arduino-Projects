x#include <Adafruit_NeoPixel.h>
#include <lm75.h>
#include <math.h>

#define PIN A0
#define NUMPIXELS 48
#define ANALOGPIN A1

int value, firstValue, def, nextCounter;
byte i,n, r, g, b;
bool isFirstEntry;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels.clear();
  pixels.show();
  
  isFirstEntry = true;
  firstValue = analogRead(ANALOGPIN);
  value = n = 0;
  nextCounter = 1;
  def = 15;
  r = 128; g = 0; b = 0;
}

void loop() {
  value = analogRead(ANALOGPIN);

  if(fabs(value - firstValue) > def && nextCounter < NUMPIXELS){
    while(fabs(value - firstValue) > def){
      value = analogRead(ANALOGPIN);
      for(i = 0; i < 12 && isFirstEntry; i++){
        pixels.setPixelColor(i+n, r, g, b);
        //delay(100);
      }
      pixels.show();
      isFirstEntry = false;
    }
    Serial.println(nextCounter);
    nextCounter++;
    r += 128; r %= 256;
    g += 128; g %= 256;
    b += 60; b %= 256;
    n += 12;
   isFirstEntry = true;
  }
}
