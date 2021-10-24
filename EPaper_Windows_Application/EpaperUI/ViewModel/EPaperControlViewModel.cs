
using System.Collections.Generic;
using Arduino.Shared.Enums;

namespace EpaperUI.ViewModel
{
    public class EPaperControlViewModel : BaseViewModel
    {
        public EPaperControlViewModel()
        {
        }

        private List<string> _modeString = new List<string>()
        {
            "Text",
            "Blocks",
            "Static",
            "Checkers",
            "Sleep"
        };

        public List<string> ModeString 
        { 
            get => _modeString;
            set
            {
                _modeString = value;
            }
        }

        private DisplayMode _deviceMode = DisplayMode.Unknown;
        public DisplayMode DeviceMode
        {
            get => _deviceMode;
            set
            {
                _deviceMode = value;
                OnPropertyChanged();
            }
        }

        private int _selectedMode = 0;
        public int SelectedMode
        {
            get => _selectedMode;
            set
            {
                _selectedMode = value;
                var modeString = _modeString[_selectedMode];
                switch(modeString)
                {
                    case "Text":
                        DeviceMode = DisplayMode.Text;
                        break;
                    case "Blocks":
                        DeviceMode = DisplayMode.Blocks;
                        break;
                    case "Static":
                        DeviceMode = DisplayMode.Static;
                        break;
                    case "Checkers":
                        DeviceMode = DisplayMode.Checker;
                        break;
                    case "Sleep":
                        DeviceMode = DisplayMode.Sleep;
                        break;
                    default:
                        DeviceMode = DisplayMode.Unknown;
                        break;
                }
                OnPropertyChanged();
            }
        }
    }
}
