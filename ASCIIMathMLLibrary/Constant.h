#ifndef CONSTANT_H
#define CONSTANT_H

#include "Expression.h"

namespace ASCIIMathMLLibrary
{
	// Child class of Expression - represents a constant value
	class Constant : public Expression
	{
		// The value
		double _value;

	public:
		// Basic constructor
		Constant(double value);

		// Simplify this expression
		// For CompoundExpressions, this method executes all operations and
		// returns the simplest Expression
		// For Variables, this method looks its name up in the WorkingMemory, and
		// returns a Constant with its value.
		// For Constants, this method returns this object.
		virtual shared_ptr<Expression> Simplify(const WorkingMemory& workingMemory);

		// Gets the double value associated with this expression, or throws an
		// error
		virtual double GetValue();

		// Write a friendly string representation of this object to the inputed
		// ostream
		virtual std::ostream& Print(std::ostream& os);
	};
}

#endif