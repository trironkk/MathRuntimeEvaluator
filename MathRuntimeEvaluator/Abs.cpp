#include "Abs.h"

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator
	string Abs::GetIdentifier() const { return "abs"; }

	// Returns a helpful string explaining how to use this Operator
	string Abs::GetUsage() const
	{
		return
"abs(x) Absolute value \n\
\n\
x: the only parameter \n\
returns the absolute value \n";
	}

	// Returns the number of parameters this operation works with
	int Abs::GetParameterCount() const { return 1; }

	// Perform this operation
	Value& Abs::Evaluate(const deque<Value>& parameters) const
	{
		ValidateParameterTypes(parameters);
		return *(new Value(abs(parameters[0].Number)));
	}
}