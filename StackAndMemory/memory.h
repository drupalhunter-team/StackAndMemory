#ifndef MEMORY_H
#define MEMORY_H

#include "memory_abstract.h"

using namespace std;

class memory: public memory_abstract<unsigned int>{
private:
	// Write your code here
	int point;
	unsigned int start_adr;
	const static int size = max_size; //  ќбъ€вл€ть константу вне класса?
public:
	memory(string addr); // Implement constructor that get string containing "address" of first element
	// Write your code here. Body of methods must be placed in memory.cpp file
	unsigned int getValueByAddress(string s) throw (invalid_argument, out_of_range);
	void readNext(string s) throw (invalid_argument, out_of_range, overflow_error); 
};
 
#endif
