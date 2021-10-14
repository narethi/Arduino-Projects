# READ ME
This is the small arduino project that is used to run my desk toy that consists of a set of RGB LEDs with a common ground (the power is amplified by a transistor from the digital signal outputs). 

This controls only 1 LED or a set of LEDs with the same commands (this is really just a bunch of LEDs connected in series).

## What this contains
* Arduino project file
* A couple of classes that are used to manage the LED behaviour

## How it works
Each of the 3 digital outputs are routed to one of the colour leg of the LEDs, one for each of the LEDs in the LED (Red, Green, Blue).
The LEDs do not support PWM through digital write (some do, these ones don't), so the intensity is managed through a sort of longer phase PWM turning them on and off in a set number of micro seconds.

The library contains a few modes (Breath, and solid color mostly)