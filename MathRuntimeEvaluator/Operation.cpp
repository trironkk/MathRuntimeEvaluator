#include "Operation.h"

#include "MathRuntimeEvaluatorException.h"

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

	// Parameter type checking methods
	void Operation::AssertNoUnassignedVariables(
		const std::deque<Value>& parameters) const
	{
		for (std::deque<Value>::const_iterator iter = parameters.begin();
			iter != parameters.end();
			iter++)
		{
			if (iter->Type == Value::UnassignedVariable)
				throw MathRuntimeEvaluatorException(
"Undefined variable encountered: " + iter->Name + "."
				);
		}
	}
}