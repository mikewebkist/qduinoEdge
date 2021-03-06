const byte chasing[256][3] PROGMEM = {
    {168, 0, 0},  {168, 0, 0},  {168, 0, 0},  {168, 0, 0},   {168, 0, 0},   {168, 0, 0},   {168, 0, 0},   {168, 0, 0},
    {168, 0, 0},  {168, 0, 0},  {168, 0, 0},  {168, 0, 0},   {168, 0, 0},   {168, 0, 0},   {168, 0, 0},   {168, 0, 0},
    {168, 0, 0},  {166, 0, 0},  {163, 0, 0},  {161, 0, 0},   {158, 0, 0},   {156, 0, 0},   {154, 0, 0},   {151, 0, 0},
    {149, 0, 0},  {147, 0, 0},  {145, 0, 0},  {143, 0, 0},   {140, 0, 0},   {138, 0, 0},   {136, 0, 0},   {134, 0, 0},
    {132, 0, 0},  {130, 1, 0},  {128, 4, 0},  {126, 8, 0},   {124, 14, 0},  {121, 23, 0},  {119, 34, 0},  {117, 46, 0},
    {115, 61, 0}, {113, 78, 0}, {110, 97, 0}, {108, 118, 0}, {106, 140, 0}, {103, 163, 0}, {101, 186, 0}, {98, 209, 0},
    {95, 232, 0}, {92, 239, 0}, {89, 243, 0}, {86, 246, 0},  {82, 247, 0},  {79, 247, 0},  {76, 245, 0},  {72, 242, 0},
    {69, 238, 0}, {66, 233, 0}, {63, 227, 0}, {60, 221, 0},  {57, 214, 0},  {54, 206, 0},  {51, 199, 0},  {49, 191, 0},
    {46, 183, 0}, {44, 181, 0}, {42, 178, 0}, {41, 176, 0},  {39, 173, 0},  {37, 171, 0},  {36, 168, 0},  {34, 166, 0},
    {32, 163, 0}, {31, 161, 0}, {29, 158, 0}, {28, 156, 0},  {27, 153, 0},  {25, 150, 0},  {24, 148, 0},  {23, 145, 0},
    {22, 143, 0}, {20, 139, 0}, {19, 136, 0}, {17, 133, 0},  {16, 130, 0},  {15, 127, 0},  {14, 124, 0},  {12, 121, 0},
    {11, 118, 0}, {10, 115, 0}, {9, 111, 0},  {8, 108, 0},   {8, 105, 0},   {7, 102, 0},   {6, 99, 0},    {5, 96, 0},
    {5, 93, 0},   {4, 90, 1},   {3, 87, 3},   {3, 85, 8},    {2, 82, 15},   {2, 79, 24},   {2, 76, 35},   {1, 74, 49},
    {1, 71, 65},  {1, 69, 83},  {1, 66, 103}, {0, 64, 125},  {0, 61, 148},  {0, 59, 172},  {0, 57, 197},  {0, 55, 222},
    {0, 53, 247}, {0, 51, 253}, {0, 49, 255}, {0, 48, 255},  {0, 46, 255},  {0, 44, 255},  {0, 43, 255},  {0, 41, 251},
    {0, 40, 246}, {0, 39, 239}, {0, 37, 232}, {0, 36, 223},  {0, 35, 215},  {0, 33, 205},  {0, 32, 196},  {0, 31, 187},
    {0, 30, 177}, {0, 28, 172}, {0, 27, 167}, {0, 26, 162},  {0, 24, 157},  {0, 23, 152},  {0, 22, 147},  {0, 21, 142},
    {0, 20, 137}, {0, 19, 133}, {0, 18, 128}, {0, 17, 124},  {0, 16, 120},  {0, 15, 116},  {0, 14, 112},  {0, 13, 108},
    {0, 12, 105}, {0, 11, 102}, {0, 11, 99},  {0, 10, 97},   {0, 9, 94},    {0, 9, 92},    {0, 8, 90},    {0, 8, 88},
    {0, 7, 86},   {0, 7, 84},   {0, 6, 82},   {0, 6, 80},    {0, 5, 79},    {0, 5, 77},    {0, 4, 76},    {0, 4, 74},
    {0, 4, 73},   {0, 3, 71},   {0, 3, 70},   {0, 3, 69},    {0, 2, 67},    {0, 2, 66},    {0, 2, 65},    {0, 1, 64},
    {0, 1, 62},   {0, 1, 61},   {0, 1, 60},   {0, 1, 59},    {0, 1, 57},    {0, 1, 56},    {0, 0, 54},    {0, 0, 53},
    {0, 0, 51},   {0, 0, 49},   {0, 0, 47},   {0, 0, 44},    {0, 0, 42},    {0, 0, 40},    {0, 0, 38},    {0, 0, 36},
    {0, 0, 33},   {0, 0, 31},   {0, 0, 29},   {0, 0, 27},    {0, 0, 25},    {0, 0, 24},    {0, 0, 22},    {0, 0, 20},
    {0, 0, 18},   {0, 0, 17},   {0, 0, 16},   {0, 0, 15},    {0, 0, 13},    {0, 0, 12},    {0, 0, 11},    {0, 0, 10},
    {0, 0, 9},    {0, 0, 9},    {0, 0, 8},    {0, 0, 7},     {0, 0, 6},     {0, 0, 6},     {0, 0, 5},     {0, 0, 5},
    {0, 0, 4},    {0, 0, 4},    {0, 0, 3},    {0, 0, 3},     {0, 0, 2},     {0, 0, 2},     {0, 0, 2},     {0, 0, 2},
    {0, 0, 1},    {0, 0, 1},    {0, 0, 1},    {0, 0, 1},     {0, 0, 1},     {0, 0, 1},     {0, 0, 1},     {0, 0, 0},
    {0, 0, 0},    {0, 0, 0},    {0, 0, 0},    {0, 0, 0},     {0, 0, 0},     {0, 0, 0},     {0, 0, 0},     {0, 0, 0},
    {0, 0, 0},    {0, 0, 0},    {0, 0, 0},    {0, 0, 0},     {0, 0, 0},     {0, 0, 0},     {0, 0, 0},     {0, 0, 0},
    {0, 0, 0},    {0, 0, 0},    {0, 0, 0},    {0, 0, 0},     {0, 0, 0},     {0, 0, 0},     {0, 0, 0},     {0, 0, 0},
    {0, 0, 0},    {0, 0, 0},    {0, 0, 0},    {0, 0, 0},     {0, 0, 0},     {0, 0, 0},     {0, 0, 0},     {0, 0, 0},
};

