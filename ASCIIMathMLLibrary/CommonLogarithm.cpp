#include "CommonLogarithm.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	CommonLogarithm::CommonLogarithm() {}

	// Performs this operation
	shared_ptr<Expression> CommonLogarithm::Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters)
	{
		// Get the values of each of the parameters
		shared_ptr<vector<double>> values = GetValuesFromParameters(parameters,
			workingMemory);

		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant(log10((*values)[0]))
		);
	}

	// Gets a string representation of this operation
	string& CommonLogarithm::GetStringRepresentation()
	{
		return *(new string("log"));
	}
}