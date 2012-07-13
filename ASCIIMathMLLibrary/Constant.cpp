#include "Constant.h"

namespace ASCIIMathMLLibrary
{
	// Basic Constructor
	Constant::Constant(double value) : _value(value) {  }

	// Write a friendly string representation of this object to the inputed
	// ostream
	std::ostream& Constant::Print(std::ostream& os)
	{
		os << _value;
		return os;
	}
}