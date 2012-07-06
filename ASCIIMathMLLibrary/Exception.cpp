#include <iostream>

#include "Exception.h"

namespace ASCIIMathMLLibrary
{
	ASCIIMathMLException::ASCIIMathMLException(String description) throw()
		: Description(description)
	{
		std::cout << description;
	}

	const char* ASCIIMathMLException::what() const throw()
	{
		return Description.c_str();
	}

	std::ostream& operator<<(std::ostream& os, const ASCIIMathMLException e)
	{
		os << e.Description;
		return os;
	}
}