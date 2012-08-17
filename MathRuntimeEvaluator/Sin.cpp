#include "Sin.h"

#include <cmath>

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator
	string Sin::GetIdentifier() const { return "sin"; }

	// Returns a helpful string explaining how to use this Operator
	string Sin::GetUsage() const
	{
		return
"sin(x) Sine function \n\
\n\
x: the angle in radians \n\
returns the sine of an angle \n";
	}

	// Returns the number of parameters this operation works with
	int Sin::GetParameterCount() const { return 1; }

	// Perform this operation
	Value& Sin::Evaluate(const deque<Value>& parameters) const
	{
		ValidateParameterTypes(parameters);

		return *(new Value(sin(parameters[0].Number)));
	}
}