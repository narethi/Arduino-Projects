using EpaperUI.Controllers;
using EpaperUI.EventTypes;
using EpaperUI.Model;
using System;
using System.Diagnostics;
using System.Threading.Tasks;

namespace EpaperUI
{
   public class ApplicationController : IApplicationController, IDisposable
   {
        public MessageController MessageController { get; private set; }
        public ArduinoController ArduinoController { get; private set; }

        public event ShowMessageHandler ShowMessage;

        public object MessageLock = new();
        public ApplicationController()
        {
            //The order matters here, we need to set up the message handler immediately so that it can be used to show messages
            //About the other controllers when errors occur
            MessageController = new();
            MessageController.ShowMessage += OnShowMessage;
            try
            {
                ArduinoController = new();
                ArduinoController.InitializeController();
            }
            catch(Exception e)
            {
                MessageController.SetErrorFromException(e);
            }
        }

        public void SetMode(string mode)
        {
            if(ArduinoController.ArduinoControlInitialized == false)
            {
                MessageController.SetErrorMessage("Failed to set mode to {0} for arduino connected to port {1}", mode, "COM8");
                return;
            }
            try
            {
                ArduinoController.SetMode(mode);
            }
            catch (Exception e)
            {
                MessageController.SetErrorFromException(e);
            }
        }

        private void OnShowMessage(MessageDataContract messageData)
        {
            //There is a race condition in the start up where the message controller gets called
            //before the message receiver is initialized, to handle this the messaging thread
            //will be held up by this lock until the message has some where to go
            //An alternative is to keep the list of all system messages in a list some where and
            //access it at start up
            lock(MessageLock)
            {
                while(ShowMessage == null)
                {
                    //This isn't a high priority task so wait for a
                    //second before checking again to keep the
                    //polling fairly low rate
                    Task.Delay(1000);
                }
                ShowMessage?.Invoke(messageData);
            }
            
        }

        #region IDisposable Implementation

        private bool _isDisposed = false;

        #if DEBUG
        private string _caller = Environment.StackTrace;
        #endif

        public void Dispose()
        {
            if (!_isDisposed)
            {
                ArduinoController?.Dispose();
                MessageController.ShowMessage -= ShowMessage;
                _isDisposed = true;
            }
        }

        ~ApplicationController()
        {
            Debug.Assert(_isDisposed, "Failed to dispose the ArduinoController in the application controller");
            GC.SuppressFinalize(this);
        }

        #endregion
    }
}
