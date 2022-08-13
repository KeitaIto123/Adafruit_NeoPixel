// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 60 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// ここから下4行の数字を設定してね
#define DURATION 30 // 光る間隔
#define RED 200      // 赤の明るさ (0-255)
#define GREEN 40    // 緑の明るさ (0-255)
#define BLUE 40     // 青の明るさ (0-255)

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'

  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // ここで光らせるLEDとその色と明るさの設定をしている
    /// pixels.setPixelColor(<光らせるLEDの番号(0-59番)>, pixels.Color(<赤の要素の明るさ>, <緑の要素の明るさ>, <青の要素の明るさ>));
    //// 明るさの範囲は0-255まで
    pixels.setPixelColor(i, pixels.Color(RED, GREEN, BLUE));
     // ここで設定した光らせ方で光らせるぞって命令している
     pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DURATION);
    // pixels.setBrightness(10);
  }
}
