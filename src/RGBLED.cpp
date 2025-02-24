#include "Arduino.h"
#include "RGBLED.h"

Adafruit_NeoPixel strip(12, 5, NEO_GRB + NEO_KHZ800);

void RGBLED::begin(int PinNumber)
{
    // strip = new Adafruit_NeoPixel(12, PinNumber, NEO_GRB + NEO_KHZ800);
    // strip->begin();
    // strip->setBrightness(255);
    // strip->fill(0); //strip->clear();
    // strip->show();
    strip.begin();
    strip.setBrightness(255);
    strip.clear();
    strip.show();
}

void RGBLED::SetState(LEDState State)
{
    // strip->fill(0); //strip->clear();
    strip.clear();

    switch (State)
    {
        case LEDOFF:
            break;
        case LEDOK:
            // strip->fill(strip->ColorHSV(21845));
            strip.fill(strip.ColorHSV(21485));
            break;
        case LEDFAIL:
            // strip->fill(strip->ColorHSV(0));
            strip.fill(strip.ColorHSV(0));
            break;
        case LEDERROR:
            // strip->fill(strip->ColorHSV(10922));
            strip.fill(strip.ColorHSV(10922));
            break;
    }

    // strip->show();
    strip.show();
}

void RGBLED::SetStateOff() { SetState(LEDOFF); }
void RGBLED::SetStateOK() { SetState(LEDOK); }
void RGBLED::SetStateFail() { SetState(LEDFAIL); }
void RGBLED::SetStateError() { SetState(LEDERROR); }
void RGBLED::SetStateStartup() 
{
    int _WaitMS = 1;

    for ( int x = 0 ; x <= 100 ; x++ ) { SetColor((char *)"RED", x); delay(_WaitMS); }
    for ( int x = 100 ; x >= 0 ; x-- ) { SetColor((char *)"RED", x); delay(_WaitMS); }
    for ( int x = 0 ; x <= 100 ; x++ ) { SetColor((char *)"GRN", x); delay(_WaitMS); }
    for ( int x = 100 ; x >= 0 ; x-- ) { SetColor((char *)"GRN", x); delay(_WaitMS); }
    for ( int x = 0 ; x <= 100 ; x++ ) { SetColor((char *)"BLU", x); delay(_WaitMS); }
    for ( int x = 100 ; x >= 0 ; x-- ) { SetColor((char *)"BLU", x); delay(_WaitMS); }
}

void RGBLED::SetStateWithDelay(LEDState State, int Delay)
{
    SetState(State);
    _Delay(Delay);
    // strip->fill(0); //strip->clear();
    // strip->show();
    strip.clear();
    strip.show();
}

void RGBLED::SetColor(uint32_t HSVColor)
{
    // strip->fill(0); //strip->clear();
    // strip->fill(HSVColor);
    // strip->show();
    strip.clear();
    strip.fill(HSVColor);
    strip.show();
}
void RGBLED::SetColor(int R, int G, int B)
{
    // strip->fill(strip->Color(R, G, B));
    strip.clear();
    strip.fill(strip.Color(R, G, B));
    strip.show();
}
void RGBLED::SetColor(char *Color, int Brightness)
{
    // uint32_t HSVColor = 0;
    int _brightness = 255 * ((float)Brightness / 100.00);

    // if (strcmp(Color, (char *)"RED") == 0) HSVColor = strip->ColorHSV(0, 255, Brightness);
    // if ((strcmp(Color, (char *)"GRN") == 0) || (strcmp(Color, (char *)"GREEN") == 0)) HSVColor = strip->ColorHSV(21845, 255, Brightness);
    // if ((strcmp(Color, (char *)"BLU") == 0) || (strcmp(Color, (char *)"BLUE") == 0)) HSVColor = strip->ColorHSV(43690, 255, Brightness);
    // if ((strcmp(Color, (char *)"CYN") == 0) || (strcmp(Color, (char *)"CYAN") == 0)) HSVColor = strip->ColorHSV(32768, 255, Brightness);
    // if ((strcmp(Color, (char *)"PUR") == 0) || (strcmp(Color, (char *)"PURPLE") == 0)) HSVColor = strip->ColorHSV(54612, 255, Brightness);
    // if ((strcmp(Color, (char *)"WHT") == 0) || (strcmp(Color, (char *)"WHITE") == 0)) HSVColor = strip->ColorHSV(0, 0, Brightness);
    // if ((strcmp(Color, (char *)"YEL") == 0) || (strcmp(Color, (char *)"YELLOW") == 0)) HSVColor = strip->ColorHSV(10922, 255, Brightness);
    // if ((strcmp(Color, (char *)"ORN") == 0) || (strcmp(Color, (char *)"ORANGE") == 0)) HSVColor = strip->ColorHSV(5461, 255, Brightness);
    if (strcmp(Color, (char *)"RED") == 0) strip.fill(strip.ColorHSV(0, 255, Brightness));
    if ((strcmp(Color, (char *)"GRN") == 0) || (strcmp(Color, (char *)"GREEN") == 0)) strip.fill(strip.ColorHSV(21845, 255, _brightness));
    if ((strcmp(Color, (char *)"BLU") == 0) || (strcmp(Color, (char *)"BLUE") == 0)) strip.fill(strip.ColorHSV(43690, 255, _brightness));
    if ((strcmp(Color, (char *)"CYN") == 0) || (strcmp(Color, (char *)"CYAN") == 0)) strip.fill(strip.ColorHSV(32768, 255, _brightness));
    if ((strcmp(Color, (char *)"PUR") == 0) || (strcmp(Color, (char *)"PURPLE") == 0)) strip.fill(strip.ColorHSV(54612, 255, _brightness));
    if ((strcmp(Color, (char *)"WHT") == 0) || (strcmp(Color, (char *)"WHITE") == 0)) strip.fill(strip.ColorHSV(0, 0, _brightness));
    if ((strcmp(Color, (char *)"YEL") == 0) || (strcmp(Color, (char *)"YELLOW") == 0)) strip.fill(strip.ColorHSV(10922, 255, _brightness));
    if ((strcmp(Color, (char *)"ORN") == 0) || (strcmp(Color, (char *)"ORANGE") == 0)) strip.fill(strip.ColorHSV(5461, 255, _brightness));
    if (strcmp(Color, (char *)"OFF") == 0)
    {
        // strip->fill(0); //strip->clear();
        // strip->show();
        strip.clear();
    }
    strip.show();
}

void RGBLED::SetColorWithDelay(uint32_t HSVColor, int Delay)
{
    SetColor(HSVColor);
    _Delay(Delay);
    // strip->fill(0); //strip->clear();
    // strip->show();
    strip.clear();
    strip.show();
}
void RGBLED::SetColorWithDelay(int R, int G, int B, int Delay)
{
    SetColor(R, G, B);
    _Delay(Delay);
    // strip->fill(0); //strip->clear();
    // strip->show();
    strip.clear();
    strip.show();

}
void RGBLED::SetColorWithDelay(char *Color, int Brightness, int Delay)
{
    int _brightness = 255 * ((float)Brightness / 100.00);

    SetColor(Color, _brightness);
    _Delay(Delay);
    // strip->fill(0); //strip->clear();
    // strip->show();
    strip.clear();
    strip.show();
}

void RGBLED::_Delay(int ms)
{
    unsigned long now = millis();

    while (millis() - now > ms) { yield(); }
}