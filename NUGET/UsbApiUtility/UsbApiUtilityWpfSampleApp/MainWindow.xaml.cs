using System;
using System.Windows;
using UsbApiUtility;

namespace ManagedSampleApplication
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        UsbApiController sampleController;
        public MainWindow()
        {
            sampleController = new UsbApiController("COM8");
            InitializeComponent();
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            sampleController.Dispose();
        }
    }
}
