#ifndef MEMORY_H
#define MEMORY_H

#include "memory_abstract.h"

using namespace std;

class memory: public memory_abstract<unsigned int>{
private:
	// Write your code here

public:
	memory(string addr); // Implement constructor that get string containing "address" of first element
	// Write your code here. Body of methods must be placed in memory.cpp file
};


#endif
