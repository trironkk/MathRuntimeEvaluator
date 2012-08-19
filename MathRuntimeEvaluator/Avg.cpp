#include "Avg.h"

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator
	string Average::GetIdentifier() const { return "avg"; }

	// Returns a helpful string explaining how to use this Operator
	string Average::GetUsage() const
	{
		return
"avg(...) Average \n\
\n\
Takes in any number of parameters \n\
returns the sum of all of the parameters \n";
	}

	// Returns the number of parameters this operation works with
	int Average::GetParameterCount() const { return -1; }

	// Perform this operation
	Value& Average::Evaluate(const deque<Value>& parameters) const
	{
		ValidateParameterTypes(parameters);

		double result = 0;
		for (deque<Value>::const_iterator iter = parameters.begin();
			iter != parameters.end();
			iter++)
		{
			result += iter->Number;
		}
		
		result = result / parameters.size();

		return *(new Value(result));
	}
}