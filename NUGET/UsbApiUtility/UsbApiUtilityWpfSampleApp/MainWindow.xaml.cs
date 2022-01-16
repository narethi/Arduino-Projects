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
            try
            {
                sampleController = new UsbApiController("COM8");
            }
            catch (UsbApiException e) 
            {
                Console.WriteLine(e.Message);
            }
            InitializeComponent();
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            sampleController?.Dispose();
        }
    }
}
