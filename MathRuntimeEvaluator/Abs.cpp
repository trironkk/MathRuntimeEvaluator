#include "Abs.h"

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	string Abs::GetIdentifier() const { return "abs"; }

	// Returns a helpful string explaining how to use this Operator
	const string& Abs::GetUsage() const
	{
		return *(new string(
"abs(x) Absolute value \n \
\n \
x: the only parameter \n \
returns the absolute value \n"));
	}

	// Returns the number of parameters this operation works with
	int Abs::GetParameterCount() const { return 1; }

	// Perform this operation
	double Abs::Evaluate(const vector<double>& parameters) const
	{
		return abs(parameters[0]);
	}
}