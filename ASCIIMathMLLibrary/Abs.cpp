#include "Abs.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace ASCIIMathMLLibrary
{
	// Performs this operation
	shared_ptr<Expression> Abs::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		return shared_ptr<Expression>(
			new Constant(abs(values[0]))
		);
	}

	// Gets a string representation of this operation
	string& Abs::GetStringRepresentation()
	{
		return *(new string("abs"));
	}
}