#include "Exponentiate.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	Exponentiate::Exponentiate() {}

	// Performs this operation
	shared_ptr<Expression> Exponentiate::Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters)
	{
		// Get the values of each of the parameters
		shared_ptr<vector<double>> values = GetValuesFromParameters(parameters,
			workingMemory);

		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant(pow((*values)[0], (*values)[1]))
		);
	}

	// Returns the number of parameters involved in this operation
	int Exponentiate::GetParameterCount()
	{
		return 2;
	}

	// Gets a string representation of this operation
	string Exponentiate::GetStringRepresentation()
	{
		return "^";
	}
}