#pragma once

#include <string>
#include <iterator>

class DefaultPreprocessor 
{
public:
	template<typename ForwardIter>
	DefaultPreprocessor(ForwardIter begin, ForwardIter end )
	{
		std::copy(begin, end, std::back_inserter(data));
	}
	
	std::string operator()();
	
	// remove the ; comments
	void removeSemicolonComments();
	
	// remove the /**/ comments
	void removeSlashStarComments();
	
	std::string& getWorkingData()
	{
		return data;
	}
	
private:
	std::string data;
};
