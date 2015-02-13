#ifndef MEMORY_CPP_
#define MEMORY_CPP_
#include "memory.h"
#include <sstream>


memory::memory(string addr)
{
	
}

unsigned int memory::getValueByAddress(string s) throw (invalid_argument, out_of_range)
{
	//
	return 0;
}



void memory::readNext(string s) throw (invalid_argument, out_of_range, overflow_error)
{

}

unsigned int memory::hex2int (string hex)
{
	unsigned int x;
	std::stringstream ss;
	ss << std::hex << hex;
	ss >> x;
	return x;
}


string memory::int2hex (unsigned int input)
{
	stringstream ss;
	ss << "0x" << std::hex << input;
	return ss.str();
}
#endif MEMORY_CPP_