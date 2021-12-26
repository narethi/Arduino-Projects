#include <iostream>
#include "UsbDevice.h"

int main()
{
    std::cout << "Starting Test!\n";
    try
    {
        UsbDevice test("COM8");
        std::cout << "Successfully constructed driver\n";
    }
    catch (...)
    {
        std::cout << "Failed to initialize the USB Driver" << std::endl;
    }
}
