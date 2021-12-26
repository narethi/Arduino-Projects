#include <iostream>
#include "USBInterface.h"

int main()
{
    std::cout << "Starting Test!\n";
    try
    {
        USBInterface test("COM8");
        std::cout << "Successfully constructed driver\n";
    }
    catch (...)
    {
        std::cout << "Failed to initialize the USB Driver" << std::endl;
    }
}
