using EpaperUI.Model;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace EpaperUI.ViewModel
{
    public class MainWindowViewModel : INotifyPropertyChanged
    {
        public ObservableCollection<MessageDataContract> Messages { get; set; } = new();

        #region INotifyPropertyChanged Implemenation

        public event PropertyChangedEventHandler PropertyChanged;

        public void OnPropertyChanged([CallerMemberName] string propertyName = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        #endregion
    }
}
