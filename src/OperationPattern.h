#pragma once

#include <vector>
#include <iterator>
#include <cstdint>
#include <utility>
#include <algorithm>

#include <boost/optional.hpp>
#include <boost/hana.hpp>

#include "RegisterPattern.h"
#include "Operations.h"


template<typename... Types>
constexpr auto type_tuple = boost::hana::make_tuple(boost::hana::type_c<Types>...);

template<typename Operations>
uint8_t getBinaryForOp(Operations ops, const std::string& toMatch)
{
	uint8_t ret;
	boost::hana::for_each(ops, [](auto type)
		{
			
		});
}

class OperationPattern 
{
	OperationPattern() = default;
	explicit OperationPattern(std::string parseFrom)
	{
				
		
	}
	
	enum class Flag : uint8_t
	{
		u = 0b00000000,
		l = 0b00000001,
		g = 0b00000010,
		c = 0b00000011,
		z = 0b00000100,
		e = 0b00000101
	};
	
	static constexpr auto operations = type_tuple<
			operations::nop        ,
			operations::copy       ,
			operations::add        ,
			operations::mult       ,
			operations::div        ,
			operations::sub        ,
			operations::inv        ,
			operations::cmp        ,
			operations::jr         ,
			operations::call       ,
			operations::ret        ,
			operations::pow        ,
			operations::rsh        ,
			operations::lsh        ,
			operations::and_       ,
			operations::or_        ,
			operations::xor_       ,
			operations::not_       ,
			operations::in         ,
			operations::out        ,
			operations::pull       ,
			operations::push       ,
			operations::crnz       ,
			operations::exx        ,
			operations::rshiftc    ,
			operations::lshiftc    ,
			operations::rshiftw    ,
			operations::lshiftw 
		>;
    
    
        
	std::string operation;
	Flag flag;
	
	std::vector<RegisterPattern> args;
	
	std::vector<uint8_t> toBinary()
	{
		std::vector<uint8_t> ret;
		
		ret.push_back((uint8_t)operation | (uint8_t)flag);
		
		for(auto& arg : args)
		{
			
            auto argBinary = arg.toBinary();
			std::copy(argBinary.begin(), argBinary.end(), std::back_inserter(ret));
			
		}
		
		return std::move(ret);
	}
};
