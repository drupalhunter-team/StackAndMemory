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

	unsigned int hex2int (string hex);
	string int2hex (unsigned int input);

public:
	memory(string addr); // Implement constructor that get string containing "address" of first element
	// Write your code here. Body of methods must be placed in memory.cpp file
	unsigned int getValueByAddress(string s) throw (invalid_argument, out_of_range);
	void readNext(string s) throw (invalid_argument, out_of_range, overflow_error); 
};
 
#endif
