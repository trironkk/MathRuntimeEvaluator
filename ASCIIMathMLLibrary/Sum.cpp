#include "Sum.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace ASCIIMathMLLibrary
{
	// Performs this operation
	shared_ptr<Expression> Sum::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		double sum = 0;
		for (int i = 0; i < values.size(); i++)
		{
			sum += values[i];
		}

		return shared_ptr<Expression>(
			new Constant(sum)
		);
	}

	// Gets a string representation of this operation
	string& Sum::GetStringRepresentation()
	{
		return *(new string("sum"));
	}
}