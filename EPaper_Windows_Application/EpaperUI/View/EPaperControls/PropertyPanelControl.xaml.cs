using Arduino.Shared.Enums;
using System.Windows;
using System.Windows.Controls;

namespace EpaperUI.View.EPaperControls
{
    public class PropertyPanelControl : UserControl
    {
        #region Routed Events

        // Create a custom routed event by first registering a RoutedEventID
        // This event uses the bubbling routing strategy
        public static readonly RoutedEvent SetModeEvent = EventManager.RegisterRoutedEvent(
            nameof(SetMode), RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(PropertyPanelControl));

        // Provide CLR accessors for the event
        public event RoutedEventHandler SetMode
        {
            add { AddHandler(SetModeEvent, value); }
            remove { RemoveHandler(SetModeEvent, value); }
        }

        // This method raises the Tap event
        protected void RaiseSetModeEvent(DisplayMode mode, params object[] args)
        {
            SetModeRoutedEventArgs newEventArgs = new SetModeRoutedEventArgs(SetModeEvent)
            {
                Mode = mode,
                Parameters = args
            };
            RaiseEvent(newEventArgs);
        }

        #endregion
    }
}
