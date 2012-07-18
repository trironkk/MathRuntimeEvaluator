#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "IPrintable.h"
#include "WorkingMemory.h"

namespace ASCIIMathMLLibrary
{
	// Abstract base class of expressions
	class Expression : public IPrintable
	{
	public:
		// Basic Constructor
		Expression();

		// Simplify this expression
		// For CompoundExpressions, this method executes all operations and
		// returns the simplest Expression
		// For Variables, this method looks its name up in the WorkingMemory, and
		// returns a Constant with its value.
		// For Constants, this method returns this object.
		virtual shared_ptr<Expression> Simplify(
			const WorkingMemory& workingMemory) = 0;

		// Gets the double value associated with this expression, or throws an
		// error
		virtual double GetValue() = 0;

		// Gets a string representation of this object
		virtual string& GetStringRepresentation() = 0;
	};
}

#endif