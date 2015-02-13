#ifndef MEMORY_CPP_
#define MEMORY_CPP_
#include "memory.h"
#include <sstream>
#include <iostream>

memory::memory(string addr)
{
	start_address = hex2int(addr);
	pointer_to_free_memory = 0;

}

unsigned int memory::getValueByAddress(string s) throw (invalid_argument, out_of_range)
{
	if (!isHex(s))
		throw invalid_argument("Address is invalid");

	unsigned int address = memory::hex2int(s);

	//»щем адресс в левом стеке.
	for (int i = 0; i < pointer_to_free_memory; i++)
		if (data[i] == address)
			return data[max_size - 1 - i]; 

	throw out_of_range("Address is not available");
}


void memory::readNext(string s) throw (invalid_argument, out_of_range, overflow_error)
{
	std::cout<<s.length();
	if (s[0]=='#')
	{
		//#A или #B
		if (s == "#A")
			data[max_size - 1 - pointer_to_free_memory] ++;
		else if (s == "#B") 
			data[max_size - 1 - pointer_to_free_memory] --;
		else 
			throw invalid_argument("Command is invalid");
	}
	else
	{
		if (s=="{")
		{
			executive_stack.push(pointer_to_free_memory);
		}
		else if (s=="}")
		{
			//ƒанные физические не сотрутс€, но мы будем считать их свободными
			pointer_to_free_memory = executive_stack.top();
			executive_stack.pop();
		}
		else
		{
			//ќбработка чисел и лексем, не €вл€ющихс€ частью €зыка.

			//stol уже порождает исключени€ invalid_argument и out_of_range дл€ long long
			long long check_overflow_ui = stoll (s);
			unsigned int number = (unsigned int)check_overflow_ui;
			std::cout<<endl<<number<<" "<< check_overflow_ui;
			
			//stoll может распарсить первые числа несуществующей команды, поэтому
			//провер€ем, что подали именно число
			if (std::to_string(check_overflow_ui) != s)
				throw invalid_argument ("Command is invalid");


			//ѕровереем out_of_range дл€ unsigned int
			if (number!=check_overflow_ui)
				throw out_of_range("Number is not unsigned int");
			
			//“еперь работаем только с числами
			
			if (max_size - 1 - pointer_to_free_memory <= pointer_to_free_memory)
				throw overflow_error("Stack is overflow");

			//» в стеке достаточно места
			data[pointer_to_free_memory] = start_address + pointer_to_free_memory * sizeof(unsigned int);
			data [max_size - 1 - pointer_to_free_memory] = number;
			pointer_to_free_memory++;

		}
	}
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

bool memory::isHex (string hex)
{
	for (int i = 0; i < hex.length(); i++)
		if (!('0'<=hex[i]&&hex[i]<='9'||'a'<=hex[i]&&hex[i]<='f'||'A'<=hex[i]&&hex[i]<='F'))
			return false;

	return true;
}
#endif MEMORY_CPP_