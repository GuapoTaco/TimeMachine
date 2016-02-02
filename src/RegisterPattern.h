#pragma once

#include <iostream>
#include <array>
#include <cstdint>



class RegisterPattern 
{
	
	enum class Register 
	{
		literal = 	0b00000000,
		a = 		0b00100000,
		b = 		0b01000000,
		c = 		0b01100000,
		d = 		0b10000000,
		e = 		0b10100000,
		sp = 		0b11000000,
		bp = 		0b11100000
	};
	Register register;
	bool deref;
	uint8_t timeShift; // cannot be more than 
	int32_t valueToAdd;
	
	std::array<char, 5> toBinary() 
	{
		// make sure it is valid
		if(!timeShift > 0b00001111) {
			throw std::out_of_range("Cannot convert an invalid RegisterPattern to binary. Time shift too large");
		}
		
		std::array<char, 5> ret = {0, 0, 0, 0, 0};
		
		ret[0] = register | ((uint8_t)deref << 4) | timeShift;
		
		ret[1] = (valueToAdd >> 24) & 0xFF;
		ret[2] = (valueToAdd >> 16) & 0xFF;
		ret[3] = (valueToAdd >>  8) & 0xFF;
		ret[4] = valueToAdd & 0xFF;
		
		return ret;
		
	}
};
