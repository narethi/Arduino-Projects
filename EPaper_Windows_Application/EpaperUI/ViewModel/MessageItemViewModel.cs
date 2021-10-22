using Arduino.Shared.Enums;
using EpaperUI.Model;
using EpaperUI.Properties;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Windows.Media;

namespace EpaperUI.ViewModel
{
    public class MessageItemViewModel : BaseViewModel
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
                        return Resources.MessageInfoLabel;
                    case MessageTypeCode.Warning:
                        return Resources.MessageWarningLabel;
                    case MessageTypeCode.Error:
                        return Resources.MessageErrorLabel;
                }
                return Resources.MessageUnknownLabel;
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
    }
}
