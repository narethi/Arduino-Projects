using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
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
