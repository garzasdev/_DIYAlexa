#include "Arduino.h"
#include "RGBLED.h"

void RGBLED::begin(int PinNumber)
{
    strip = new Adafruit_NeoPixel(12, PinNumber, NEO_GRB + NEO_KHZ800);
    strip->begin();
    strip->setBrightness(255);
    strip->clear();
    strip->show();
}

void RGBLED::SetState(LEDState State)
{
    strip->clear();

    switch (State)
    {
        case LEDOFF:
            break;
        case LEDOK:
            strip->fill(strip->ColorHSV(21845));
            break;
        case LEDFAIL:
            strip->fill(strip->ColorHSV(0));
            break;
        case LEDERROR:
            strip->fill(strip->ColorHSV(10922));
            break;
    }

    strip->show();
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
    strip->clear();
    strip->show();
}

void RGBLED::SetColor(uint32_t HSVColor)
{
    strip->clear();
    strip->fill(HSVColor);
    strip->show();
}
void RGBLED::SetColor(int R, int G, int B)
{
    strip->fill(strip->Color(R, G, B));
}
void RGBLED::SetColor(char *Color, int Brightness)
{
    if (strcmp(Color, "RED") == 0) SetColor(strip->ColorHSV(0, 255, Brightness));
    if ((strcmp(Color, "GRN") == 0) || (strcmp(Color, "GREEN") == 0)) SetColor(strip->ColorHSV(21845, 255, Brightness));
    if ((strcmp(Color, "BLU") == 0) || (strcmp(Color, "BLUE") == 0)) SetColor(strip->ColorHSV(43690, 255, Brightness));
    if ((strcmp(Color, "CYN") == 0) || (strcmp(Color, "CYAN") == 0)) SetColor(strip->ColorHSV(32768, 255, Brightness));
    if ((strcmp(Color, "PUR") == 0) || (strcmp(Color, "PURPLE") == 0)) SetColor(strip->ColorHSV(54612, 255, Brightness));
    if ((strcmp(Color, "WHT") == 0) || (strcmp(Color, "WHITE") == 0)) SetColor(strip->ColorHSV(0, 0, Brightness));
    if ((strcmp(Color, "YEL") == 0) || (strcmp(Color, "YELLOW") == 0)) SetColor(strip->ColorHSV(10922, 255, Brightness));
    if ((strcmp(Color, "ORN") == 0) || (strcmp(Color, "ORANGE") == 0)) SetColor(strip->ColorHSV(5461, 255, Brightness));
    if (strcmp(Color, "OFF") == 0)
    {
        strip->clear();
        strip->show();
    }
}

void RGBLED::SetColorWithDelay(uint32_t HSVColor, int Delay)
{
    SetColor(HSVColor);
    _Delay(Delay);
    strip->clear();
    strip->show();
}
void RGBLED::SetColorWithDelay(int R, int G, int B, int Delay)
{
    SetColor(R, G, B);
    _Delay(Delay);
    strip->clear();
    strip->show();

}
void RGBLED::SetColorWithDelay(char *Color, int Brightness, int Delay)
{
    float _brightness = Brightness / 100.00;

    SetColor(Color, 255 * _brightness);
    _Delay(Delay);
    strip->clear();
    strip->show();
}

void RGBLED::_Delay(int ms)
{
    unsigned long now = millis();

    while (millis() - now > ms) { yield(); }
}