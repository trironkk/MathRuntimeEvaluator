#include "Log2.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace ASCIIMathMLLibrary
{
	// Performs this operation
	shared_ptr<Expression> Log2::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		return shared_ptr<Expression>(
			new Constant((log10(values[0]) / log10(2.0)))
		);
	}

	// Gets a string representation of this operation
	string& Log2::GetStringRepresentation()
	{
		return *(new string("log2"));
	}
}