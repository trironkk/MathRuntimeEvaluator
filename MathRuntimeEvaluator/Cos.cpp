#include "Cos.h"

#include <cmath>

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator
	string Cos::GetIdentifier() const { return "cos"; }

	// Returns a helpful string explaining how to use this Operator
	string Cos::GetUsage() const
	{
		return
"cos(x) Cosine function \n\
\n\
x: the angle in radians \n\
returns the cosine of an angle \n";
	}

	// Returns the number of parameters this operation works with
	int Cos::GetParameterCount() const { return 1; }

	// Perform this operation
	Value& Cos::Evaluate(const deque<Value>& parameters) const
	{
		ValidateParameterTypes(parameters);

		return *(new Value(cos(parameters[0].Number)));
	}
}