#include "Cos.h"

#include <cmath>

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	const string& Cos::GetIdentifier() const { return *(new string("cos")); }

	// Returns a helpful string explaining how to use this Operator
	const string& Cos::GetUsage() const
	{
		return *(new string(
"cos(x) Cosine function \n \
\n \
x: the angle in radians \n \
returns the cosine of an angle \n"));
	}

	// Returns the number of parameters this operation works with
	int Cos::GetParameterCount() const { return 1; }

	// Perform this operation
	double Cos::Evaluate(const vector<double>& parameters) const
	{
		return cos(parameters[0]);
	}
}