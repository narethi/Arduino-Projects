
using ArduinoDriver;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using ArduinoExceptions;

namespace EpaperUI.ViewModel
{
    public class EPaperControlViewModel : INotifyPropertyChanged
    {
        private readonly Driver arduinoControl;

        public EPaperControlViewModel()
        {
            try
            {
                arduinoControl = new();
            }
            catch (DeviceException e)
            {
                var test = e.ReadError();
            }
        }

        private List<string> _modeString = new List<string>()
        {
            "Text",
            "Blocks",
            "Static"
        };

        public List<string> ModeString 
        { 
            get => _modeString;
            set
            {
                _modeString = value;
            }
        }

        private int _selectedMode = 0;
        public int SelectedMode
        {
            get => _selectedMode;
            set
            {
                _selectedMode = value;
                arduinoControl.SetMode(_modeString[_selectedMode]);
                OnPropertyChanged();
            }
        }

        #region INotifyPropertyChanged Implemenation

        public event PropertyChangedEventHandler PropertyChanged;

        public void OnPropertyChanged([CallerMemberName] string propertyName = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        #endregion
    }
}
