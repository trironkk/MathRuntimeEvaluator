#include "SquareRoot.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	SquareRoot::SquareRoot() {}

	// Performs this operation
	shared_ptr<Expression> SquareRoot::Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters)
	{
		// Get the values of each of the parameters
		shared_ptr<vector<double>> values = GetValuesFromParameters(parameters,
			workingMemory);

		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant(sqrt((*values)[0]))
		);
	}

	// Returns the number of parameters involved in this operation
	int SquareRoot::GetParameterCount()
	{
		return 1;
	}

	// Gets a string representation of this operation
	string SquareRoot::GetStringRepresentation()
	{
		return "sqrt";
	}
}