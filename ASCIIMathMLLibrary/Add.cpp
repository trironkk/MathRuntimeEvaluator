#include "Add.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace ASCIIMathMLLibrary
{
	// Performs this operation
	shared_ptr<Expression> Add::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant(values[0] + values[1])
		);
	}

	// Gets a string representation of this operation
	string& Add::GetStringRepresentation()
	{
		return *(new string("+"));
	}
}