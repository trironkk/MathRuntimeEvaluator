#include "Tan.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Performs this operation
	shared_ptr<Expression> Tan::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		return shared_ptr<Expression>(
			new Constant(tan(values[0]))
		);
	}

	// Gets a string representation of this operation
	string& Tan::GetStringRepresentation()
	{
		return *(new string("tan"));
	}
}