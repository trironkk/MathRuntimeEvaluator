#include "Sqrt.h"

#include <cmath>

#include "MathRuntimeEvaluatorException.h"

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator
	string Sqrt::GetIdentifier() const { return "sqrt"; }

	// Returns a helpful string explaining how to use this Operator
	string Sqrt::GetUsage() const
	{
		return
"sqrt(x) Square root\n\
\n\
x: the only parameter \n\
returns the square root of x \n\
Notes: \n\
- Does not support negative inputs. \n";
	}

	// Returns the number of parameters this operation works with
	int Sqrt::GetParameterCount() const { return 1; }

	// Perform this operation
	Value& Sqrt::Evaluate(const deque<Value>& parameters) const
	{
		ValidateParameterTypes(parameters);

		if (parameters[0].Number < 0)
			throw MathRuntimeEvaluatorException(
"sqrt does not support negative inputs."
				);
		return *(new Value(sqrt(parameters[0].Number)));
	}
}