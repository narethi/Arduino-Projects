using EpaperUI.Model;
using EpaperUI.ViewModel;
using System.Collections.ObjectModel;
using System.Windows;
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

        public static readonly DependencyProperty MessagesProperty = 
            DependencyProperty.Register(nameof(Messages), 
            typeof(ObservableCollection<MessageDataContract>),
            typeof(MessageControl), new FrameworkPropertyMetadata() { PropertyChangedCallback =  OnDependencyPropertyChanged }
        );

        public ObservableCollection<MessageDataContract> Messages
        {
            get => (ObservableCollection<MessageDataContract>)GetValue(MessagesProperty);
            set => SetValue(MessagesProperty, value);
        }

        private static void OnDependencyPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            if(d is MessageControl control)
            {
                if(e.Property.Name == nameof(Messages))
                {
                    control._viewModel.Messages = (ObservableCollection<MessageDataContract>)e.NewValue;
                }
            }
        }
    }
}
