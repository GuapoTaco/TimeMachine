#pragma once

#include <string>
#include <iostream>
#include <cassert>
#include <fstream>

#include "DefaultPreprocessor.h"

template<typename Preprocessor = DefaultPreprocessor>
class Compiler 
{
public:
	template<typename ForwardIter>
	Compiler(ForwardIter begin, ForwardIter end)
	{
		// read the files into one buffer
		for(; begin != end; ++begin)
		{
			auto fileToRead = *begin;
			
			std::string line;
			std::cout << "Trying to read from file: " << fileToRead << std::endl;
			std::ifstream in_stream(fileToRead);
			assert(in_stream.is_open());
			while(std::getline(in_stream, line))
			{
				source.append(line + '\n');
			}
			
		
		}	
	}
	
	void operator()()
	{
		
	}
	
	std::string source;
};
