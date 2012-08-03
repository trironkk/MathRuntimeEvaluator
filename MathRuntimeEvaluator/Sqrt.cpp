#include "Sqrt.h"

#include <cmath>

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	const string& Sqrt::GetIdentifier() const { return *(new string("sqrt")); }

	// Returns a helpful string explaining how to use this Operator
	const string& Sqrt::GetUsage() const
	{
		return *(new string("sqrt usage string"));
	}

	// Returns true if this operator is a function
	bool Sqrt::IsFunction() const { return true; }

	// Returns the number of parameters this Operator works with
	int Sqrt::GetParameterCount() const { return 1; }

	// Perform this operation
	double Sqrt::Evaluate(const vector<double>& parameters) const
	{
		return sqrt(parameters[0]);
	}
}