using Arduino.Shared.Enums;
using ArduinoExceptions;
using EpaperUI.Controllers;
using EpaperUI.Model;
using EpaperUI.Properties;
using Moq;
using NUnit.Framework;
using System.Threading;

namespace EpaperUI.Test
{
    public class MessageControllerTests
    {
        private string _deviceCOMPort = "COM8";
        //This is wonky, ideally I wouldn't need to use a variable to keep track of the state of the
        //test run, however I also don't want to expose the the controller methods to be waited on
        //as they are intended to be dispatched and forgotten
        private bool _finished = false;
        private Mock<MessageController> _messageController = new Mock<MessageController>();
        private MessageDataContract _messageToCompare = new MessageDataContract();

        private string _testMessage = "Test";
        private string _messageToBeFormatted = "param 1: {0}, param 2: {1}, param 3: {2}";

        private string parameterOne = "test";
        private string parameterTwo = "TESTING";
        private string parameterThree = "TeStInG";

        private void MockShowMessage(MessageDataContract messageData)
        {
            _messageToCompare = messageData;
            _finished = true;
        }

        [SetUp]
        public void SetUp()
        {
            _messageController.Object.ShowMessage += MockShowMessage;
        }

        [TearDown]
        public void TearDown()
        {
            _messageController.Object.ShowMessage -= MockShowMessage;
        }

        [Test]
        public void GivenFailedToFindDeviceErrorWhenSettingMessageThenInvokeShowMessageWithCorrectMessage()
        {
            _finished = false;
             var failedToFindDeviceException = new DeviceException(SerialErrorCodes.FailedToFindDevice);
            _messageController.Object.SetErrorFromException(failedToFindDeviceException);
            while (!_finished) Thread.Sleep(10);
            Assert.AreEqual(MessageTypeCode.Error, _messageToCompare.MessageType);
            Assert.AreEqual(string.Format(Resources.UnableToFindDevice, _deviceCOMPort) , _messageToCompare.Message);
        }

        [Test]
        public void GivenFailedToGetDeviceStateErrorWhenSettingMessageThenInvokeShowMessageWithCorrectMessage()
        {
            _finished = false;
            var failedToGetDeviceStateException = new DeviceException(SerialErrorCodes.FailedToGetDeviceState);
            _messageController.Object.SetErrorFromException(failedToGetDeviceStateException);
            while (!_finished) Thread.Sleep(10);
            Assert.AreEqual(MessageTypeCode.Error, _messageToCompare.MessageType);
            Assert.AreEqual(string.Format(Resources.UnableToGetDeviceState, _deviceCOMPort), _messageToCompare.Message);
        }

        [Test]
        public void GivenFailedToSetDeviceStateErrorWhenSettingMessageThenInvokeShowMessageWithCorrectMessage()
        {
            _finished = false;
            var failedToSetDeviceStateException = new DeviceException(SerialErrorCodes.FailedToSetDeviceState);
            _messageController.Object.SetErrorFromException(failedToSetDeviceStateException);
            while (!_finished) Thread.Sleep(10);
            Assert.AreEqual(MessageTypeCode.Error, _messageToCompare.MessageType);
            Assert.AreEqual(string.Format(Resources.UnableToSetDeviceState, _deviceCOMPort), _messageToCompare.Message);
        }

        [Test]
        public void GivenFailedToSetDeviceTimeOutErrorWhenSettingMessageThenInvokeShowMessageWithCorrectMessage()
        {
            _finished = false;
            var failedToSetDeviceTimeoutException = new DeviceException(SerialErrorCodes.FailedToSetTimeout);
            _messageController.Object.SetErrorFromException(failedToSetDeviceTimeoutException);
            while (!_finished) Thread.Sleep(10);
            Assert.AreEqual(MessageTypeCode.Error, _messageToCompare.MessageType);
            Assert.AreEqual(string.Format(Resources.UnableToSetTimeout, _deviceCOMPort), _messageToCompare.Message);
        }

        [Test]
        public void GivenFailedToWriteBufferErrorWhenSettingMessageThenInvokeShowMessageWithCorrectMessage()
        {
            _finished = false;
            var failedToWriteDeviceBufferException = new DeviceException(SerialErrorCodes.FailedToWriteBuffer);
            _messageController.Object.SetErrorFromException(failedToWriteDeviceBufferException);
            while (!_finished) Thread.Sleep(10);
            Assert.AreEqual(MessageTypeCode.Error, _messageToCompare.MessageType);
            Assert.AreEqual(string.Format(Resources.UnableToWriteDeviceBuffer, _deviceCOMPort), _messageToCompare.Message);
        }

        [Test]
        public void GivenFailedToReadBufferErrorWhenSettingMessageThenInvokeShowMessageWithCorrectMessage()
        {
            _finished = false;
            var failedToReadDeviceBufferException = new DeviceException(SerialErrorCodes.FailedToReadBuffer);
            _messageController.Object.SetErrorFromException(failedToReadDeviceBufferException);
            while (!_finished) Thread.Sleep(10);
            Assert.AreEqual(MessageTypeCode.Error, _messageToCompare.MessageType);
            Assert.AreEqual(string.Format(Resources.UnableToReadDeviceBuffer, _deviceCOMPort), _messageToCompare.Message);
        }

        [Test]
        public void GivenUnknownErrorWhenSettingMessageThenInvokeShowMessageWithCorrectMessage()
        {
            _finished = false;
            var unknownErrorException = new DeviceException((SerialErrorCodes)(-1));
            _messageController.Object.SetErrorFromException(unknownErrorException);
            while (!_finished) Thread.Sleep(10);
            Assert.AreEqual(MessageTypeCode.Error, _messageToCompare.MessageType);
            Assert.AreEqual(Resources.UnknownError, _messageToCompare.Message);
        }

        [Test]
        public void GivenAnInfoMessageWhenDispatchedThenSetMessageTypeToInfo()
        {
            _finished = false;
            _messageController.Object.SetInfoMessage(_testMessage);
            while (!_finished) Thread.Sleep(10);
            Assert.AreEqual(MessageTypeCode.Info, _messageToCompare.MessageType);
        }

        [Test]
        public void GivenAWarningMessageWhenDispatchedThenSetMessageTypeToWarning()
        {
            _finished = false;
            _messageController.Object.SetWarningMessage(_testMessage);
            while (!_finished) Thread.Sleep(10);
            Assert.AreEqual(MessageTypeCode.Warning, _messageToCompare.MessageType);
        }

        [Test]
        public void GivenAnErrorMessageWhenDispatchedThenSetMessageTypeToError()
        {
            _finished = false;
            _messageController.Object.SetErrorMessage(_testMessage);
            while (!_finished) Thread.Sleep(10);
            Assert.AreEqual(MessageTypeCode.Error, _messageToCompare.MessageType);
        }

        [Test]
        public void GivenAMessageThatContainsParamatersWhenDispatchedThenFormatTheMessage()
        {
            _finished = false;
            _messageController.Object.SetWarningMessage(_messageToBeFormatted, parameterOne, parameterTwo, parameterThree);
            while (!_finished) Thread.Sleep(10);
            Assert.AreEqual(string.Format(_messageToBeFormatted, parameterOne, parameterTwo, parameterThree), _messageToCompare.Message);
        }
    }
}
