#include "Constant.h"

namespace ASCIIMathMLLibrary
{
	// Basic Constructor
	Constant::Constant(double value) : _value(value) {  }

	// Simplify this expression
	// For CompoundExpressions, this method executes all operations and
	// returns the simplest Expression
	// For Variables, this method looks its name up in the WorkingMemory, and
	// returns a Constant with its value.
	// For Constants, this method returns this object.
	shared_ptr<Expression> Constant::Simplify(const WorkingMemory& workingMemory)
	{
		return *(new shared_ptr<Expression>(this));
	}

	// Gets the double value associated with this expression, or throws an
	// error
	double Constant::GetValue()
	{
		return _value;
	}

	// Write a friendly string representation of this object to the inputed
	// ostream
	std::ostream& Constant::Print(std::ostream& os)
	{
		return os << _value;
	}
}