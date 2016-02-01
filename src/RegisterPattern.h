#include <iostream>
#include <array>

class RegisterPattern 
{
	uint8_t registerID; // really only 3 bits
	bool deref;
	uint8_t timeShift; // really only 4 bits
	int32_t valueToAdd;
	
	// validates that the the values are within an acceptable range
	bool isValid() 
	{
		return 
			registerID 	<= 0b111 &&
			timeShift 	<= 0b1111;
	}
	
	std::array<char, 5> toBinary() 
	{
		// make sure it is valid
		if(!isValid()) {
			throw std::runtime_error("Cannot convert an invalid RegisterPattern to binary");
		}
		
		std::array<char, 5> ret = {0, 0, 0, 0, 0};
		
		ret[0] |= registerID << 5;
		ret[0] |= (uint8_t) deref << 4;
		ret[0] |= timeShift;
		
		ret[1] = (valueToAdd >> 24) & 0xFF;
		ret[2] = (valueToAdd >> 16) & 0xFF;
		ret[3] = (valueToAdd >>  8) & 0xFF;
		ret[4] = valueToAdd & 0xFF;
		
		return ret;
		
	}
};
