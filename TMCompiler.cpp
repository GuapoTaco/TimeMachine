#include <iostream>
#include <string>

#include <boost/program_options.hpp>

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
	
	if(options_map.count("help"))
	{
		std::cout << all_options;
		return 1;
	}
	
	std::cout << output_file << std::endl;
	for(const auto& elem : options_map["input"].as<std::vector<std::string>>())
	{
		std::cout << elem << ":";
	}
	std::cout << std::endl;
	
	
}
