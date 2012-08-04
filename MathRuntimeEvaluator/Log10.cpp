#include "Log10.h"

#include <cmath>

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	const string& Log10::GetIdentifier() const { return *(new string("log10")); }

	// Returns a helpful string explaining how to use this Operator
	const string& Log10::GetUsage() const
	{
		return *(new string(
"log10(x) Base 10 Logarithm \n\
\n\
x: the only parameter \n\
returns the base 10 logarithm of x \n"));
	}

	// Returns the number of parameters this operation works with
	int Log10::GetParameterCount() const { return 1; }

	// Perform this operation
	double Log10::Evaluate(const vector<double>& parameters) const
	{
		return log10(parameters[0]);
	}
}