#ifndef UTILITIES
#define UTILITIES

#include <string>
#include <ctype.h>
#include <sstream>

namespace ASCIIMathMLLibrary
{
	bool IsDouble(const std::string& str);
	double ToDouble(const std::string& str);

}

#endif