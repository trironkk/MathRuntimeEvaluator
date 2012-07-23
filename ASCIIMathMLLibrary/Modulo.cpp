#include "Modulo.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	Modulo::Modulo() {}

	// Performs this operation
	shared_ptr<Expression> Modulo::Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters)
	{
		// Get the values of each of the parameters
		shared_ptr<vector<double>> values = GetValuesFromParameters(parameters,
			workingMemory);

		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant(fmod((*values)[0], (*values)[1]))
		);
	}

	// Returns the rank of this operation - higher rank operations are
	// evaluated before lower operations
	// 3 - Unary Operations
	// 2 - Multiply/Divide/Modulo
	// 1 - Add/Subtract
	int Modulo::GetRank()
	{
		return 2;
	}

	// Gets a string representation of this operation
	string& Modulo::GetStringRepresentation()
	{
		return *(new string("%"));
	}
}