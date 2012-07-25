#include "Log10.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace ASCIIMathMLLibrary
{
	// Performs this operation
	shared_ptr<Expression> Log10::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant(log10(values[0]))
		);
	}

	// Gets a string representation of this operation
	string& Log10::GetStringRepresentation()
	{
		return *(new string("log10"));
	}
}