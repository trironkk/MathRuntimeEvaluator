#include "Cos.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	Cos::Cos() {}

	// Performs this operation
	shared_ptr<Expression> Cos::Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters)
	{
		// Get the values of each of the parameters
		shared_ptr<vector<double>> values = GetValuesFromParameters(parameters,
			workingMemory);

		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant(cos((*values)[0]))
		);
	}

	// Gets a string representation of this operation
	string& Cos::GetStringRepresentation()
	{
		return *(new string("cos"));
	}
}