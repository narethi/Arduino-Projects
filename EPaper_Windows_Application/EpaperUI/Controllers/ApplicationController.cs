using EpaperUI.Controllers;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EpaperUI
{
   public class ApplicationController : IApplicationController, IDisposable
   {
        public MessageController MessageController { get; private set; }
        public ArduinoController ArduinoController { get; private set; }

        public ApplicationController()
        {
            ArduinoController = new();
            MessageController = new();
        }

        public void SetMode(string mode)
        {
            ArduinoController.SetMode(mode);
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
                ArduinoController.Dispose();
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
