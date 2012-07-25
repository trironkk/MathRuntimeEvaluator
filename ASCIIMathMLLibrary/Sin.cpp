#include "Sin.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace ASCIIMathMLLibrary
{
	// Performs this operation
	shared_ptr<Expression> Sin::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant(sin(values[0]))
		);
	}

	// Gets a string representation of this operation
	string& Sin::GetStringRepresentation()
	{
		return *(new string("sin"));
	}
}