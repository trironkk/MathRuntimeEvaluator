#include "Sin.h"

#include <cmath>

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	string Sin::GetIdentifier() const { return "sin"; }

	// Returns a helpful string explaining how to use this Operator
	const string& Sin::GetUsage() const
	{
		return *(new string(
"sin(x) Sine function \n\
\n\
x: the angle in radians \n\
returns the sine of an angle \n"));
	}

	// Returns the number of parameters this operation works with
	int Sin::GetParameterCount() const { return 1; }

	// Perform this operation
	double Sin::Evaluate(const vector<double>& parameters) const
	{
		return sin(parameters[0]);
	}
}