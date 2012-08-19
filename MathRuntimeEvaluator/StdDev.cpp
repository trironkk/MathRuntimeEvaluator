#include "StdDev.h"

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator
	string StdDev::GetIdentifier() const { return "stddev"; }

	// Returns a helpful string explaining how to use this Operator
	string StdDev::GetUsage() const
	{
		return
"stddev(...) Standard Deviation \n\
\n\
Takes in any number of parameters \n\
returns the standard deviation of all of the parameters \n";
	}

	// Returns the number of parameters this operation works with
	int StdDev::GetParameterCount() const { return -1; }

	// Perform this operation
	Value& StdDev::Evaluate(const deque<Value>& parameters) const
	{
		ValidateParameterTypes(parameters);

		double sum = 0;
		for (deque<Value>::const_iterator iter = parameters.begin();
			iter != parameters.end();
			iter++)
		{
			sum += iter->Number;
		}

		double average = sum / parameters.size();

		double result = 0;
		for (deque<Value>::const_iterator iter = parameters.begin();
			iter != parameters.end();
			iter++)
		{
			result += pow(iter->Number - average, 2);
		}

		result = sqrt(result / parameters.size());

		return *(new Value(result));
	}
}