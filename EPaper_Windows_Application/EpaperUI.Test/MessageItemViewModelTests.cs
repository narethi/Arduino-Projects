using EpaperUI.ViewModel;
using NUnit.Framework;
using EpaperUI.Properties;
using System;
using System.Linq;
using System.Windows.Media;

namespace EpaperUI.Test
{
    public class MessageItemViewModelTests
    {
        [Test]
        public void GivenMessageTypeInfoWhenDisplayingThenPrintInfoLabel()
        {
            var data = new MessageItemViewModel();
            data.MessageData = new Model.MessageDataContract() 
            { 
                MessageType = Arduino.Shared.Enums.MessageTypeCode.Info 
            };
            Assert.AreEqual(Resources.MessageInfoLabel, data.MessageLabel);
        }

        [Test]
        public void GivenMessageTypeWarningWhenDisplayingThenPrintWarningLabel()
        {
            var data = new MessageItemViewModel();
            data.MessageData = new Model.MessageDataContract()
            {
                MessageType = Arduino.Shared.Enums.MessageTypeCode.Warning
            };
            Assert.AreEqual(Resources.MessageWarningLabel, data.MessageLabel);
        }

        [Test]
        public void GivenMessageTypeErrorWhenDisplayingThenPrintErrorLabel()
        {
            var data = new MessageItemViewModel();
            data.MessageData = new Model.MessageDataContract()
            {
                MessageType = Arduino.Shared.Enums.MessageTypeCode.Error
            };
            Assert.AreEqual(Resources.MessageErrorLabel, data.MessageLabel);
        }

        [Test]
        public void GivenInvalidMessageTypeWhenDisplayingThenPrintUnknownLabel()
        {
            var data = new MessageItemViewModel();
            var totalMessageTypes = Enum.GetValues(typeof(Arduino.Shared.Enums.MessageTypeCode)).Cast<int>().Max() + 1;
            data.MessageData = new Model.MessageDataContract()
            {
                MessageType = (Arduino.Shared.Enums.MessageTypeCode)(totalMessageTypes)
            };
            Assert.AreEqual(Resources.MessageUnknownLabel, data.MessageLabel);
            totalMessageTypes = Enum.GetValues(typeof(Arduino.Shared.Enums.MessageTypeCode)).Cast<int>().Min() - 1;
            data.MessageData.MessageType = (Arduino.Shared.Enums.MessageTypeCode)(totalMessageTypes);
            Assert.AreEqual(Resources.MessageUnknownLabel, data.MessageLabel);
        }

        [Test]
        public void GivenMessageTypeInfoWhenDisplayingThenUseGreenLabelHighlight()
        {
            var data = new MessageItemViewModel();
            data.MessageData = new Model.MessageDataContract()
            {
                MessageType = Arduino.Shared.Enums.MessageTypeCode.Info
            };
            Assert.AreEqual(Brushes.Green, data.BackgroundColour);
        }
        [Test]
        public void GivenMessageTypeWarningWhenDisplayingThenUseYellowLabelHighlight()
        {
            var data = new MessageItemViewModel();
            data.MessageData = new Model.MessageDataContract()
            {
                MessageType = Arduino.Shared.Enums.MessageTypeCode.Warning
            };
            Assert.AreEqual(Brushes.Yellow, data.BackgroundColour);
        }

        [Test]
        public void GivenMessageTypeErrorWhenDisplayingThenUseRedLabelHighlight()
        {
            var data = new MessageItemViewModel();
            data.MessageData = new Model.MessageDataContract()
            {
                MessageType = Arduino.Shared.Enums.MessageTypeCode.Error
            };
            Assert.AreEqual(Brushes.Red, data.BackgroundColour);
        }

        [Test]
        public void GivenMessageTypeErrorWhenDisplayingThenUseWhiteLabelHighlight()
        {
            var data = new MessageItemViewModel();
            var totalMessageTypes = Enum.GetValues(typeof(Arduino.Shared.Enums.MessageTypeCode)).Cast<int>().Max() + 1;
            data.MessageData = new Model.MessageDataContract()
            {
                MessageType = (Arduino.Shared.Enums.MessageTypeCode)(totalMessageTypes)
            };
            Assert.AreEqual(Brushes.White, data.BackgroundColour);
            totalMessageTypes = Enum.GetValues(typeof(Arduino.Shared.Enums.MessageTypeCode)).Cast<int>().Min() - 1;
            data.MessageData.MessageType = (Arduino.Shared.Enums.MessageTypeCode)(totalMessageTypes);
            Assert.AreEqual(Brushes.White, data.BackgroundColour);
        }
    }
}
