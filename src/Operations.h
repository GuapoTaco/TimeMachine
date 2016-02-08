#pragma once

#include <string>
#include <boost/hana/string.hpp>

namespace operations {

using namespace boost::hana::literals;

struct nop {
	static constexpr auto pattern = "nop"_s;
	
	static constexpr uint8_t binary = 0b00000000;
};

struct copy {
	static constexpr auto pattern = "copy"_s;
	
	static constexpr uint8_t binary = 0b00001000;
};

struct add {
	static constexpr auto pattern = "add"_s;
	
	static constexpr uint8_t binary = 0b00010000;
};

struct mult {
	static constexpr auto pattern = "mult"_s;
	
	static constexpr uint8_t binary = 0b00011000;
};

struct div {
	static constexpr auto pattern = "div"_s;
	
	static constexpr uint8_t binary = 0b00100000;
};

struct sub {
	static constexpr auto pattern = "sub"_s;
	
	static constexpr uint8_t binary = 0b00101000;
};

struct inv {
	static constexpr auto pattern = "inv"_s;
	
	static constexpr uint8_t binary = 0b00110000;
};

struct cmp {
	static constexpr auto pattern = "cmp"_s;
	
	static constexpr uint8_t binary = 0b00111000;
};

struct jr {
	static constexpr auto pattern = "jr"_s;
	
	static constexpr uint8_t binary = 0b01000000;
};

struct call {
	static constexpr auto pattern = "call"_s;
	
	static constexpr uint8_t binary = 0b01001000;
};

struct ret {
	static constexpr auto pattern = "ret"_s;
	
	static constexpr uint8_t binary = 0b01010000;
};

struct pow {
	static constexpr auto pattern = "pow"_s;
	
	static constexpr uint8_t binary = 0b01011000;
};

struct rsh {
	static constexpr auto pattern = "rsh"_s;
	
	static constexpr uint8_t binary = 0b01100000;
};

struct lsh {
	static constexpr auto pattern = "lsh"_s;
	
	static constexpr uint8_t binary = 0b01101000;
};

struct and_ {
	static constexpr auto pattern = "and"_s;
	
	static constexpr uint8_t binary = 0b01110000;
};

struct or_ {
	static constexpr auto pattern = "or"_s;
	
	static constexpr uint8_t binary = 0b01111000;
};

struct xor_ {
	static constexpr auto pattern = "xor"_s;
	
	static constexpr uint8_t binary = 0b10000000;
};

struct not_ {
	static constexpr auto pattern = "not"_s;
	
	static constexpr uint8_t binary = 0b10001000;
};

struct in {
	static constexpr auto pattern = "in"_s;
	
	static constexpr uint8_t binary = 0b10010000;
};

struct out {
	static constexpr auto pattern = "out"_s;
	
	static constexpr uint8_t binary = 0b10011000;
};

struct pull {
	static constexpr auto pattern = "pull"_s;
	
	static constexpr uint8_t binary = 0b10100000;
};

struct push {
	static constexpr auto pattern = "push"_s;
	
	static constexpr uint8_t binary = 0b10101000;
};

struct crnz {
	static constexpr auto pattern = "crnz"_s;
	
	static constexpr uint8_t binary = 0b10110000;
};

struct exx {
	static constexpr auto pattern = "exx"_s;
	
	static constexpr uint8_t binary = 0b10111000;
};

struct rshiftc {
	static constexpr auto pattern = "rshiftc"_s;
	
	static constexpr uint8_t binary = 0b11000000;
};

struct lshiftc {
	static constexpr auto pattern = "lshiftc"_s;
	
	static constexpr uint8_t binary = 0b01011000;
};

struct rshiftw {
	static constexpr auto pattern = "rshiftw"_s;
	
	static constexpr uint8_t binary = 0b11010000;
};

struct lshiftw {
	static constexpr auto pattern = "lshiftw"_s;
	
	static constexpr uint8_t binary = 0b11011000;
};

struct end {
	static constexpr auto pattern = "end"_s;
	
	static constexpr uint8_t binary = 0b11111000;
};

}
