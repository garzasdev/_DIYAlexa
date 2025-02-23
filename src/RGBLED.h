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

enum LEDState
{
    LEDOFF
    , LEDOK
    , LEDFAIL
    , LEDERROR
};

class RGBLED
{
    public:
        void begin(int PinNumber);
        void SetState(LEDState State);
        void SetStateWithDelay(LEDState State, int Delay);
        void SetStateOff();
        void SetStateOK();
        void SetStateFail();
        void SetStateError();
        void SetStateStartup();
        void SetColor(uint32_t HSVColor);
        void SetColor(int R, int G, int B);
        void SetColor(char *Color, int Brightness = 100);
        void SetColorWithDelay(uint32_t HSVColor, int Delay);
        void SetColorWithDelay(int R, int G, int B, int Delay);
        void SetColorWithDelay(char *Color, int Brightness = 100, int Delay = 0);
    private:
        Adafruit_NeoPixel *strip;
        void _Delay(int ms);
};
#endif