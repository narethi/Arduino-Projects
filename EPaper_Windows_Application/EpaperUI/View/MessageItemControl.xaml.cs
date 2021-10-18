using EpaperUI.Model;
using EpaperUI.ViewModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace EpaperUI.View
{
    /// <summary>
    /// Interaction logic for MessageItem.xaml
    /// </summary>
    public partial class MessageItemControl : UserControl
    {
        private MessageItemViewModel _viewModel = new();
        public MessageItemControl()
        {
            InitializeComponent();
            DataContext = _viewModel;
        }

        public static readonly DependencyProperty MessageDataProperty =
            DependencyProperty.Register(nameof(MessageData),
            typeof(MessageDataContract),
            typeof(MessageItemControl), new FrameworkPropertyMetadata() { PropertyChangedCallback = OnDependencyPropertyChanged }
        );

        public MessageDataContract MessageData
        {
            get => (MessageDataContract)GetValue(MessageDataProperty);
            set => SetValue(MessageDataProperty, value);
        }

        private static void OnDependencyPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            if (d is MessageItemControl control)
            {
                if (e.Property.Name == nameof(MessageData))
                {
                    control._viewModel.MessageData = (MessageDataContract)e.NewValue;
                }
            }
        }
    }
}
