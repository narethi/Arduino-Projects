using EpaperUI.Model;
using System.Collections.ObjectModel;

namespace EpaperUI.ViewModel
{
    public class MainWindowViewModel : BaseViewModel
    {
        public ObservableCollection<MessageDataContract> Messages { get; set; } = new();
    }
}
