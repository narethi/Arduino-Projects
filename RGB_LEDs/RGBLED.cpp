#include "Arduino.h"
#include "RGBLED.h"

const int MAX_CHANNEL_VALUE = 255;
const int MIN_CHANNEL_VALUE = 0;

RGBLED::RGBLED(int redPin, int greenPin, int bluePin)
{
    ColourChannelPins[0] = redPin; ColourChannelPins[1] = greenPin; ColourChannelPins[2] = bluePin;
}

void RGBLED::TurnOnChannels()
{
    TurnOnRedColourChannel();
    TurnOnGreenColourChannel();
    TurnOnBlueColourChannel();
}

void RGBLED::TurnOnRedColourChannel()
{
    TurnOnColourChannel(ColourChannelPins[0], RedChannelValue);
}

void RGBLED::TurnOnGreenColourChannel()
{
    TurnOnColourChannel(ColourChannelPins[1], GreenChannelValue);
}

void RGBLED::TurnOnBlueColourChannel()
{
    TurnOnColourChannel(ColourChannelPins[2], BlueChannelValue);
}

void RGBLED::TurnOnRedColourChannel(int overrideValue)
{
    TurnOnColourChannel(ColourChannelPins[0], overrideValue);
}

void RGBLED::TurnOnGreenColourChannel(int overrideValue)
{
    TurnOnColourChannel(ColourChannelPins[1], overrideValue);
}

void RGBLED::TurnOnBlueColourChannel(int overrideValue)
{
    TurnOnColourChannel(ColourChannelPins[2], overrideValue);
}

void CheckAndSetColourChannel(int *channel, int value)
{
    if(value > MAX_CHANNEL_VALUE) value = MAX_CHANNEL_VALUE;
    else if(value < MIN_CHANNEL_VALUE) value = MIN_CHANNEL_VALUE;
    *channel = value;
}

void RGBLED::SetColour(int red, int green, int blue)
{
    CheckAndSetColourChannel(&RedChannelValue, red);
    CheckAndSetColourChannel(&GreenChannelValue, green);
    CheckAndSetColourChannel(&BlueChannelValue, blue);
}

void RGBLED::TurnOnColourChannel(int pin, int value)
{
    if(value == MIN_CHANNEL_VALUE)
    {
        digitalWrite(pin, LOW);
        delayMicroseconds(MAX_CHANNEL_VALUE);
        return;
    }
    digitalWrite(pin, HIGH);
    delayMicroseconds(value);
    digitalWrite(pin, LOW);
    delayMicroseconds(MAX_CHANNEL_VALUE-value);
}

void RGBLED::Breathe(int millisecondDuration)
{
    millisecondDuration /= 2;
    GlowUp(millisecondDuration);
    GlowDown(millisecondDuration);
}

void RGBLED::GlowUp(int millisecondDuration)
{
    GlowInternal(millisecondDuration, GlowDirection::UP);
}

void RGBLED::GlowDown(int millisecondDuration)
{
    GlowInternal(millisecondDuration, GlowDirection::DOWN);
}

void RGBLED::GlowInternal(int millisecondDuration, GlowDirection direction)
{
    double cycles = cyclesToMilliseconds * millisecondDuration;
    double redStepSize = RedChannelValue/cycles;
    double greenStepSize = GreenChannelValue/cycles;
    double blueStepSize = BlueChannelValue/cycles;
    for(int i = 0; i < cycles; i++)
    {
        auto redDelta = i*redStepSize;
        auto greenDelta =  i*greenStepSize;
        auto blueDelta = i*blueStepSize;
        if(direction == GlowDirection::DOWN)
        {
            TurnOnRedColourChannel(RedChannelValue - redDelta);
            TurnOnGreenColourChannel(GreenChannelValue - greenDelta);
            TurnOnBlueColourChannel(BlueChannelValue - blueDelta);
        }
        else
        {
            TurnOnRedColourChannel(redDelta);
            TurnOnGreenColourChannel(greenDelta);
            TurnOnBlueColourChannel(blueDelta);
        }
    }
}