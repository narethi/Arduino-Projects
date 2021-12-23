#include <iostream>
#include "USBDriver.h"

int main()
{
    std::cout << "Starting Test!\n";
    try
    {
        USBDriver test("COM8");
    }
    catch (...)
    {
        std::cout << "Failed to initialize the USB Driver" << std::endl;
    }
}
