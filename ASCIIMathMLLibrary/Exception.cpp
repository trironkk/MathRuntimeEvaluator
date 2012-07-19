#include "Exception.h"

using std::string;

namespace ASCIIMathMLLibrary
{
	ASCIIMathMLException::ASCIIMathMLException(string description) throw()
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