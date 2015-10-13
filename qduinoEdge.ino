#include "Qduino.h"
#include "Wire.h"
#include <Adafruit_NeoPixel.h>
// *** SLEEP CODE

#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/interrupt.h>
#define BODS 7                   //BOD Sleep bit in MCUCR
#define BODSE 2                  //BOD Sleep enable bit in MCUCR
uint8_t mcucr1, mcucr2;

// Hardware parameters //

const int neoPin = 6;
const int buttonPin = 2;
const int numLeds = 9;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, neoPin, NEO_GRB + NEO_KHZ800);
qduino q;
fuelGauge battery;

const long holdClickTime = 1000;    // time between double-clicks, otherwise goes to sleep

// When all lights solid, actually dimmed to reduce strain on the battery.
const byte solidBrightness = 255;
const byte fashionBrightness = 64;
const byte safetyBrightness = 192;

// Flashing timing
int frameStep = 0;          // frame counter for flashing modes
const int transitionRate = 3;    // fade time transitioning between modes

// Interface memorizing
boolean buttonState = LOW;

// Things to remember
int state = -1;      // What state of the programme are we in?
int pressed = 0;
long firstPressedTime;    // how long ago was the button pressed?
uint32_t currentLEDvalue[numLeds];
int sleepCycled=0;

void setup() {
    // disable ADC, cut power consumption
    ADCSRA = 0;
    strip.begin();
    q.setup();
    q.ledOff();
    battery.setup();
    battery.goToSleep();

    //  Define pins
    pinMode(buttonPin, INPUT_PULLUP);
    startupFlash();    // flash to show that the programme's started
    goToSleep();    // sshhhh... there there...
}

long lastDebounceTime = 0;
boolean lastButtonState = HIGH;

void loop() {
    // Button debounce: still end up with buttonState having the
    // proper value, it just may take a few loop()s.
    boolean newButtonState = digitalRead(buttonPin);
    if (newButtonState != lastButtonState) {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > 50) { // debounce delay: 50ms
        buttonState = newButtonState;
    }

    lastButtonState = newButtonState;

    if(state == -1) {
        if (buttonState == LOW) {
            if ((millis() - firstPressedTime) > holdClickTime) {
                state++;
            }
        } else { // buttonState == HIGH: released too early
            q.setRGB("yellow");
            delay(10);
            goToSleep();
        }
    }

    if (state > -1 && buttonState == LOW) {
        pressed = 1;
    } else if (pressed == 1 && buttonState == HIGH) {
        state++;
        pressed = 0;
        // The number of modes
        if (state > 11) {
            state = 99;
        } else if (state > 2) { // Turn everthing off when switching to a blinking mode.
            for(int i=0; i<numLeds; i++) {
                currentLEDvalue[i] = 0; // set current value to 0 so that we can fade up.
            }
        }
    }

    // All of the states set the currentLEDvalue, here we set the LEDs from those values
    for(int i=0; i<numLeds; i++) {
        strip.setPixelColor(i, currentLEDvalue[i]);
    }
    strip.show();

    if (state > 0 && state < 99) {
        doFlashing(state);
    }

    // Waiting for button release to go to sleep
    else if (state == 99) {
        // linear fading
        for(int i=0; i<numLeds; i++) {
            if (currentLEDvalue[i] > 0) {
                currentLEDvalue[i] = fadeDown(currentLEDvalue[i]);
            }
        }
        delay(transitionRate);

        int total = 0;
        for(int i=0; i<numLeds; i++) { total = total + currentLEDvalue[i]; }
        if (total == 0) {
            goToSleep();
        }       // go to sleep when the button's been released and fading is done
    }
}

uint32_t fadeDown(uint32_t val) { return fadeDown(val, 0); }
uint32_t fadeDown(uint32_t val, uint32_t lowVal) {
    uint32_t r = (val >> 16) & 0xff;
    uint32_t g = (val >> 8) & 0xff;
    uint32_t b = val & 0xff;
    if(r > lowVal) { r--; }
    if(g > lowVal) { g--; }
    if(b > lowVal) { b--; }
    return r << 16 | g << 8 | b;
}

uint32_t fadeUp(uint32_t val) { return fadeUp(val, 255); }
uint32_t fadeUp(uint32_t val, uint32_t highVal) {
    uint32_t r = (val >> 16) & 0xff;
    uint32_t g = (val >> 8) & 0xff;
    uint32_t b = val & 0xff;
    if(r < highVal) { r++; }
    if(g < highVal) { g++; }
    if(b < highVal) { b++; }
    return r << 16 | g << 8 | b;
}

// Flash pattern when the Edge turns on
void startupFlash() {
    // v 3.2.2 flash pattern
    for(int j=0; j<2; j++) {
        for(int k = 255; k > 0; k--) {
            for(int i=0; i<numLeds/3; i++) {
                strip.setPixelColor(i * 3, doGamma(k >> (i == 2 ? 0 : 1), 0, 0));
                strip.setPixelColor(i * 3 + 1, doGamma(0, k >> (i == 2 ? 0 : 1), 0));
                strip.setPixelColor(i * 3 + 2, doGamma(0, 0, k >> (i == 2 ? 0 : 1)));
            }
            strip.show();
            delay(1);
        }
    }
}

void goToSleep(void)
{
    state = -1;

    // Disable LEDs.
    for(int i=0; i<numLeds; i++) {
        currentLEDvalue[i] = 0;
        strip.setPixelColor(i, 0);
    }
    strip.show();

    q.setRGB("red");
    delay(100);
    q.ledOff();

    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    noInterrupts();           // timed sequence follows
    // will be called when pin D2 goes low
    attachInterrupt(1, wake, FALLING);
    EIFR = bit(INTF1);  // clear flag for interrupt 0

    interrupts();             // guarantees next instruction executed
    sleep_cpu();

    // cancel sleep as a precaution
    detachInterrupt(1);
    sleep_disable();
    q.setRGB("green");
    delay(10);
    q.ledOff();
    firstPressedTime = millis();
    lastButtonState = LOW;
    pressed = 0;
}

void wake() {
}  // end of wake
