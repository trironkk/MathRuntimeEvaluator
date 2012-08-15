#include "Pow.h"

#include <cmath>

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator
	string Pow::GetIdentifier() const { return "pow"; }

	// Returns a helpful string explaining how to use this Operator
	string Pow::GetUsage() const
	{
		return
"pow(x,y) Exponentiation \n\
\n\
x: the first parameter \n\
y: the second parameter \n\
returns x raised to the y power \n";
	}

	// Returns the number of parameters this operation works with
	int Pow::GetParameterCount() const { return 2; }

	// Perform this operation
	Value Pow::Evaluate(const deque<Value>& parameters) const
	{
		AssertNoUnassignedVariables(parameters);

		return pow(parameters[0].Number, parameters[1].Number);
	}
}