#include "Mod.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Performs this operation
	shared_ptr<Expression> Mod::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		return shared_ptr<Expression>(
			new Constant(fmod(values[0], values[1]))
		);
	}

	// Gets a string representation of this operation
	string& Mod::GetStringRepresentation()
	{
		return *(new string("mod"));
	}
}