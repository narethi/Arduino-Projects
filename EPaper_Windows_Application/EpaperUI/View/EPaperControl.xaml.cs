using Arduino.Shared.Enums;
using EpaperUI.ViewModel;
using System.Windows;
using System.Windows.Controls;

namespace EpaperUI.View
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

        #region Routed Events

        // Create a custom routed event by first registering a RoutedEventID
        // This event uses the bubbling routing strategy
        public static readonly RoutedEvent SetModeEvent = EventManager.RegisterRoutedEvent(
            nameof(SetMode), RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(EPaperControl));

        // Provide CLR accessors for the event
        public event RoutedEventHandler SetMode
        {
            add { AddHandler(SetModeEvent, value); }
            remove { RemoveHandler(SetModeEvent, value); }
        }

        // This method raises the Tap event
        void RaiseSetModeEvent(DisplayMode mode, params object[] args)
        {
            SetModeRoutedEventArgs newEventArgs = new SetModeRoutedEventArgs(SetModeEvent)
            {
                Mode = mode,
                Parameters = args
            };
            RaiseEvent(newEventArgs);
        }

        #endregion

        private void ModePropertyPanel_SetMode(object sender, RoutedEventArgs e)
        {
            if(e is SetModeRoutedEventArgs eventArgs)
            {
                RaiseSetModeEvent(eventArgs.Mode, eventArgs.Parameters);
            }
        }
    }
}
