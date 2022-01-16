#include <iostream>
#include "UsbDevice.h"
#include <exception>
#include "UsbDeviceException.h"

int main()
{
    std::cout << "Starting Test!\n";
    try
    {
        UsbDevice test("COM8");
        std::cout << "Successfully constructed driver\n";
        test.CheckDeviceCommState();
        std::cout << "Successfully read the comm state" << std::endl;
        test.WriteDataToDevice("\0", 1);
        std::cout << "Successfully wrote to device" << std::endl;
        const char* buffer;
        size_t dataRead;
        test.ReadDataFromSerialBuffer(buffer, dataRead);
        std::cout << "Successfully read device buffer" << std::endl;
    }
    catch (UsbDeviceException e)
    {
        std::cout << "Failed to complete test, due to error code: " << static_cast<int>(e.ReadError()) << std::endl;
    }
}
