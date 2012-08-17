#include "Divide.h"

#include "MathRuntimeEvaluatorException.h"

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator
	string Divide::GetIdentifier() const { return "/"; }

	// Returns a helpful string explaining how to use this Operator
	string Divide::GetUsage() const
	{
		return
"x / y Division \n\
\n\
x: the first parameter \n\
y: the second parameter \n\
returns the result of x divided by y \n\
Notes: \n\
- Does not support denominators of 0. \n";
	}

	// Returns true if this operator is a function
	bool Divide::IsFunction() const { return false; }

	// Returns the number of parameters this operation works with
	int Divide::GetParameterCount() const { return 2; }
		
	// Returns an integer representing the rank of this Operation
	int Divide::GetRank() const { return 2; }

	// Perform this operation
	Value& Divide::Evaluate(const deque<Value>& parameters) const
	{
		ValidateParameterTypes(parameters);

		if (parameters[1].Number == 0)
			throw MathRuntimeEvaluatorException(
"Cannot divide by zero."
				);
		return *(new Value(parameters[0].Number / parameters[1].Number));
	}
}