#include "Rand.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Performs this operation
	shared_ptr<Expression> Rand::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		double one = 1.0;
		// Assert the range is an integer value
		if (modf(values[0], &one) != 0.0)
		{
			throw ASCIIMathMLException(
"The specified range must be an integer value."
				);
		}

		// Initialize random seed.
		srand ( time(NULL) );

		// Generate a random number inside range
		int randomNumber = rand() % int(values[0]);

		return shared_ptr<Expression>(
			new Constant(randomNumber)
		);
	}

	// Gets a string representation of this operation
	string& Rand::GetStringRepresentation()
	{
		return *(new string("rand"));
	}
}