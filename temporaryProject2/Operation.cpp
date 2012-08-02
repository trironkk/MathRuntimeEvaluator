#include "Operation.h"

namespace MathRuntimeEvaluator
{
	// Returns an integer representing the rank of this Operation
	// Functions:		3
	// Multiplication:	2
	// Division:		2
	// Addition:		1
	// Subtraction:		1
	int Operation::GetRank() const { return 3; }
}