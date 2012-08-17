#include "MathRuntimeEvaluatorException.h"

using std::string;

MathRuntimeEvaluatorException::MathRuntimeEvaluatorException(string description,
	int errorCode) throw()
	: Description(description)
{
	ErrorCode = errorCode;
}

const char* MathRuntimeEvaluatorException::what() const throw()
{
	return Description.c_str();
}

__declspec(dllexport)
std::ostream& operator<<(std::ostream& os, const MathRuntimeEvaluatorException e)
{
	os << e.Description;
	return os;
}
