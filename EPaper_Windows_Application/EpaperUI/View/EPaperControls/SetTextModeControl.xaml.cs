using Arduino.Shared.Enums;
using System.Windows;

namespace EpaperUI.View.EPaperControls
{
    /// <summary>
    /// Interaction logic for SetTextModeControl.xaml
    /// </summary>
    public partial class SetTextModeControl : PropertyPanelControl
    {
        public SetTextModeControl()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            RaiseSetModeEvent(DisplayMode.Text);
        }
    }
}
