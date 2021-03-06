#include "Add.h"

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator

	string Add::GetIdentifier() const { return "+"; }

	// Returns a helpful string explaining how to use this Operator
	string Add::GetUsage() const
	{
		return
"x + y Addition \n\
\n\
x: the first parameter \n\
y: the second parameter \n\
returns the sum of x and y \n";
	}

	// Returns true if this operator is a function
	bool Add::IsFunction() const { return false; }

	// Returns the number of parameters this operation works with
	int Add::GetParameterCount() const { return 2; }

	// Returns an integer representing the rank of this Operation
	int Add::GetRank() const { return 1; }

	// Perform this operation
	double Add::Evaluate(const deque<double>& parameters) const
	{
		return parameters[0] + parameters[1];
	}
}