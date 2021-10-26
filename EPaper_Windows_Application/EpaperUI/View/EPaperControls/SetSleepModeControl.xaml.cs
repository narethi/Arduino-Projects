using Arduino.Shared.Enums;
using System.Windows;

namespace EpaperUI.View.EPaperControls
{
    /// <summary>
    /// Interaction logic for SleepModeControl.xaml
    /// </summary>
    public partial class SetSleepModeControl : PropertyPanelControl
    {
        public SetSleepModeControl()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            RaiseSetModeEvent(DisplayMode.Sleep);
        }
    }
}
