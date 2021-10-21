using EpaperUI.Model;
using System.Collections.ObjectModel;

namespace EpaperUI.ViewModel
{
    public class MessageControlViewModel : BaseViewModel
    {
        private ObservableCollection<MessageDataContract> _messages = new();
        public ObservableCollection<MessageDataContract> Messages 
        { 
            get => _messages; 
            set
            {
                _messages = value;
                OnPropertyChanged();
            }
        }
    }
}
