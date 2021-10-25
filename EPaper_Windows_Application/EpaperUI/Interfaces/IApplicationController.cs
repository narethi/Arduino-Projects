using Arduino.Shared.Enums;

namespace EpaperUI
{
    public interface IApplicationController
    {
        void SetMode(DisplayMode mode, params object[] args);
        void EstablishArduinoConnection();
    }
}
