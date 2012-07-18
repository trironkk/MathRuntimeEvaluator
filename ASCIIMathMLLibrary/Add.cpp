#include "Add.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	Add::Add() {}

	// Performs this operation
	shared_ptr<Expression> Add::Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters)
	{
		// Get the values of each of the parameters
		shared_ptr<vector<double>> values = GetValuesFromParameters(parameters,
			workingMemory);

		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant((*values)[0] + (*values)[1])
		);
	}

	// Returns the number of parameters involved in this operation
	int Add::GetParameterCount()
	{
		return 2;
	}

	// Gets a string representation of this operation
	string& Add::GetStringRepresentation()
	{
		return *(new string("+"));
	}
}