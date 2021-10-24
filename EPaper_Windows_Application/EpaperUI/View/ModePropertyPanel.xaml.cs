using Arduino.Shared.Enums;
using EpaperUI.ViewModel.EPaperControlViewModels;
using System.Windows;
using System.Windows.Controls;

namespace EpaperUI.View
{
    /// <summary>
    /// Interaction logic for ModePropertyPanel.xaml
    /// </summary>
    public partial class ModePropertyPanel : UserControl
    {
        private readonly ModePropertyPanelViewModel _viewModel = new();
        public ModePropertyPanel()
        {
            DataContext = _viewModel;
            InitializeComponent();
        }

        #region Dependency Properties

        public static readonly DependencyProperty DeviceModeProperty =
            DependencyProperty.Register(nameof(DeviceMode),
            typeof(DisplayMode),
            typeof(ModePropertyPanel), new FrameworkPropertyMetadata() { PropertyChangedCallback = OnDependencyPropertyChanged }
        );

        public DisplayMode DeviceMode
        {
            get => (DisplayMode)GetValue(DeviceModeProperty);
            set => SetValue(DeviceModeProperty, value);
        }

        private static void OnDependencyPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            if (d is ModePropertyPanel control)
            {
                if (e.Property.Name == nameof(DeviceMode))
                {
                    control._viewModel.DeviceMode = (DisplayMode)e.NewValue;
                }
            }
        }

        #endregion

        #region Routed Events

        // Create a custom routed event by first registering a RoutedEventID
        // This event uses the bubbling routing strategy
        public static readonly RoutedEvent SetModeEvent = EventManager.RegisterRoutedEvent(
            nameof(SetMode), RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(ModePropertyPanel));

        // Provide CLR accessors for the event
        public event RoutedEventHandler SetMode
        {
            add { AddHandler(SetModeEvent, value); }
            remove { RemoveHandler(SetModeEvent, value); }
        }

        // This method raises the Tap event
        protected void RaiseSetModeEvent(DisplayMode mode)
        {
            SetModeRoutedEventArgs newEventArgs = new SetModeRoutedEventArgs(SetModeEvent)
            {
                Mode = mode
            };
            RaiseEvent(newEventArgs);
        }

        #endregion

        private void ModeControl_SetMode(object sender, RoutedEventArgs e)
        {
            if(e is SetModeRoutedEventArgs eventArgs)
            {
                RaiseSetModeEvent(eventArgs.Mode);
            }
        }
    }
}
