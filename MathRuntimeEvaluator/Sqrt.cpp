#include "Sqrt.h"

#include <cmath>

#include "Exception.h"

using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a string representation of this Operator
	const string& Sqrt::GetIdentifier() const { return *(new string("sqrt")); }

	// Returns a helpful string explaining how to use this Operator
	const string& Sqrt::GetUsage() const
	{
		return *(new string(
"sqrt(x) Square root\n \
\n \
x: the only parameter \n \
returns the square root of x \n \
Notes: \n \
- Does not support negative inputs. \n"));
	}

	// Returns true if this operator is a function
	bool Sqrt::IsFunction() const { return true; }

	// Returns the number of parameters this Operator works with
	int Sqrt::GetParameterCount() const { return 1; }

	// Perform this operation
	double Sqrt::Evaluate(const vector<double>& parameters) const
	{
		if (parameters[0] < 0)
			throw MathRuntimeEvaluatorException(
"sqrt does not support negative inputs."
				);
		return sqrt(parameters[0]);
	}
}