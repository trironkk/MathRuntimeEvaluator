#include "Sin.h"

#include <cmath>

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	const string& Sin::GetIdentifier() const { return *(new string("sin")); }

	// Returns a helpful string explaining how to use this Operator
	const string& Sin::GetUsage() const
	{
		return *(new string("sin usage string"));
	}

	// Returns true if this operator is a function
	bool Sin::IsFunction() const { return true; }

	// Returns the number of parameters this Operator works with
	int Sin::GetParameterCount() const { return 1; }

	// Perform this operation
	double Sin::Evaluate(const vector<double>& parameters) const
	{
		return sin(parameters[0]);
	}
}