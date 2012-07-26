#include "Exception.h"

using std::string;

namespace MathRuntimeEvaluator
{
	ASCIIMathMLException::ASCIIMathMLException(string description,
		int errorCode) throw()
		: Description(description)
	{
		ErrorCode = errorCode;
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