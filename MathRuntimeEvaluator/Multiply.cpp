#include "Multiply.h"

using std::deque;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	string Multiply::GetIdentifier() const { return "*"; }

	// Returns a helpful string explaining how to use this Operator
	string Multiply::GetUsage() const
	{
		return
"x * y Multiplication \n\
\n\
x: the first parameter \n\
y: the second parameter \n\
returns the product of x and y \n";
	}

	// Returns true if this operator is a function
	bool Multiply::IsFunction() const { return false; }

	// Returns the number of parameters this operation works with
	int Multiply::GetParameterCount() const { return 2; }

	// Returns an integer representing the rank of this Operation
	int Multiply::GetRank() const { return 2; }

	// Perform this operation
	double Multiply::Evaluate(const deque<double>& parameters) const
	{
		return parameters[0] * parameters[1];
	}
}