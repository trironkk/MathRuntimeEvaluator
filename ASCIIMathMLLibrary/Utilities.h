#ifndef UTILITIES
#define UTILITIES

#include <string>
#include <ctype.h>
#include <sstream>

namespace ASCIIMathMLLibrary
{
	bool isDouble(const std::string& str);
	double toDouble(const std::string& str);

}

#endif