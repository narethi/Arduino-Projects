using EpaperUI.Model;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace EpaperUI.ViewModel
{
    public class MainWindowViewModel : BaseViewModel
    {
        public ObservableCollection<MessageDataContract> Messages { get; set; } = new();
    }
}
