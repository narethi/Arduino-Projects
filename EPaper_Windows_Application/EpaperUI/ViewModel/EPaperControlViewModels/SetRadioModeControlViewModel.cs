namespace EpaperUI.ViewModel.EPaperControlViewModels
{
    public class SetRadioModeControlViewModel : BaseViewModel
    {
        private int _modeValue = 1;
        public int ModeValue
        {
            get => _modeValue;
            set
            {
                _modeValue = value;
                OnPropertyChanged();
            }
        }
    }
}
