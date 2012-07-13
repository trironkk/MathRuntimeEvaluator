#include "Variable.h"

namespace ASCIIMathMLLibrary
{
	Variable::Variable(string variableName) : _variableName(variableName) {  }
	
	// Write a friendly string representation of this object to the inputed
	// ostream
	std::ostream& Variable::Print(std::ostream& os)
	{
		os << _variableName;
		return os;
	}
}
