using Arduino.Shared.Enums;
using EpaperUI.ViewModel;
using EpaperUI.ViewModel.EPaperControlViewModels;
using System.Windows;

namespace EpaperUI.View.EPaperControls
{
    /// <summary>
    /// Interaction logic for SetTextModeControl.xaml
    /// </summary>
    public partial class SetTextModeControl : PropertyPanelControl
    {
        private readonly SetTextModeControlViewModel _viewModel = new();
        public SetTextModeControl()
        {
            DataContext = _viewModel;
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            RaiseSetModeEvent(DisplayMode.Text, _viewModel.TextToWrite);
        }
    }
}
