#include "DefaultPreprocessor.h"

std::string DefaultPreprocessor::operator()()
{
	removeSemicolonComments();
	removeSlashStarComments();
	
	return data;
}


void DefaultPreprocessor::removeSemicolonComments()
{
	for(std::string::size_type next_semicolon = data.find(';', 0); next_semicolon != std::string::npos; 
		next_semicolon = data.find(';', next_semicolon))
	{
		std::string::size_type next_newline = data.find('\n', next_semicolon);
		data.erase(next_semicolon, next_newline - next_semicolon);
	}
}

void DefaultPreprocessor::removeSlashStarComments()
{
	for(std::string::size_type next_start = data.find("/*", 0); next_start != std::string::npos; 
		next_start = data.find("/*", next_start))
	{
		std::string::size_type next_newline = data.find("*/", next_start);
		data.erase(next_start, next_newline - next_start + 2);
	}
}
