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
		return *(new string(
"x / y Division \n \
\n \
x: the first parameter \n \
y: the second parameter \n \
returns the result of x divided by y \n"));
	}

	// Returns true if this operator is a function
	bool Divide::IsFunction() const { return false; }

	// Returns the number of parameters this operation works with
	int Divide::GetParameterCount() const { return 2; }
		
	// Returns an integer representing the rank of this Operation
	int Divide::GetRank() const { return 2; }

	// Perform this operation
	double Divide::Evaluate(const vector<double>& parameters) const
	{
		return parameters[0] / parameters[1];
	}
}