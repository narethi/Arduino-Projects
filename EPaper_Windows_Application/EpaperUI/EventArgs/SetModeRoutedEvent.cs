using Arduino.Shared.Enums;
using System.Windows;

namespace EpaperUI
{
    public class SetModeRoutedEventArgs : RoutedEventArgs
    {
        public DisplayMode Mode { get; set; }
        public object[] Parameters { get; set; }
        public SetModeRoutedEventArgs(RoutedEvent routedEvent) : base(routedEvent)
        {

        }
    }
}
