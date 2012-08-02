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
		return *(new string("addition usage string"));
	}

	// Returns true if this operator is +, -, *, or /, and false otherwise
	bool Add::IsFunction() const { return true; }

	// Returns the number of parameters this Operator works with
	int Add::GetParameterCount() const { return 2; }

	// Returns an integer representing the rank of this Operation
	// Functions:		3
	// Multiplication:	2
	// Division:		2
	// Addition:		1
	// Subtraction:		1
	int Add::GetRank() const { return 1; }

	// Perform this operation
	double Add::Evaluate(const vector<double>& parameters) const
	{
		return parameters[0] + parameters[1];
	}
}