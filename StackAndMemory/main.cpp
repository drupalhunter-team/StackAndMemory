#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "memory.h"

using namespace std;

int main (int argc, char* argv[]){

	 if (argc != 2) {
		 cout << "Invalid argument count " << argc;
		 return EXIT_FAILURE;
	 }

		 fstream fin(argv[1], fstream::in);
		 string line, addr;
		 fin >> addr;
		 fin.get();

	//NOT ROBUST
	//try{
	//	memory m(addr);
	//	string lex;
	//	while (fin.good() && getline(fin,lex,' '))	m.readNext(lex);
	//}
	//catch(exception &e){
	//	cout << e.what();
	//}
	fin.close();
	return EXIT_SUCCESS;
}
