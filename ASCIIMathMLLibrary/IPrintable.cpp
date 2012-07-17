#include "IPrintable.h"

namespace ASCIIMathMLLibrary
{
	// Call the child class's implementation of Print, and then write a new
	// line character.
	std::ostream& IPrintable::PrintLine(std::ostream& os)
	{
		Print(os);
		os << std::endl;
		return os;
	}
}