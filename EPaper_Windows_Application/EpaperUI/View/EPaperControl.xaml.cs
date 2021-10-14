using EpaperUI.ViewModel;
using System;
using System.Windows.Controls;

namespace EpaperUI.Views
{
    /// <summary>
    /// Interaction logic for EPaperControl.xaml
    /// </summary>
    public partial class EPaperControl : UserControl
    {
        private readonly EPaperControlViewModel _viewModel = new();
        public EPaperControl()
        {
            DataContext = _viewModel;
            InitializeComponent();
        }
    }
}
