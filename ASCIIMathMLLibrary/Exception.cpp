#include "Exception.h"

using std::string;

namespace ASCIIMathMLLibrary
{
	ASCIIMathMLException::ASCIIMathMLException(string description,
		int errorCode) throw()
		: Description(description)
	{
		ErrorCode = errorCode;
		std::cout << "Error: " << description << std::endl;
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