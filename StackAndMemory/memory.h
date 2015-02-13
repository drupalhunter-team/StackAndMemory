#ifndef MEMORY_H
#define MEMORY_H

#include "memory_abstract.h"
#include <stack>

using namespace std;

class memory: public memory_abstract<unsigned int>{
private:

	int pointer_to_free_memory;

	//Стек, отслеживающий блоки {}.
	stack<int> executive_stack;
	unsigned int start_address;

	//Перевод 16го числа из строки в число
	unsigned int hex2int (string hex);

	//Перевод числа в строку в 16ой системе
	string int2hex (unsigned int input);

	//Проверка строки на соответствие 16ому числу
	bool isHex(string hex);
	

public:
	memory(string addr); // Implement constructor that get string containing "address" of first element
	// Write your code here. Body of methods must be placed in memory.cpp file
	unsigned int getValueByAddress(string s) throw (invalid_argument, out_of_range);
	void readNext(string s) throw (invalid_argument, out_of_range, overflow_error); 
};
 
#endif
