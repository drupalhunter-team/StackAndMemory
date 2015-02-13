#ifndef MEMORY_CPP_
#define MEMORY_CPP_
#define _CRT_SECURE_NO_WARNINGS
#include "memory.h"


memory::memory(string addr)
{
	memory::point = -1;

	//Тут ждем ошибку, если addr не содержит hex
	//Это не работает
	sscanf(addr.c_str(), "%x", &memory::start_adr); 
	printf("\nstring=%s, decimalValue=%u",addr.c_str(), memory::start_adr);
}

unsigned int memory::getValueByAddress(string s) throw (invalid_argument, out_of_range)
{
	unsigned int ui_addres;

	sscanf(s.c_str(), "%x", &ui_addres); 
	printf("\nstring=%s, decimalValue=%u",s.c_str(), ui_addres);
	//throw invalid argument

	for (int i = 0; i <= memory::point; i++)
		if (ui_addres == memory::data[i])
			return memory::data[memory::size - 1 - i];

	throw out_of_range("Address is not in stack");
}



void memory::readNext(string s) throw (invalid_argument, out_of_range, overflow_error)
{
	int i = 2;
}

#endif MEMORY_CPP_