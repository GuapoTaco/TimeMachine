#pragma once

#include <vector>
#include <cstdint>

#include <boost/optional.hpp>

#include "RegisterPattern.h"


class Operation 
{
	
	enum class Flag : uint8_t
	{
		u = 0b00000000,
		l = 0b00000001,
		g = 0b00000010,
		c = 0b00000011,
		z = 0b00000100,
		e = 0b00000101
	};
	
	enum class Operation : uint8_t 
	{
	
	Operation operation;
	Flag flag;
	
	boost::optional<RegisterPattern> arg1;
	boost::optional<RegisterPattern> arg2;
	boost::optional<RegisterPattern> arg3;
	
	std::vector<uint8_t> toBinary()
	{
		std::vector<uint8_t> ret;
		
		ret.push_back((uint8_t)operation | (uint8_t)flag);
		
		if(arg1)
		{
			ret.
		}
	}
		nop = 		0b00000000,
		copy = 		0b00001000,
		add = 		0b00010000,
		mult = 		0b00011000,
		div = 		0b00100000,
		sub = 		0b00101000,
		inv = 		0b00110000,
		cmp = 		0b00111000,
		jr = 		0b01000000,
		call = 		0b01001000,
		ret = 		0b01010000,
		pow = 		0b01011000,
		rsh = 		0b01100000,
		lsh = 		0b01101000,
		and_ = 		0b01110000,
		or_ = 		0b01111000,
		xor_ = 		0b10000000,
		not_ = 		0b10001000,
		in = 		0b10010000,
		out = 		0b10011000,
		pull = 		0b10100000,
		push = 		0b10101000,
		crnz = 		0b10110000,
		exx = 		0b10111000,
		rshiftc = 	0b11000000,
		lshiftc = 	0b11001000,
		rshiftw = 	0b11010000,
		lshiftw = 	0b11011000,
		
		
		end = 		0b11111000,
	}
};
