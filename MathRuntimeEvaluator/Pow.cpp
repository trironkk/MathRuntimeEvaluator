#include "Pow.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Performs this operation
	shared_ptr<Expression> Pow::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		return shared_ptr<Expression>(
			new Constant(pow(values[0], values[1]))
		);
	}

	// Gets a string representation of this operation
	string& Pow::GetStringRepresentation()
	{
		return *(new string("+"));
	}
}