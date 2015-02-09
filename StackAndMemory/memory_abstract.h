#ifndef MEMORY_ABSTRACT_H_
#define MEMORY_ABSTRACT_H_

#include <string>
#include <stdexcept>
using namespace std;

const size_t max_size = 10;

template <class T> class memory_abstract{
protected:
	T data[max_size]; // Array for addresses and values

public:

	// Convert string representation of address to unsigned int, and return value associated with it
	virtual T getValueByAddress(string s) throw (invalid_argument, out_of_range) = 0;
	// Proceed next lexeme from input
	virtual void readNext(string s) throw (invalid_argument, out_of_range, overflow_error) = 0;
	virtual ~memory_abstract(){};

};

#endif
