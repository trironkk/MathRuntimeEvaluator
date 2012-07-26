#include "Utilities.h"

using std::string;
using std::istringstream;

namespace MathRuntimeEvaluator
{
	// Returns true if the string is can be converted to a double, and false
	// otherwise
	bool IsDouble(const string& str)
	{
		char* endptr = 0;
		strtod(str.c_str(), &endptr);

		if(*endptr != '\0' || endptr == str)
			return false;
		return true;
	}

	// Parses a string and returns a double
	double ToDouble(const string& str)
	{
		istringstream i(str);
		double x;
		if (!(i >> x))
			return 0;
		return x;
	}
}