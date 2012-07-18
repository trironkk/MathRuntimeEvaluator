#include "IPrintable.h"

namespace ASCIIMathMLLibrary
{
	// Write a friendly string representation of this object to the inputed
	// ostream
	std::ostream& IPrintable::Print(std::ostream& os)
	{
		return os << GetStringRepresentation();
	}

	// Call the child class's implementation of Print, and then write a new
	// line character.
	std::ostream& IPrintable::PrintLine(std::ostream& os)
	{
		Print(os);
		return os << std::endl;
	}
}