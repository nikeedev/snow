#include <iostream>
#include <string>
#include <fstream>

#include "snow/snow.h"

int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cout << "Snow Compiler - v0.1.0a" << std::endl;
		std::cout << "\nUsage: snow <source file>.snow";
	} else {
		load(argv[1]);
	}
}