void doFlashing(int flash_type) {

    // SAFETY SOLID
    if (state == 1) {
        for(int i=0; i<numLeds; i++) {
            if (currentLEDvalue[i] < doGamma(baseBrightness)) {
                currentLEDvalue[i] = fadeUp(currentLEDvalue[i], doGamma(baseBrightness) & 0xff);
            } // fade in to solidBrightness value
        }
        delay(3);
    }

    // FASHION SOLID
    else if (state == 2) {
        for(int i=0; i<numLeds; i++) {
            if (currentLEDvalue[i] > doGamma(baseBrightness >> 1)) {
                currentLEDvalue[i] = fadeDown(currentLEDvalue[i], doGamma(baseBrightness >> 1) & 0xff);
            } // fade in to solidBrightness value
        }
        delay(3);
    }
    else if (flash_type == 3) {      // Mackey special
        // 1000ms 100ms 100ms
        // Fade in 500ms, Fade out 500ms,
        // on 100ms, off 100ms
        long time = (millis() - modeStartTime) % 1200;
        long fadeVal = 0;
        long flashVal = 0;

        // Fade in
        if (time < 500) { fadeVal = time * baseBrightness / 1000; flashVal = 0; }
        // Fade out
        else if (time >= 500 && time < 1000)  { fadeVal = (500 - (time - 500)) * baseBrightness / 1000; flashVal = 0; }
        // Turn on middle
        else if (time >= 1000 && time < 1100) { fadeVal = 0; flashVal = baseBrightness; }
        // Turn off middle
        else if (time >= 1100 && time < 1200) { fadeVal = 0; flashVal = 0; }


        for(int i=0; i<3; i++) {
            currentLEDvalue[i] = doGamma(fadeVal);
            currentLEDvalue[i + 6] = doGamma(fadeVal);
        }

        for(int i=0; i<3; i++) {
            currentLEDvalue[i + 3] = doGamma(flashVal);
        }


    }

    else if (flash_type == 4) {      // chasing
        for(int i=0; i<numLeds; i++) {
            currentLEDvalue[i] = doGamma(pgm_read_byte(&(chasing[frameStep][i % 3])) * baseBrightness / 255);
        }
        delay(3);
        frameStep = (frameStep + 1) % 256;  // reset! consider variable-length flash pattern, then 255 should be something else.
    }

    else if (flash_type == 5) { softNoise(); }
    else if (flash_type == 6) { fireflies(); }
    else if (flash_type == 7) { flickerSunrise(); }
    else if (flash_type == 8) { binaryCount(); }
    else if (flash_type == 9) { grayCount(); }
    else if (flash_type == 10) { johnsonSpiral(); }
    else if (flash_type == 11) { batteryLevel(); }
}

void softNoise() {
    currentLEDvalue[(millis()/20)%numLeds] = doGamma(random(baseBrightness));
}

void fireflies() {
    static long nextFly[numLeds];

    static uint32_t fireflyFade = 0x010100;
    static int flyTime = 10000;      // max time between flashes on an LED
    static long timeNow;

    timeNow = millis();

    // flash the fly if its wait time has passed
    for (int x = 0; x < numLeds; x++){
        if (timeNow > nextFly[x]) {
            // uint32_t flyGlow = random(baseBrightness >> 1, baseBrightness);
            uint32_t flyGlow = baseBrightness;
            currentLEDvalue[x] = doGamma(flyGlow, flyGlow, 0);
            nextFly[x] = timeNow + random(flyTime);
        }
        else if ((timeNow - nextFly[x]) > flyTime) {    // eliminate weird persistence from previous iterations
            nextFly[x] = timeNow + random(flyTime);
        }
    }

    // fade
    for(int i=0; i<numLeds; i++) {
        if(currentLEDvalue[i] > 0) {
            currentLEDvalue[i] = currentLEDvalue[i] - fireflyFade;
        }
    }
}

