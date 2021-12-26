using System.Windows;
using UsbApiUtility;

namespace ManagedSampleApplication
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            var test1 = new UsbApiController("COM8");
            test1.Dispose();
            InitializeComponent();
        }
    }
}
