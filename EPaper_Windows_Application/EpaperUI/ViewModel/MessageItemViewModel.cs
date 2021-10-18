using Arduino.Shared.Enums;
using EpaperUI.Model;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;

namespace EpaperUI.ViewModel
{
    public class MessageItemViewModel : INotifyPropertyChanged
    {
        private MessageDataContract _messageData = new();
        public MessageDataContract MessageData 
        {
            get => _messageData;
            set
            {
                _messageData = value;
                OnPropertyChanged(nameof(BackgroundColour));
                OnPropertyChanged(nameof(MessageString));
                OnPropertyChanged(nameof(MessageLabel));
            }
        }

        public string MessageString
        {
            get => _messageData.Message;
        }

        public string MessageLabel
        {
            get
            {
                switch (_messageData.MessageType)
                {
                    case MessageTypeCode.Info:
                        return "INFO";
                    case MessageTypeCode.Warning:
                        return "WARNING";
                    case MessageTypeCode.Error:
                        return "ERROR";
                }
                return "Unknown";
            }
        }

        public Brush BackgroundColour
        {
            get
            {
                switch (_messageData.MessageType)
                {
                    case MessageTypeCode.Info:
                        return Brushes.Green;
                    case MessageTypeCode.Warning:
                        return Brushes.Yellow;
                    case MessageTypeCode.Error:
                        return Brushes.Red;
                }
                return Brushes.White;
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
