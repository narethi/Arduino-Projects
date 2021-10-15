using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace EpaperUI
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application, IDisposable
    {
        private ApplicationController _applicationController;

        private App()
        {
            _applicationController = new();
        }

        protected override void OnStartup(StartupEventArgs e)
        {
            //Call the base application start up
            base.OnStartup(e);

            //Create the main application window, set the application controller to the window
            var applicationWindow = new MainWindow()
            {
                ApplicationController = _applicationController
            };

            //Open as a modal dialog
            applicationWindow.ShowDialog();

            //Run the application controller clean up
            Dispose(true);

            //Close the applicaiton, use 0 to show that the close is successful
            Environment.Exit(0);
        }

        #region IDisposable Implementation
        private bool _isDisposed = false;

#if DEBUG
        private string _caller = Environment.StackTrace;
#endif

        public void Dispose()
        {
            Dispose(false);
        }

        private void Dispose(bool isDisposing)
        {
            if (isDisposing)
            {
                _applicationController.Dispose();
                _isDisposed = true;
            }
        }

        ~App()
        {
            Debug.Assert(!_isDisposed, "Failed to dispose the ArduinoController in the application controller");
            GC.SuppressFinalize(this);
        }

        #endregion
    }
}
