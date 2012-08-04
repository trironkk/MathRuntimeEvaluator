#include "Log2.h"

#include <cmath>

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	const string& Log2::GetIdentifier() const { return *(new string("log2")); }

	// Returns a helpful string explaining how to use this Operator
	const string& Log2::GetUsage() const
	{
		return *(new string(
"log2(x) Binary Logarithm \n \
\n \
x: the only parameter \n \
returns the binary logarithm of x \n"));
	}

	// Returns the number of parameters this operation works with
	int Log2::GetParameterCount() const { return 1; }

	// Perform this operation
	double Log2::Evaluate(const vector<double>& parameters) const
	{
		return log10(parameters[0]) / log10(2.0);
	}
}