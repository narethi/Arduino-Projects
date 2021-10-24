using Arduino.Shared.Enums;

namespace EpaperUI
{
    public interface IApplicationController
    {
        void SetMode(DisplayMode mode);
        void EstablishArduinoConnection();
    }
}
