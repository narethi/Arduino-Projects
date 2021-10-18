using Arduino;
using Arduino.Shared.Enums;
using ArduinoExceptions;
using EpaperUI.EventTypes;
using System;
using System.Diagnostics;
using System.Threading.Tasks;

namespace EpaperUI
{
    public class ArduinoController : IDisposable
    {
        private Controller _arduinoController;
        private ArduinoMonitor _monitor;
        public event ProcessExceptionHandler ProcessTimerException;
        public bool ArduinoControlInitialized { get; private set; } = false;
        public SerialErrorCodes LastError { get; private set; } = SerialErrorCodes.UnknownError;

        public ArduinoController()
        {
        }


        public void RunMonitor()
        {
            _monitor.StartMonitor();
        }

        public void StopMonitor()
        {
            _monitor.StopMonitor();
        }

        private void ResetMonitor()
        {
            if(_monitor != null)
            {
                _monitor.StopMonitor();
                _monitor.TimerCompleted -= ProcessTimerException;
            }
            
            _monitor = new(_arduinoController);
            _monitor.TimerCompleted += ProcessTimerException;
        }

        public void InitializeController()
        {
            try
            {   
                _arduinoController?.Dispose();
                _arduinoController = new();
                ResetMonitor();
                ArduinoControlInitialized = true;
            }
            catch (DeviceException e)
            {
                ArduinoControlInitialized = false;
                LastError = (SerialErrorCodes)e.ReadError();
                throw;
            }
        }

        public void SetMode(string mode)
        {
            try
            {
                _arduinoController.SetMode(mode);
            }
            catch (DeviceException e)
            {
                ArduinoControlInitialized = false;
                LastError = (SerialErrorCodes)e.ReadError();
                throw;
            }
        }

        #region IDisposable Implementation
        private bool _isDisposed = false;

        #if DEBUG
        private string _caller = Environment.StackTrace;
#endif

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        public void Dispose(bool isDisposing)
        {
            if(!isDisposing)
            {
                _arduinoController?.Dispose();
                _isDisposed = true;
            }
        }

        ~ArduinoController()
        {
            Debug.Assert(!_isDisposed, "Failed to dispose the ArduinoController in the application controller");
            Dispose(false);
        }

        #endregion
    }
}
