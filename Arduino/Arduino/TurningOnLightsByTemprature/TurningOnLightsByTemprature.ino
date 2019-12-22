#include <Adafruit_NeoPixel.h>
#include <Wire.h>

#define LM75_addr 0x90>>1
#define PIN 6
#define NUMPIXELS 48

byte i, r, g, b;
float valtemp;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void configTemp(byte add){
 Wire.beginTransmission(add);
 Wire.write(0x0);
}

float readTemp(byte add){
  float temp;
  Wire.requestFrom(add,2);
  if(Wire.available()){
   temp = ((Wire.read() << 8 |Wire.read()) >> 5) * 0.125;
   return temp;
  }
}

void setup() {
  Wire.begin();
  configTemp(LM75_addr);
  
  Serial.begin(9600);
  pixels.begin();
  pixels.clear();
  pixels.show();
  
  r = 128; g = 0; b = 0;
}

void loop() {
  valtemp = readTemp(LM75_addr);
  Serial.print("Temperature: ");
  Serial.println(valtemp);

  if(valtemp < 22){
    r = 40; g = 0; b = 0;
  } else if(valtemp < 24){
    r = 80; g = 0; b = 0;
  } else if(valtemp < 26){
    r = 150; g = 0; b = 0;
  } else if(valtemp < 28){
    r = 200; g = 0; b = 0;
  } else{
    r = 255; g = 0; b = 0;
  }

  for(i = 0; i < NUMPIXELS; i++){
    pixels.setPixelColor(i, r, g, b);
  }
  pixels.show();
}
