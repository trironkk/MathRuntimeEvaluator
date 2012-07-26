#include "Negate.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Performs this operation
	shared_ptr<Expression> Negate::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant(-values[0])
		);
	}

	// Gets a string representation of this operation
	string& Negate::GetStringRepresentation()
	{
		return *(new string("-"));
	}
}