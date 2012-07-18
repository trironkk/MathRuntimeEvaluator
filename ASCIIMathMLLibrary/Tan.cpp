#include "Tan.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	Tan::Tan() {}

	// Performs this operation
	shared_ptr<Expression> Tan::Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters)
	{
		// Get the values of each of the parameters
		shared_ptr<vector<double>> values = GetValuesFromParameters(parameters,
			workingMemory);

		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant(tan((*values)[0]))
		);
	}

	// Returns the number of parameters involved in this operation
	int Tan::GetParameterCount()
	{
		return 1;
	}

	// Gets a string representation of this operation
	string Tan::GetStringRepresentation()
	{
		return "tan";
	}
}