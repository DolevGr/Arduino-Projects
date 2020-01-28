 #include <Adafruit_NeoPixel.h>
 #include<Wire.h> 
 
 // Angular velocity 
 #define MPU_addr  0x68 // I2C address of the MPU-6050
 int GyZ;
//pixel
 #define PIN A0
 #define NUMPIXELS 48
 #define ANALOGPIN A1
 Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
 
 void setup(){ 
  Wire.begin();
  configGyro();
  Serial.begin(9600);
  pixels.begin();
  pixels.clear();
  pixels.show();
  } 
 byte i;
void loop(){ 
  GyZ = readGyro(); 
  if(GyZ > 20){     //left
    for(i = 36; i<48; i++){
      pixels.setPixelColor(i,255,165,0); }
    delay(30);
    for(i = 36; i<48; i++){
      pixels.setPixelColor(i,0,0,0); }
    delay(50);

    for(i = 24; i < 36; i++){
      pixels.setPixelColor(i,128,0,128); 
      }
    delay(30);
     for(i = 24; i<36; i++){
      pixels.setPixelColor(i,0,0,0); 
      }
    delay(50);

    for(i = 12; i<24; i++){
      pixels.setPixelColor(i,0,255,0); }
    delay(30);
    for(i = 12; i<24; i++){
      pixels.setPixelColor(i,0,0,0); }
    delay(50);
    
    for(i = 0; i<12; i++){
      pixels.setPixelColor(i,0,255,255); }
    delay(30);
    for(i = 0; i<12; i++){
      pixels.setPixelColor(i,0,0,0); }
    delay(50);
    
   pixels.show();
   }
  
  else if(GyZ<(-20)){    //right
    for(i = 0; i<12; i++){
      pixels.setPixelColor(i,255,165,0); }
    delay(30);
    for(i = 0; i<12; i++){
      pixels.setPixelColor(i,0,0,0); }
    delay(50);
    
    for(i = 12; i<24; i++){
      pixels.setPixelColor(i,128,0,128); }
    delay(30);
    for(i = 12; i<24; i++){
      pixels.setPixelColor(i,0,0,0); }
    delay(50);
    
    for(i = 24; i<36; i++){
      pixels.setPixelColor(i,0,128,0); 
      }
    delay(30);
     for(i = 24; i<36; i++){
      pixels.setPixelColor(i,0,0,0); 
      }
    delay(50);
    
    for(i = 36; i<48; i++){
      pixels.setPixelColor(i,0,255,255); }
    delay(30);
    for(i = 36; i<48; i++){
      pixels.setPixelColor(i,0,0,0); }
    delay(50);
   
   pixels.show();
   }
   }
