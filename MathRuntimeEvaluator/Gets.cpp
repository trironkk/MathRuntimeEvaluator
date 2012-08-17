#include "Gets.h"

#include "WorkingMemory.h"

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator

	string Gets::GetIdentifier() const { return "="; }

	// Returns a helpful string explaining how to use this Operator
	string Gets::GetUsage() const
	{
		return
"x = y Assignment \n\
\n\
x: the first parameter \n\
y: the second parameter \n\
returns the sum of x and y \n";
	}

	// Returns true if this operator is a function
	bool Gets::IsFunction() const { return false; }

	// Returns the number of parameters this operation works with
	int Gets::GetParameterCount() const { return 2; }

	// Returns an integer representing the rank of this Operation
	int Gets::GetRank() const { return 1; }

		// Parameter types formatting string
		// - '#'
		//     - The parameter at this index must be defined - it must be a raw
		//       number or an assigned variable
		// - 'v'
		//     - The parameter at this index must be assignable - it must be an
		//       assigned or unassigned variable
		// - ' '
		//     - The parameter at this index can be anything - there are no
		//       restrictions
		// - '*'
		//     - There are an indefinite number of parameters. All following
		//       parameters must abide by the previous character
	std::string Gets::ParameterTypes() const { return "v "; }

	// Perform this operation
	Value Gets::Evaluate(const deque<Value>& parameters) const
	{
		ValidateParameterTypes(parameters);

		WorkingMemory::SetValue(parameters[0].Name, parameters[1].Number);
		return parameters[1].Number;
	}
}