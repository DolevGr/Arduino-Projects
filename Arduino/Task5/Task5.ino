#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>

#define rxPin 4
#define txPin 5
#define PIN A0
#define NUM_PIXELS 12

#define Q1 11
#define Q2 10
#define Q3 9
#define Q4 8
#define STD 12

byte num;
int vTone, delayVal = 500,
  R = 0, G = 0, B = 0;
SoftwareSerial Bt(rxPin, txPin);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  Bt.begin(9600);
  Serial.begin(9600);
  pixels.begin();
  pixels.clear();
  pixels.show();
  
  pinMode(Q4, INPUT);
  pinMode(Q3, INPUT);
  pinMode(Q2, INPUT);
  pinMode(Q1, INPUT);
  pinMode(STD, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(STD)){
    vTone = digitalRead(Q4) * 8 + digitalRead(Q3) * 4
            + digitalRead(Q2) * 2 + digitalRead(Q1);
   Serial.print(vTone);
   while(digitalRead(STD));


   switch(vTone){
    case 1:
      R = 255; G = 255; B = 0;
      break;
      
   case 2:
      R = 135; G = 206; B = 235;
      break;
      
   case 3:
      R = 218; G = 112; B = 214;
      break;
      
   case 4:
      R = 255; G = 165; B = 0;
      break;
      
   default:
      R = 0; G = 0; B = 0;
  }

  for (int i = 0; i < NUM_PIXELS; i++){
    pixels.setPixelColor(i, R, G, B);
  }
  
  pixels.show();
  }
}
