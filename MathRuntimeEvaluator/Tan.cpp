#include "Tan.h"

#include <cmath>

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator
	string Tan::GetIdentifier() const { return "tan"; }

	// Returns a helpful string explaining how to use this Operator
	string Tan::GetUsage() const
	{
		return
"tan(x) Tangent function \n\
\n\
x: the angle in radians \n\
returns the tangent of an angle \n";
	}

	// Returns the number of parameters this operation works with
	int Tan::GetParameterCount() const { return 1; }

	// Perform this operation
	Value Tan::Evaluate(const deque<Value>& parameters) const
	{
		AssertNoUnassignedVariables(parameters);
		return tan(parameters[0].Number);
	}
}