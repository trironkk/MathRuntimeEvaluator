#include "Operation.h"

using std::string;

namespace MathRuntimeEvaluator
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
}