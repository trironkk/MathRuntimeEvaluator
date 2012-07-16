#include "Expression.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	Expression::Expression() {}

	// Call the child class's implementation of Print, and then write a new
	// line character.
	std::ostream& Expression::PrintLine(std::ostream& os)
	{
		Print(os);
		os << std::endl;
		return os;
	}

}
