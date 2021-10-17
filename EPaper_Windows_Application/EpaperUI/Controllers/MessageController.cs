using Arduino.Shared.Enums;
using ArduinoExceptions;
using EpaperUI.EventTypes;
using System;
using System.Threading.Tasks;

namespace EpaperUI.Controllers
{
    public class MessageController
    {
        public event ShowMessageHandler ShowMessage;

        public void SetWarningMessage(string message, params object[] formatOptions)
        {
            throw new NotImplementedException();
        }

        public void SetInfoMessage(string message, params object[] formatOptions)
        {
            throw new NotImplementedException();
        }

        public async void SetErrorMessage(string message, params object[] formatOptions)
        {
            await SetMessage(MessageTypeCode.Error, message, formatOptions);
        }

        public async void SetErrorFromException(Exception exception)
        {
            if(exception is DeviceException deviceException)
            {
                var baseMessage = ConstructMessageStringFromSerialError((SerialErrorCodes)deviceException.ReadError());
                await SetMessage(MessageTypeCode.Error, baseMessage, "COM8");
            }
        }

        private string ConstructMessageStringFromSerialError(SerialErrorCodes error)
        {
            switch(error)
            {
                case SerialErrorCodes.FailedToFindDevice:
                    return "Unable to find device on port {0}";
                case SerialErrorCodes.FailedToGetDeviceState:
                    return "Unable to read the device comm state for the device on port {0}";
                case SerialErrorCodes.FailedToSetDeviceState:
                    return "Unable to update the device comm state on port {0}";
                case SerialErrorCodes.FailedToSetTimeout:
                    return "Unable to set the timeout for the device on port {0}";
                case SerialErrorCodes.FailedToWriteBuffer:
                    return "Unable to write to device on port {0}";
                case SerialErrorCodes.FailedToReadBuffer:
                    return "Unable to read from the device on port {0}";
                default:
                    return "Cannot identify error";
            }
        }

        private async Task SetMessage(MessageTypeCode messageCode, string additionalMessageInformation, params object[] arguments)
        {
            var formattedMessage = string.Format(additionalMessageInformation, arguments);
            await Task.Run(() =>
            {
                ShowMessage?.Invoke(new Model.MessageDataContract() { MessageType = messageCode, Message = formattedMessage });
            });
        }
    }
}
