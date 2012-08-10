#ifndef UTILITIES
#define UTILITIES

#include <string>
#include <ctype.h>
#include <sstream>

namespace MathRuntimeEvaluatorNamespace
{
	// Returns true if the string is can be converted to a double, and false
	// otherwise
	bool IsDouble(const std::string& str);

	// Parses a string and returns a double
	double ToDouble(const std::string& str);
}

#endif