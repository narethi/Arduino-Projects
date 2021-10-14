#include "GlowDirection.h"

class RGBLED
{
    public:
        void SetColour(int red, int green, int blue);
        void TurnOnChannels();
        void GlowUp(int millisecondDuration);
        void GlowDown(int millisecondDuration);
        void Breathe(int millisecondDuration);
        RGBLED(int redPin, int greenPin, int bluePin);

    private:
        int ColourChannelPins[3];
        int RedChannelValue = 0;
        int BlueChannelValue = 0;
        int GreenChannelValue = 0;

        static const double cyclesToMilliseconds = 1000/(255*3);
        
        RGBLED();
        void TurnOnColourChannel(int pin, int value);
        void TurnOnRedColourChannel();
        void TurnOnGreenColourChannel();
        void TurnOnBlueColourChannel();
        void TurnOnRedColourChannel(int overrideValue);
        void TurnOnGreenColourChannel(int overrideValue);
        void TurnOnBlueColourChannel(int overrideValue);
        void GlowInternal(int millisecondDuration, GlowDirection direction);
};