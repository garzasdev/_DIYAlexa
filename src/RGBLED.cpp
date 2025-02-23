#include "Arduino.h"
#include "RGBLED.h"

// // LEDs
// #define LED_RED 5
// #define LED_GRN 18
// #define LED_BLU 19

void RGBLED::begin(int PinNumber)
{
    strip = new Adafruit_NeoPixel(12, PinNumber, NEO_GRB + NEO_KHZ800);
    strip->begin();
    strip->setBrightness(255);
    strip->setPixelColor(0, 0, 255, 0);
    strip->show();
}

void RGBLED::SetState(int LEDPin, bool LEDState)
{
//    if (LEDPin == LED_RED || LEDPin == LED_GRN || LEDPin == LED_BLU) digitalWrite(LEDPin, (LEDState ==  true));
}

void RGBLED::SetOnlyState(int LEDPin, bool LEDState)
{
//    if (LEDPin == LED_RED || LEDPin == LED_GRN || LEDPin == LED_BLU)
    {
        TurnOffAllLEDs();

        SetState(LEDPin, LEDState);
    }
}

void RGBLED::SetOnlyStateWithDelay(int LEDPin, bool LEDState, int DelayTime)
{
    SetOnlyState(LEDPin, LEDState);
    delay(DelayTime);
    SetState(LEDPin, LOW);
}

void RGBLED::SetColor(char *Color)
{
    TurnOffAllLEDs();

    if (strcmp(Color, "YEL") == 0 || strcmp(Color, "YELLOW") == 0)
    {
Serial.println("LED Yellow");
//        digitalWrite(LED_RED, HIGH);
//        digitalWrite(LED_GRN, HIGH);
    }

    if (strcmp(Color, "PUR") == 0 || strcmp(Color, "PURPLE") == 0)
    {
Serial.println("LED Purple");
//        digitalWrite(LED_RED, HIGH);
//        digitalWrite(LED_BLU, HIGH);
    }

    if (strcmp(Color, "CYN") == 0 || strcmp(Color, "CYAN") == 0)
    {
Serial.println("LED Cyan");
//        digitalWrite(LED_GRN, HIGH);
//        digitalWrite(LED_BLU, HIGH);
    }

    if (strcmp(Color, "WHT") == 0 || strcmp(Color, "WHITE") == 0)
    {
Serial.println("LED White");
//        digitalWrite(LED_RED, HIGH);
//        digitalWrite(LED_BLU, HIGH);
//        digitalWrite(LED_GRN, HIGH);
    }
}

void RGBLED::SetColorWithDelay(char *Color, int DelayTime)
{
    SetColor(Color);
    delay(DelayTime);
}




void RGBLED::TurnOffAllLEDs()
{
//    digitalWrite(LED_RED, LOW);
//    digitalWrite(LED_GRN, LOW);
//    digitalWrite(LED_BLU, LOW);
}