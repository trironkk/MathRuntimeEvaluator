#include "Divide.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	Divide::Divide() {}

	// Performs this operation
	shared_ptr<Expression> Divide::Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters)
	{
		// Get the values of each of the parameters
		shared_ptr<vector<double>> values = GetValuesFromParameters(parameters,
			workingMemory);

		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant((*values)[0] / (*values)[1])
		);
	}

	// Returns the number of parameters involved in this operation
	int Divide::GetParameterCount()
	{
		return 2;
	}

	// Gets a string representation of this operation
	string Divide::GetStringRepresentation()
	{
		return "/";
	}
}