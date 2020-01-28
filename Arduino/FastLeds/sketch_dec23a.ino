#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    41
CRGB leds[NUM_LEDS];
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
 
}
void loop() {
int counter = 0;
 while (counter < 4){
  for (int i = 0; i <= 40; i++) {
    leds[i] = CRGB (255,0,0);
    FastLED.show();
    delay(40);
  }
  
  for (int i = 40; i >= 0; i--) {
    leds[i] = CRGB (255,69,0);
    FastLED.show();
    delay(40);
  }
  
  for (int i = 0; i <= 40; i++) {
    leds[i] = CRGB (218,165,32);
    FastLED.show();
    delay(40);
  }
  
  for (int i = 40; i >= 0; i--) {
    leds[i] = CRGB (255,165,0);
    FastLED.show();
    delay(40);
  }
   for (int i = 0; i <= 40; i++) {
    leds[i] = CRGB (255,215,0);
    FastLED.show();
    delay(40);
  }
   for (int i = 40; i >= 0; i--) {
    leds[i] = CRGB (255,140,0);
    FastLED.show();
    delay(40);
  }
  counter ++; 
}

}
