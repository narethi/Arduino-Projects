using Arduino.Shared.Enums;
using System.Windows;

namespace EpaperUI.View.EPaperControls
{
    /// <summary>
    /// Interaction logic for SetStaticModeControl.xaml
    /// </summary>
    public partial class SetStaticModeControl : PropertyPanelControl
    {
        public SetStaticModeControl()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            RaiseSetModeEvent(DisplayMode.Static);
        }
    }
}
