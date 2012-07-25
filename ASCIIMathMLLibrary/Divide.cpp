#include "Divide.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace ASCIIMathMLLibrary
{
	// Performs this operation
	shared_ptr<Expression> Divide::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		// Assert that the the denominator is not zero
		if (values[1] == 0)
			throw ASCIIMathMLException(
"Cannot divide by zero."
				);

		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant(values[0] / values[1])
		);
	}

	// Gets a string representation of this operation
	string& Divide::GetStringRepresentation()
	{
		return *(new string("/"));
	}
}