#include "Operation.h"

#include "MathRuntimeEvaluatorException.h"
#include "Utilities.h"
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns an integer representing the rank of this Operation
	// Functions:		3
	// Negation:		3
	// Multiplication:	2
	// Division:		2
	// Addition:		1
	// Subtraction:		1
	// NOTE: We default to a rank of 3 because only operators will ever have a
	// different rank.
	int Operation::GetRank() const { return 3; }

	// Returns true if this operator is a function
	// NOTE: We default to returning true because only operators will ever have
	// return false.
	bool Operation::IsFunction() const { return true; }

	// Gets a string representation of this object
	std::string Operation::GetStringRepresentation()
	{
		return (this->GetIdentifier());
	}

	// Parameter types formatting string
	// - '#'
	//     - The parameter at this index must be defined - it cannot be an
	//       unassigned variable
	// - 'v'
	//     - The parameter at this index must be assignable - it cannot be
	//       a raw number
	// - ' '
	//     - The parameter at this index can be anything - there are no
	//       restrictions
	// - '*'
	//     - There are an indefinite number of parameters. All following
	//       parameters must abide by the previous character
	std::string Operation::ParameterTypes() const { return "#*"; }

	// Parameter type checking methods
	void Operation::ValidateParameterTypes(
		const std::deque<Value>& parameters) const
	{
		// Initialize several fields for tracking the progress of the validation
		char finalType = '\0';
		int index = 0;
		std::string format = ParameterTypes();
		std::string::iterator iter = format.begin();
		std::deque<Value>::const_iterator paramIter = parameters.begin();

		// Verify each parameter
		while (paramIter != parameters.end())
		{
			if (finalType == ' ' || *iter == ' ') {
				// Spaces have no restrictions
			} else if (finalType == '#' || *iter == '#') {
				// #'s cannot be unassigned variables
				if (paramIter->Type == Value::UnassignedVariable)
				{
					throw MathRuntimeEvaluatorException(
						"Operation parameter formating error encountered:\n"
						"Operation Type: " + GetIdentifier() + "\n"
						"Index: " + ToString(index) + "\n"
						"Expected Type: Not UnassignedVariable\n"
						"Actual Type: " + (*paramIter).GetTypeString()
						);
				}
			} else if (finalType == 'v' || *iter == 'v') {
				// v's cannot be raw values
				if (paramIter->Type == Value::RawValue)
					throw MathRuntimeEvaluatorException(
						"Operation parameter formating error encountered:\n"
						"Operation Type: " + GetIdentifier() + "\n"
						"Index: " + ToString(index) + "\n"
						"Expected Type: Not RawValue\n"
						"Actual Type: " + (*paramIter).GetTypeString()
						);
			} else if (finalType == '*' || *iter == '*') {
				// This case is handled below.
			} else {
				throw MathRuntimeEvaluatorException(
"Improperly formated parameter formating string encountered: " + format + "."
					);
			}

			// If an '*' is encountered, set the final token and don't increment
			// iter. Otherwise, increment iter.
			if (*iter == '*') {
				finalType = *(iter-1);
			} else {
				iter++;
			}

			paramIter++;
			index++;
		}
	}
}