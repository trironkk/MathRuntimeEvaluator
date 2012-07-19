#include "Negate.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	Negate::Negate() {}

	// Performs this operation
	shared_ptr<Expression> Negate::Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters)
	{
		// Get the values of each of the parameters
		shared_ptr<vector<double>> values = GetValuesFromParameters(parameters,
			workingMemory);

		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant(-(*values)[0])
		);
	}

	// Gets a string representation of this operation
	string& Negate::GetStringRepresentation()
	{
		return *(new string("-"));
	}
}