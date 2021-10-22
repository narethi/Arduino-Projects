using Arduino.Shared.Enums;
using ArduinoExceptions;
using EpaperUI.EventTypes;
using EpaperUI.Properties;
using System;
using System.Threading.Tasks;

namespace EpaperUI.Controllers
{
    public class MessageController
    {
        public event ShowMessageHandler ShowMessage;

        public async void SetWarningMessage(string message, params object[] formatOptions)
        {
            await SetMessage(MessageTypeCode.Warning, message, formatOptions);
        }

        public async void SetInfoMessage(string message, params object[] formatOptions)
        {
            await SetMessage(MessageTypeCode.Info, message, formatOptions);
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
                    return Resources.UnableToFindDevice;
                case SerialErrorCodes.FailedToGetDeviceState:
                    return Resources.UnableToGetDeviceState;
                case SerialErrorCodes.FailedToSetDeviceState:
                    return Resources.UnableToSetDeviceState;
                case SerialErrorCodes.FailedToSetTimeout:
                    return Resources.UnableToSetTimeout;
                case SerialErrorCodes.FailedToWriteBuffer:
                    return Resources.UnableToWriteDeviceBuffer;
                case SerialErrorCodes.FailedToReadBuffer:
                    return Resources.UnableToReadDeviceBuffer;
                default:
                    return Resources.UnknownError;
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
