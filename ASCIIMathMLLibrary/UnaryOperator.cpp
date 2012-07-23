#include "UnaryOperator.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	UnaryOperator::UnaryOperator() {}

	// Returns the number of parameters involved in this object
	int UnaryOperator::GetParameterCount()
	{
		return 1;
	}

	// Returns the rank of this operation - higher rank operations are
	// evaluated before lower operations
	// 3 - Unary Operations
	// 2 - Multiply/Divide/Modulo
	// 1 - Add/Subtract
	int UnaryOperator::GetRank()
	{
		return 3;
	}
}