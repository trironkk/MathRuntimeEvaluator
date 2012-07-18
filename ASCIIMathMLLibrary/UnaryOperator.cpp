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
}