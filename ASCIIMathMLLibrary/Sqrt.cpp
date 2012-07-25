#include "Sqrt.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace ASCIIMathMLLibrary
{
	// Performs this operation
	shared_ptr<Expression> Sqrt::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		// Assert that the value is positive
		if (values[0] < 0)
			throw ASCIIMathMLException(
"sqrt does not support negative numbers."
				);

		return shared_ptr<Expression>(
			new Constant(sqrt(values[0]))
		);
	}

	// Gets a string representation of this operation
	string& Sqrt::GetStringRepresentation()
	{
		return *(new string("sqrt"));
	}
}