void flickerSunrise() {
    int counter = (millis()/50)%256;

    // fade
    for(int i=0; i<numLeds/3; i++) {
        currentLEDvalue[i] = doGamma(random(counter) >> 1);
        currentLEDvalue[i + 2 * numLeds / 3] = doGamma(random(counter) >> 1);
        currentLEDvalue[i + numLeds / 3] = doGamma(random(counter), random(counter), 0);
    }
}

void binaryCount() {
    static int n = 0;
    const unsigned long nextIncrement = 250;
    static unsigned long nextTime = 0;
    unsigned long timeNow;

    timeNow = millis();
    if (timeNow > nextTime) {
        for(int i=0; i<numLeds; i++) {
            currentLEDvalue[i] =  doGamma(((n >> i) &  1) * baseBrightness);
        }
        n++;
        nextTime = timeNow + nextIncrement;
    }
}

void grayCount() {
    // http://en.wikipedia.org/wiki/Gray_code
    static int n = 0;
    const unsigned long nextIncrement = 250;
    static unsigned long nextTime = 0;
    unsigned long timeNow;

    timeNow = millis();
    if (timeNow > nextTime) {
        int x = n - 1;
        x = x ^ (x >> 1);
        for(int i=0; i<numLeds; i++) {
            currentLEDvalue[i] = doGamma(((x >> i) & 1) * baseBrightness);
        }
        n++;
        nextTime = timeNow + nextIncrement;
    }
}

void johnsonSpiral() {
    static long sequences[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8,   // Normal
                                0, 1, 2, 5, 4, 3, 6, 7, 8,   // Snake
                                0, 1, 2, 5, 8, 7, 6, 3, 4,   // Spiral
                                4, 3, 6, 7, 8, 5, 2, 1, 0,   // Spiral reverse
                                0, 2, 8, 6, 3, 1, 5, 7, 4,   // Corners, Edges, Middle
                                4, 7, 5, 1, 3, 6, 8, 2, 0,   // Corners, Edges, Middle reverse
                                0, 4, 8, 7, 6, 4, 2, 1, 0,   // Zorro
                                0, 3, 1, 2, 4, 6, 7, 5, 8,   // Zig
                                0, 3, 1, 6, 4, 2, 7, 5, 8 }; // Zag
    static int n = 0;
    const unsigned long nextIncrement = 100;
    static unsigned long nextTime = 0;
    unsigned long timeNow;
    static byte r = baseBrightness;
    static byte g = baseBrightness;
    static byte b = baseBrightness;
    static int sub_seq = random(sizeof(sequences)/sizeof(long)/9);

    timeNow = millis();
    if (timeNow > nextTime) {
        // Take LSB, flip it, move it to MSB, shift byte right 1 bit.
        n = ((n >> (numLeds - 1)) ^ 1) | (n << 1) & ((1 << numLeds) - 1);
        for(int i=0; i<numLeds; i++) {
            currentLEDvalue[sequences[i + sub_seq * 9]] =  doGamma(((n >> i) & 1) * r, ((n >> i) & 1) * g, ((n >> i) & 1) * b);
        }

        if(n == 0) {
            r = random(baseBrightness >> 1) + (baseBrightness >> 1);
            g = random(baseBrightness >> 1) + (baseBrightness >> 1);
            b = random(baseBrightness >> 1) + (baseBrightness >> 1);
            sub_seq = random(sizeof(sequences)/sizeof(long)/9);
        }
        nextTime = timeNow + nextIncrement;
    }
}

void batteryLevel() {
    static long nextIncrement = 10000;
    static long nextTime = 0;
    static int brightness = 0;
    long timeNow;
    static int charge;

    timeNow = millis();
    if (timeNow > nextTime) {
        battery.wakeUp();
        charge = battery.chargePercentage();
        battery.reset();
        nextTime = timeNow + nextIncrement;
        battery.goToSleep();
    }

    brightness = (millis() / 5) % (baseBrightness * 2);
    if(brightness > baseBrightness) {
        brightness = baseBrightness - (brightness - baseBrightness);
    }

    for(int i=0; i<numLeds; i++) {
        if(i <= (numLeds * charge / 100)) {
            if(charge > 66) { currentLEDvalue[i] = doGamma(0, brightness, 0); }
            else if(charge > 33) { currentLEDvalue[i] = doGamma(brightness, brightness, 0); }
            else { currentLEDvalue[i] = doGamma(brightness, 0, 0); }
        } else {
            currentLEDvalue[i] = 0;
        }
    }
}
