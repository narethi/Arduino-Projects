using Arduino.Shared.Enums;
using EpaperUI.ViewModel.EPaperControlViewModels;
using System.Windows;

namespace EpaperUI.View.EPaperControls
{
    /// <summary>
    /// Interaction logic for SetBlocksModeControl.xaml
    /// </summary>
    public partial class SetBlocksModeControl : PropertyPanelControl
    {
        private readonly SetBlocksModeControlViewModel _viewModel = new();
        public SetBlocksModeControl()
        {
            InitializeComponent();
            DataContext = _viewModel;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            RaiseSetModeEvent(DisplayMode.Blocks, _viewModel.SetBlocksVertically);
        }
    }
}
