#ifndef _RGBLED_h_
#define _RGBLED_h_

#include "config.h"
#include <Adafruit_NeoPixel.h>


// LEDs
// #define LED_RED 5
// // #define LED_GRN 18
// // #define LED_BLU 19
// #define LED_GRN 12
// #define LED_BLU 14

class RGBLED
{
    public:
        void begin(int PinNumber);
        void SetState(int LEDPin, bool LEDState);
        void SetOnlyState(int LEDPin, bool LEDState);
        void SetOnlyStateWithDelay(int LEDPin, bool LEDState, int DelayTime);
        void SetColor(char *Color);
        void SetColorWithDelay(char *Color, int DelayTime);
        void TurnOffAllLEDs();
    private:
        Adafruit_NeoPixel *strip;
};
#endif