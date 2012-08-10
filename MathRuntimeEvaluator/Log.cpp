#include "Log.h"

#include <cmath>

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator
	string Log::GetIdentifier() const { return "log"; }

	// Returns a helpful string explaining how to use this Operator
	string Log::GetUsage() const
	{
		return
"log(x,y) Generic Logarithm \n\
\n\
x: the base of the logarithm \n\
y: the input \n\
returns the base x logarithm of y \n";
	}

	// Returns the number of parameters this operation works with
	int Log::GetParameterCount() const { return 2; }

	// Perform this operation
	double Log::Evaluate(const deque<double>& parameters) const
	{
		return log10(parameters[1]) / log10(parameters[0]);
	}
}