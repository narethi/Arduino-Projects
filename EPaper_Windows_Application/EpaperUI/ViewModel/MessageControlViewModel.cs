﻿using EpaperUI.Model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace EpaperUI.ViewModel
{
    public class MessageControlViewModel : INotifyPropertyChanged
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

        #region INotifyPropertyChanged Implemenation

        public event PropertyChangedEventHandler PropertyChanged;

        public void OnPropertyChanged([CallerMemberName] string propertyName = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        #endregion
    }
}
