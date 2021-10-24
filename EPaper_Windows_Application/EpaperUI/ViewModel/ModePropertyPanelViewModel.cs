using Arduino.Shared.Enums;
using System.Windows;

namespace EpaperUI.ViewModel.EPaperControlViewModels
{
    public class ModePropertyPanelViewModel : BaseViewModel
    {
        private DisplayMode _deviceMode = DisplayMode.Unknown;
        public DisplayMode DeviceMode
        {
            get => _deviceMode;
            set
            {
                _deviceMode = value;
                OnPropertyChanged();
                UpdateControlVisibilityProperties();
            }
        }

        private void UpdateControlVisibilityProperties()
        {
            OnPropertyChanged(nameof(StaticModeControlVisibility));
            OnPropertyChanged(nameof(BlocksModeControlVisibility));
            OnPropertyChanged(nameof(TextModeControlVisibility));
            OnPropertyChanged(nameof(CheckerModeControlVisibility));
        }

        public Visibility StaticModeControlVisibility => DeviceMode == DisplayMode.Static ? Visibility.Visible : Visibility.Collapsed;
        public Visibility BlocksModeControlVisibility => DeviceMode == DisplayMode.Blocks ? Visibility.Visible : Visibility.Collapsed;
        public Visibility TextModeControlVisibility => DeviceMode == DisplayMode.Text ? Visibility.Visible : Visibility.Collapsed;
        public Visibility CheckerModeControlVisibility => DeviceMode == DisplayMode.Checker ? Visibility.Visible : Visibility.Collapsed;
    }
}
