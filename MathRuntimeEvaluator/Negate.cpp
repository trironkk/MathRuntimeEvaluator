#include "Negate.h"

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator
	string Negate::GetIdentifier() const { return "~"; }

	// Returns a helpful string explaining how to use this Operator
	string Negate::GetUsage() const
	{
		return
"~x Negation \n\
\n\
x: the only parameter \n\
returns the negation of x \n";
	}

	// Returns true if this operator is a function
	bool Negate::IsFunction() const { return false; }

	// Returns the number of parameters this operation works with
	int Negate::GetParameterCount() const { return 1; }

	// Returns an integer representing the rank of this Operation
	int Negate::GetRank() const { return 3; }

	// Perform this operation
	Value Negate::Evaluate(const deque<Value>& parameters) const
	{
		AssertNoUnassignedVariables(parameters);

		return -parameters[0].Number;
	}
}