#include "BinaryOperator.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	BinaryOperator::BinaryOperator() {}

	// Returns the number of parameters involved in this object
	int BinaryOperator::GetParameterCount()
	{
		return 2;
	}
}