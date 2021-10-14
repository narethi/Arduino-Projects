using EpaperUI.ViewModel;
using System.Windows.Controls;

namespace EpaperUI.View
{
    /// <summary>
    /// Interaction logic for MessageControl.xaml
    /// </summary>
    public partial class MessageControl : UserControl
    {
        private readonly MessageControlViewModel _viewModel = new();
        public MessageControl()
        {
            InitializeComponent();
            DataContext = _viewModel;
        }
    }
}
