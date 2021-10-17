using EpaperUI.Model;
using EpaperUI.ViewModel;
using System;
using System.Diagnostics;
using System.Windows;

namespace EpaperUI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window, IDisposable
    {
        private MainWindowViewModel _viewModel = new();
        public IApplicationController ApplicationController;

        public MainWindow()
        {
            InitializeComponent();
            DataContext = _viewModel;
        }

        public void OnShowMessage(MessageDataContract messageData)
        {
            Dispatcher.Invoke(() => _viewModel.Messages.Add(messageData));
        }

        private void EPaperControl_SetMode(object sender, RoutedEventArgs e)
        {
            if(e is SetModeRoutedEventArgs setModeArgs)
            {
                ApplicationController.SetMode(setModeArgs.Mode);
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
            if (!isDisposing)
            {
                //Do Dispose here
            }
            //Do any always required even on bad handling dispose here
        }

        ~MainWindow()
        {
            Debug.Assert(!_isDisposed, "Failed to dispose the ArduinoController in the application controller");
            Dispose(false);
        }

        #endregion
    }
}

