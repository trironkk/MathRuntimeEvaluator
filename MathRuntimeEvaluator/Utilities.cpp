#include "Utilities.h"

#include "WorkingMemory.h"

using std::string;
using std::istringstream;
using std::ostringstream;

namespace MathRuntimeEvaluatorNamespace
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

	// Converts an integer value to its string representation
	std::string ToString(int value)
	{
		string Result;
		ostringstream convert;
		convert << value;
		return convert.str();
	}

	// Converts an double value to its string representation
	std::string ToString(double value)
	{
		string Result;
		ostringstream convert;
		convert << value;
		return convert.str();
	}
}