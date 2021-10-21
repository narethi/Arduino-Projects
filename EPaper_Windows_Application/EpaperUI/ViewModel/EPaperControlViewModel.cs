
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using EpaperUI.EventTypes;

namespace EpaperUI.ViewModel
{
    public class EPaperControlViewModel : BaseViewModel
    {
        public EPaperControlViewModel()
        {
        }

        public event SetModeHandler HandleSetMode;

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
                HandleSetMode?.Invoke(_modeString[_selectedMode]);
                OnPropertyChanged();
            }
        }
    }
}
