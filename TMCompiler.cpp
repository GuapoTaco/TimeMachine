#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cassert>

#include <boost/program_options.hpp>

void preprocess(std::string& in)
{
	// look for comments-- comments are ; or /* */ format
	
	
	// remove the ; comments
	for(std::string::size_type next_semicolon = in.find(';', 0); next_semicolon != std::string::npos; next_semicolon = in.find(';', next_semicolon))
	{
		std::string::size_type next_newline = in.find('\n', next_semicolon);
		in.erase(next_semicolon, next_newline - next_semicolon);
	}
	
	// remove the /**/ comments
	for(std::string::size_type next_start = in.find("/*", 0); next_start != std::string::npos; next_start = in.find("/*", next_start))
	{
		std::string::size_type next_newline = in.find("*/", next_start);
		in.erase(next_start, next_newline - next_start + 2);
	}
	
}

std::vector<char> compile(const std::vector<std::string>& filesToCompile)
{
	std::string in_buffer;
	// read the files into one buffer
	for(const auto& fileToRead : filesToCompile)
	{
		std::string line;
		std::cout << "Trying to read from file: " << fileToRead << std::endl;
		std::ifstream in_stream(fileToRead);
		assert(in_stream.is_open());
		while(std::getline(in_stream, line))
		{
			in_buffer.append(line + '\n');
		}
	}
	// read a line at a time-- one line = one instructon
	preprocess(in_buffer);
	std::cout << in_buffer;
	
	return {};
}

int main(int argc, char **argv) {
	
	std::string output_file;
	
	boost::program_options::options_description general_options("Generic Options");
	general_options.add_options()
		("help", "repeats the help message")
		("version", "repeats the version nubmer")
		("license", "repeats the license")
		;
		
	boost::program_options::options_description io_options("Input/Output options");
	io_options.add_options()
		("input", 		boost::program_options::value<std::vector<std::string>>()->composing(), 			"the input file to compile")
		("output,o", 	boost::program_options::value<std::string>(&output_file)->default_value("out.tmb"), "the output file")
		;
		
	boost::program_options::options_description all_options("All command line options");
	all_options.add(general_options).add(io_options);
	
	boost::program_options::options_description config_file_options("Options that are stored in the config file");
	config_file_options.add(io_options);
	
	boost::program_options::positional_options_description input_positional;
	input_positional.add("input", -1);
	
	boost::program_options::variables_map options_map;
	boost::program_options::store(
		boost::program_options::command_line_parser(argc, argv).options(all_options).positional(input_positional).run(), options_map);
	boost::program_options::notify(options_map);
	
	// if we have a help command, then print the help
	if(options_map.count("help"))
	{
		std::cout << all_options;
		return 1;
	}
	
	compile(options_map["input"].as<std::vector<std::string>>());
	
}
