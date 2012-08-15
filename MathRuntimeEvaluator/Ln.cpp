#include "Ln.h"

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator
	string Ln::GetIdentifier() const { return "Ln"; }

	// Returns a helpful string explaining how to use this Operator
	string Ln::GetUsage() const
	{
		return
"ln(x) Natural Logarithm \n\
\n\
x: the only parameter \n\
returns the natural logarithm of x \n";
	}

	// Returns the number of parameters this operation works with
	int Ln::GetParameterCount() const { return 1; }

	// Perform this operation
	Value Ln::Evaluate(const deque<Value>& parameters) const
	{
		AssertNoUnassignedVariables(parameters);

		return log(parameters[0].Number);
	}
}