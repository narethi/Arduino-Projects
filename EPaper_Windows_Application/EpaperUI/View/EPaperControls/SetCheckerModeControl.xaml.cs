using Arduino.Shared.Enums;
using EpaperUI.ViewModel.EPaperControlViewModels;
using System.Windows;

namespace EpaperUI.View.EPaperControls
{
    /// <summary>
    /// Interaction logic for SetCheckerModeControl.xaml
    /// </summary>
    public partial class SetCheckerModeControl : PropertyPanelControl
    {
        private readonly SetRadioModeControlViewModel _viewModel = new();
        public SetCheckerModeControl()
        {
            DataContext = _viewModel;
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            RaiseSetModeEvent(DisplayMode.Checker, _viewModel.ModeValue);
        }
    }
}
