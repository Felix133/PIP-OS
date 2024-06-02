//Example use of PCF8574

#include "pcf8574.h"
#include <bitset>
#include <iostream>

main(){

	//instantiate a new PCF8574 object.
	//on my machine, the i2c bus I want to talk to can be accessed via /dev/i2c-1.
	//the pcf8574 chip I want to talk to is at address 32 (0x20).
	//this is merely an example.
	//be exceptionally careful when experimenting. see license
	PCF8574 * device;
	device = new PCF8574("/dev/i2c-11", 0x20);
	//device will be set to 0xff by default, which activates the internal pullups
	//this is the correct state for reading
	
	//read a byte from device
	int last = device->getByte();

  while (true)
  {
    int now = device->getByte();
    if (now != last)
    {
      std::bitset<8> x(now);
      std::cout << x << '\n';
      
    }
    last = now;
  }

	//it may be wise to activate the internal pullups before deleting the object
	//the default destructor does not do this, for flexibility
	device->setByte(0xff);
	delete device;
}