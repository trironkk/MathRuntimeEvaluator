#include "Subtract.h"

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	string Subtract::GetIdentifier() const { return "-"; }
	
	// Returns a helpful string explaining how to use this Operator
	string Subtract::GetUsage() const
	{
		return
"x - y Subtraction \n\
\n\
x: the first parameter \n\
y: the second parameter \n\
returns the result of x minus y \n\
\n\
-x Negation \n\
\n\
x: the only parameter \n\
returns the negation of x \n";
	}

	// Returns true if this operator is a function
	bool Subtract::IsFunction() const { return false; }

	// Returns the number of parameters this operation works with
	int Subtract::GetParameterCount() const { return 2; }
	
	// Returns an integer representing the rank of this Operation
	int Subtract::GetRank() const { return 1; }

	// Perform this operation
	double Subtract::Evaluate(const vector<double>& parameters) const
	{
		return parameters[0] - parameters[1];
	}
}