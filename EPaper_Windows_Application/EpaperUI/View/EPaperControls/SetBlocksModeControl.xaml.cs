using Arduino.Shared.Enums;
using System.Windows;

namespace EpaperUI.View.EPaperControls
{
    /// <summary>
    /// Interaction logic for SetBlocksModeControl.xaml
    /// </summary>
    public partial class SetBlocksModeControl : PropertyPanelControl
    {
        public SetBlocksModeControl()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            RaiseSetModeEvent(DisplayMode.Blocks);
        }
    }
}
