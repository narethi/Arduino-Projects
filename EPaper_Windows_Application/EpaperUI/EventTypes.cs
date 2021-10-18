using EpaperUI.Model;
using System;

//Note that I am not making specific overrides of the event args classes or requiring these delegates to keep track of sender
//I find that parctice to provide more data than necessary when handling most events, in cases like routed events or events to be
//called from dynamic objects I do use sender and overrides of EventArgs 
namespace EpaperUI.EventTypes
{
    /// <summary>
    /// This is a delegate intended to be used with a set mode event
    /// </summary>
    /// <param name="mode">This is a string that represents mode that will be used to set the display (Available modes can be seen in the arduino driver)</param>
    public delegate void SetModeHandler(string mode);

    /// <summary>
    /// This is a delegate that is to be used with a show message event
    /// </summary>
    /// <param name="messageData">This is a message contract that contains the data needed for displaying a message in a message control</param>
    public delegate void ShowMessageHandler(MessageDataContract messageData);

    /// <summary>
    /// This is a delegate that is used to handle events that are to handle exceptions when they occur
    /// </summary>
    /// <param name="exception">This is the exception to handle</param>
    public delegate void ProcessExceptionHandler(Exception exception);
}
