#include "Multiply.h"

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	const string& Multiply::GetIdentifier() const { return *(new string("*")); }

	// Returns a helpful string explaining how to use this Operator
	const string& Multiply::GetUsage() const
	{
		return *(new string("multiplication usage string"));
	}

	// Returns true if this operator is +, -, *, or /, and false otherwise
	bool Multiply::IsFunction() const { return true; }

	// Returns the number of parameters this Operator works with
	int Multiply::GetParameterCount() const { return 2; }

	// Returns an integer representing the rank of this Operation
	// Functions:		3
	// Multiplication:	2
	// Division:		2
	// Addition:		1
	// Subtraction:		1
	int Multiply::GetRank() const { return 2; }

	// Perform this operation
	double Multiply::Evaluate(const vector<double>& parameters) const
	{
		return parameters[0] * parameters[1];
	}
}