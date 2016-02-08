#pragma once

#include <vector>
#include <cstdint>
#include <string>
#include <cctype>
#include <iterator>

#include "OperationPattern.h"

struct DefaultParser {
	
	template<typename Iter>
	Parser(Iter begin, Iter end)
	{
		
	}
	
	std::vector<uint8_t> operator()()
	{
		std::vector<uint8_t> ret;
		
		// parse each line
		for(std::string::size_type pos = 0; pos != inData.size(); pos = inData.find('\n', pos))
		{
			std::string line = inData.substr(pos, inData.find('\n', pos) - pos);
			
			// remove leading whitespace
			while(std::isspace(line[0]))
			{
				line = line.substr(1, inData.size() - 1);
			}
			
			OperationPattern opForLine;
			
			opForLine.parse(opForLine);
			auto binary = opForLine.toBinary();
			
			std::copy(binary.begin(), binary.end(), std::back_inserter(ret));
		}
	}
	
private:
	std::string inData;
	
};
