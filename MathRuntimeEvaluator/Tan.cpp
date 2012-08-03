#include "Tan.h"

#include <cmath>

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	const string& Tan::GetIdentifier() const { return *(new string("tan")); }

	// Returns a helpful string explaining how to use this Operator
	const string& Tan::GetUsage() const
	{
		return *(new string("tan usage string"));
	}

	// Returns true if this operator is a function
	bool Tan::IsFunction() const { return true; }

	// Returns the number of parameters this Operator works with
	int Tan::GetParameterCount() const { return 1; }

	// Perform this operation
	double Tan::Evaluate(const vector<double>& parameters) const
	{
		return tan(parameters[0]);
	}
}