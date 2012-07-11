#include "ExpressionValue.h"

namespace ASCIIMathMLLibrary
{
	// Variable Implementation
	Variable::Variable(string variableName) : VariableName(variableName) {  }

	std::ostream& Variable::Print(std::ostream& os)
	{
		os << VariableName;
		return os;
	}


	// Constant Implementation
	Constant::Constant(double value) : Value(value) {  }

	std::ostream& Constant::Print(std::ostream& os)
	{
		os << Value;
		return os;
	}
}
