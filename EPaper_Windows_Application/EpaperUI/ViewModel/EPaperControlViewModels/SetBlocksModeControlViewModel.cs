using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EpaperUI.ViewModel.EPaperControlViewModels
{
    public class SetBlocksModeControlViewModel : BaseViewModel
    {
        private bool _setBlocksVertically = false;

        public bool SetBlocksVertically
        {
            get => _setBlocksVertically;
            set
            {
                _setBlocksVertically = value;
                OnPropertyChanged();
            }
        }
    }
}
