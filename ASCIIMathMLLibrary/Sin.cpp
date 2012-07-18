#include "Sin.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	Sin::Sin() {}

	// Performs this operation
	shared_ptr<Expression> Sin::Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters)
	{
		// Get the values of each of the parameters
		shared_ptr<vector<double>> values = GetValuesFromParameters(parameters,
			workingMemory);

		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant(sin((*values)[0]))
		);
	}

	// Returns the number of parameters involved in this operation
	int Sin::GetParameterCount()
	{
		return 1;
	}

	// Gets a string representation of this operation
	string& Sin::GetStringRepresentation()
	{
		return *(new string("sin"));
	}
}