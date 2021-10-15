
using Arduino;
using Arduino.Shared.Enums;
using ArduinoExceptions;
using System;
using System.Diagnostics;

namespace EpaperUI
{
    public class ArduinoController : IDisposable
    {
        private readonly Controller _arduinoController;
        public bool ArduinoControlInitialized { get; private set; }
        public SerialErrorCodes LastError { get; private set; }

        public ArduinoController()
        {
            try
            {
                _arduinoController = new();
                ArduinoControlInitialized = true;
            }
            catch (DeviceException e)
            {
                ArduinoControlInitialized = false;
                LastError = (SerialErrorCodes)e.ReadError();
            }
        }

        public void SetMode(string mode)
        {
            _arduinoController.SetMode(mode);
        }

        #region IDisposable Implementation
        private bool _isDisposed = false;

        #if DEBUG
        private string _caller = Environment.StackTrace;
        #endif

        public void Dispose()
        {
            if(!_isDisposed)
            {
                _arduinoController?.Dispose();
                _isDisposed = true;
            }
        }

        ~ArduinoController()
        {
            Debug.Assert(!_isDisposed, "Failed to dispose the ArduinoController in the application controller");
            GC.SuppressFinalize(this);
        }

        #endregion
    }
}
