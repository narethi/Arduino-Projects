using System.Windows;

namespace EpaperUI
{
    public class SetModeRoutedEventArgs : RoutedEventArgs
    {
        public string Mode { get; set; }
        public SetModeRoutedEventArgs(RoutedEvent routedEvent) : base(routedEvent)
        {

        }
    }
}
