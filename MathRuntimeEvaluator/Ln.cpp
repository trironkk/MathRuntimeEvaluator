#include "Ln.h"

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	const string& Ln::GetIdentifier() const { return *(new string("ln")); }

	// Returns a helpful string explaining how to use this Operator
	const string& Ln::GetUsage() const
	{
		return *(new string(
"ln(x) Natural Logarithm \n \
\n \
x: the only parameter \n \
returns the natural logarithm of x \n"));
	}

	// Returns the number of parameters this operation works with
	int Ln::GetParameterCount() const { return 1; }

	// Perform this operation
	double Ln::Evaluate(const vector<double>& parameters) const
	{
		return log(parameters[0]);
	}
}