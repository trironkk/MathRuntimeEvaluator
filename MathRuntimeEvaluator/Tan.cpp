#include "Tan.h"

#include <cmath>

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	const string& Tan::GetIdentifier() const { return *(new string("tan")); }

	// Returns a helpful string explaining how to use this Operator
	const string& Tan::GetUsage() const
	{
		return *(new string(
"tan(x) Tangent function \n \
\n \
x: the angle in radians \n \
returns the tangent of an angle \n"));
	}

	// Returns the number of parameters this operation works with
	int Tan::GetParameterCount() const { return 1; }

	// Perform this operation
	double Tan::Evaluate(const vector<double>& parameters) const
	{
		return tan(parameters[0]);
	}
}