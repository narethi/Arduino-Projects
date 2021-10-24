using Arduino.Shared.Enums;
using System.Windows;

namespace EpaperUI.View.EPaperControls
{
    /// <summary>
    /// Interaction logic for SetCheckerModeControl.xaml
    /// </summary>
    public partial class SetCheckerModeControl : PropertyPanelControl
    {
        public SetCheckerModeControl()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            RaiseSetModeEvent(DisplayMode.Checker);
        }
    }
}
