// CPX interactive example (works with readCap + no showPixels)
// Input 1: touch pad A1 -> play a sound
// Input 2: light sensor -> change NeoPixel color based on brightness

#include <Adafruit_CircuitPlayground.h>

void setup() {
  // Initialize Circuit Playground Express
  CircuitPlayground.begin();
}

void loop() {
  handleTouch();   // check touch input and play sound
  handleLight();   // check light sensor and control LEDs
  delay(50);
}

// Check capacitive touch on pad A1 and play a tone if touched
void handleTouch() {
  // readCap(1) reads capacitive value from pad A1
  uint16_t touchValue = CircuitPlayground.readCap(1);

  // adjust this threshold if it doesn't detect touch well
  if (touchValue > 500) {
    CircuitPlayground.playTone(440, 200);   // play 440 Hz for 200 ms
  }
}

// Read light sensor and turn LEDs on/off
void handleLight() {
  int lightValue = CircuitPlayground.lightSensor();  // 0~1023

  if (lightValue < 80) {
    // dark -> turn all pixels purple
    setAllPixels(150, 0, 150);
  } else {
    // bright -> turn off all pixels
    CircuitPlayground.clearPixels();
  }
}

// Set all 10 NeoPixels to the same RGB color
void setAllPixels(uint8_t r, uint8_t g, uint8_t b) {
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, r, g, b);
  }
  // no showPixels() needed in this library version
}
