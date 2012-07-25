#include "Cos.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace ASCIIMathMLLibrary
{
	// Performs this operation
	shared_ptr<Expression> Cos::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant(cos(values[0]))
		);
	}

	// Gets a string representation of this operation
	string& Cos::GetStringRepresentation()
	{
		return *(new string("cos"));
	}
}