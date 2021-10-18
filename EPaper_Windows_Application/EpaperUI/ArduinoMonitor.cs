using System;
using System.Timers;
using Arduino;
using ArduinoExceptions;
using EpaperUI.EventTypes;

namespace EpaperUI
{
    public class ArduinoMonitor
    {
        public event ProcessExceptionHandler TimerCompleted;

        private Timer _arduinoWatcher;
        private readonly Controller _arduino;

        public ArduinoMonitor(Controller arduino)
        {
            _arduino = arduino;
            _arduinoWatcher = new Timer()
            {
                Interval = 1000,
                AutoReset = true
            };
        }

        void CheckArduinoState(object sender, ElapsedEventArgs e)
        {
            try
            {
                _arduino.CheckDeviceState();
            }
            catch (DeviceException timerException)
            {
                TimerCompleted?.Invoke(timerException);
                StopMonitor();
            }   
        }

        public void StartMonitor()
        {
            //If the timer is active then don't try to reactivate it
            if(!_arduinoWatcher.Enabled)
            {
                _arduinoWatcher.Elapsed += CheckArduinoState;
                _arduinoWatcher.Start();
            }
        }

        public void StopMonitor()
        {
            _arduinoWatcher.Stop();
            //Unsubscribe to the timer event to prevent the event from being called if the timer is messed up
            _arduinoWatcher.Elapsed -= CheckArduinoState;
        }
    }
}
