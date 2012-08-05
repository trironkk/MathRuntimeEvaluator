#include "Pow.h"

#include <cmath>

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	string Pow::GetIdentifier() const { return "pow"; }

	// Returns a helpful string explaining how to use this Operator
	const string& Pow::GetUsage() const
	{
		return *(new string(
"pow(x,y) Exponentiation \n\
\n\
x: the first parameter \n\
y: the second parameter \n\
returns x raised to the y power \n"));
	}

	// Returns the number of parameters this operation works with
	int Pow::GetParameterCount() const { return 2; }

	// Perform this operation
	double Pow::Evaluate(const vector<double>& parameters) const
	{
		return pow(parameters[0], parameters[1]);
	}
}