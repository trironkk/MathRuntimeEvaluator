#include "Add.h"

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	const string& Add::GetIdentifier() const { return *(new string("+")); }

	// Returns a helpful string explaining how to use this Operator
	const string& Add::GetUsage() const
	{
		return *(new string(
"x + y Addition \n \
\n \
x: the first parameter \n \
y: the second parameter \n \
returns the sum of x and y \n"));
	}

	// Returns true if this operator is a function
	bool Add::IsFunction() const { return false; }

	// Returns the number of parameters this Operator works with
	int Add::GetParameterCount() const { return 2; }

	// Returns an integer representing the rank of this Operation
	int Add::GetRank() const { return 1; }

	// Perform this operation
	double Add::Evaluate(const vector<double>& parameters) const
	{
		return parameters[0] + parameters[1];
	}
}