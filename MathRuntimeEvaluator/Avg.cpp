#include "Avg.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Performs this operation
	shared_ptr<Expression> Avg::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		// Assert that the number of parameters is greater than zero
		if (values.size() == 0)
			throw ASCIIMathMLException(
"Cannot compute the average of zero terms."
				);

		double sum = 0;
		for (int i = 0; i < values.size(); i++)
		{
			sum += values[i];
		}

		return shared_ptr<Expression>(
			new Constant(sum / values.size())
		);
	}

	// Gets a string representation of this operation
	string& Avg::GetStringRepresentation()
	{
		return *(new string("avg"));
	}
}