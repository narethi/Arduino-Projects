namespace EpaperUI.ViewModel.EPaperControlViewModels
{
    public class SetTextModeControlViewModel : BaseViewModel
    {
        private string _textToWrite = string.Empty;

        public string TextToWrite
        {
            get => _textToWrite;
            set
            {
                _textToWrite = value;
                OnPropertyChanged();
            }
        }
    }
}
