#include "Sum.h"

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator
	string Sum::GetIdentifier() const { return "sum"; }

	// Returns a helpful string explaining how to use this Operator
	string Sum::GetUsage() const
	{
		return
"sum(...) Sum \n\
\n\
Takes in any number of parameters \n\
returns the sum of all of the parameters \n";
	}

	// Returns the number of parameters this operation works with
	int Sum::GetParameterCount() const { return -1; }

	// Perform this operation
	Value& Sum::Evaluate(const deque<Value>& parameters) const
	{
		ValidateParameterTypes(parameters);

		double result = 0;
		for (deque<Value>::const_iterator iter = parameters.begin();
			iter != parameters.end();
			iter++)
		{
			result += iter->Number;
		}

		return *(new Value(result));
	}
}