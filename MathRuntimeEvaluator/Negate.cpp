#include "Negate.h"

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	const string& Negate::GetIdentifier() const { return *(new string("~")); }

	// Returns a helpful string explaining how to use this Operator
	const string& Negate::GetUsage() const
	{
		return *(new string("negation usage string"));
	}

	// Returns true if this operator is a function
	bool Negate::IsFunction() const { return false; }

	// Returns the number of parameters this Operator works with
	int Negate::GetParameterCount() const { return 1; }

	// Returns an integer representing the rank of this Operation
	int Negate::GetRank() const { return 3; }

	// Perform this operation
	double Negate::Evaluate(const vector<double>& parameters) const
	{
		return -parameters[0];
	}
}