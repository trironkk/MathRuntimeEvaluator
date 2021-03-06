#include "Log2.h"

#include <cmath>

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator
	string Log2::GetIdentifier() const { return "log2"; }

	// Returns a helpful string explaining how to use this Operator
	string Log2::GetUsage() const
	{
		return
"log2(x) Binary Logarithm \n\
\n\
x: the only parameter \n\
returns the binary logarithm of x \n";
	}

	// Returns the number of parameters this operation works with
	int Log2::GetParameterCount() const { return 1; }

	// Perform this operation
	double Log2::Evaluate(const deque<double>& parameters) const
	{
		return log10(parameters[0]) / log10(2.0);
	}
}