#include "Subtract.h"

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	const string& Subtract::GetIdentifier() const { return *(new string("-")); }

	// Returns a helpful string explaining how to use this Operator
	const string& Subtract::GetUsage() const
	{
		return *(new string("subtraction usage string"));
	}

	// Returns true if this operator is a function
	bool Subtract::IsFunction() const { return false; }

	// Returns the number of parameters this Operator works with
	int Subtract::GetParameterCount() const { return 2; }
	
	// Returns an integer representing the rank of this Operation
	int Subtract::GetRank() const { return 1; }

	// Perform this operation
	double Subtract::Evaluate(const vector<double>& parameters) const
	{
		return parameters[0] - parameters[1];
	}
}