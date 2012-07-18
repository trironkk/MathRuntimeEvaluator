#include "Subtract.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	Subtract::Subtract() {}

	// Performs this operation
	shared_ptr<Expression> Subtract::Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters)
	{
		// Get the values of each of the parameters
		shared_ptr<vector<double>> values = GetValuesFromParameters(parameters,
			workingMemory);

		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant((*values)[0] - (*values)[1])
		);
	}

	// Returns the number of parameters involved in this operation
	int Subtract::GetParameterCount()
	{
		return 2;
	}

	// Gets a string representation of this operation
	string& Subtract::GetStringRepresentation()
	{
		return *(new string("-"));
	}
}