using Arduino.Shared.Enums;
using EpaperUI.ViewModel.EPaperControlViewModels;
using System.Windows;

namespace EpaperUI.View.EPaperControls
{
    /// <summary>
    /// Interaction logic for SetStaticModeControl.xaml
    /// </summary>
    public partial class SetStaticModeControl : PropertyPanelControl
    {
        private readonly SetRadioModeControlViewModel _viewModel = new();
        public SetStaticModeControl()
        {
            DataContext = _viewModel;
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            RaiseSetModeEvent(DisplayMode.Static, _viewModel.ModeValue);
        }
    }
}
