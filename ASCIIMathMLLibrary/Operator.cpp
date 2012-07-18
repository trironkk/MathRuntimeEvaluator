#include "Operator.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	Operator::Operator() {}

	// Calls GetValue() on each of the parameters, and returns a vector of
	// results
	shared_ptr<vector<double>> Operator::GetValuesFromParameters(
		const list<shared_ptr<Expression>>& parameters,
		const WorkingMemory& workingMemory)
	{
		shared_ptr<vector<double>> result(new vector<double>(parameters.size()));

		list<shared_ptr<Expression>>::const_iterator iter = parameters.begin();

		for (unsigned int i = 0; i < parameters.size(); i++, iter++)
		{
			(*(result)).at(i) =
				(*((*(*iter)).Simplify(workingMemory))).GetValue();
		}

		return result;
	}
}