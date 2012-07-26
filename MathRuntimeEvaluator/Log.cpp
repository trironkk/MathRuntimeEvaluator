#include "Log.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Performs this operation
	shared_ptr<Expression> Log::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		return shared_ptr<Expression>(
			new Constant((log10(values[1]) / log10(values[0])))
		);
	}

	// Gets a string representation of this operation
	string& Log::GetStringRepresentation()
	{
		return *(new string("log"));
	}
}