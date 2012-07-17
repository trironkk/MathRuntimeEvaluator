#include "Variable.h"

namespace ASCIIMathMLLibrary
{
	Variable::Variable(string variableName) : _variableName(variableName) {  }
	
	// Simplify this expression
	// For CompoundExpressions, this method executes all operations and
	// returns the simplest Expression
	// For Variables, this method looks its name up in the WorkingMemory, and
	// returns a Constant with its value.
	// For Constants, this method returns this object.
	shared_ptr<Expression> Variable::Simplify(const WorkingMemory& workingMemory)
	{
		if (workingMemory.Contains(this->_variableName))
		{
			return shared_ptr<Expression>(
				new Constant(workingMemory.GetValue(this->_variableName)));
		}

	}

	// Gets the double value associated with this expression, or throws an
	// error
	double Variable::GetValue()
	{
		throw ASCIIMathMLException("Cannot get the value of a variable.");
	}

	// Write a friendly string representation of this object to the inputed
	// ostream
	std::ostream& Variable::Print(std::ostream& os)
	{
		return os << _variableName;
	}
}
