#include "Log10.h"

#include <cmath>

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator
	string Log10::GetIdentifier() const { return "log10"; }

	// Returns a helpful string explaining how to use this Operator
	string Log10::GetUsage() const
	{
		return
"log10(x) Base 10 Logarithm \n\
\n\
x: the only parameter \n\
returns the base 10 logarithm of x \n";
	}

	// Returns the number of parameters this operation works with
	int Log10::GetParameterCount() const { return 1; }

	// Perform this operation
	double Log10::Evaluate(const deque<double>& parameters) const
	{
		return log10(parameters[0]);
	}
}