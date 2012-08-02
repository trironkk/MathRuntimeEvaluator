#include "Divide.h"

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	const string& Divide::GetIdentifier() const { return *(new string("/")); }

	// Returns a helpful string explaining how to use this Operator
	const string& Divide::GetUsage() const
	{
		return *(new string("division usage string"));
	}

	// Returns true if this operator is +, -, *, or /, and false otherwise
	bool Divide::IsFunction() const { return true; }

	// Returns the number of parameters this Operator works with
	int Divide::GetParameterCount() const { return 2; }
		
	// Returns an integer representing the rank of this Operation
	// Functions:		3
	// Multiplication:	2
	// Division:		2
	// Addition:		1
	// Subtraction:		1
	int Divide::GetRank() const { return 2; }

	// Perform this operation
	double Divide::Evaluate(const vector<double>& parameters) const
	{
		return parameters[0] / parameters[1];
	}
}