using Arduino.Shared.Enums;

namespace EpaperUI.Model
{
    public class MessageDataContract
    {
        public MessageTypeCode MessageType { get; set; }
        public string Message { get; set; }
    }
}
