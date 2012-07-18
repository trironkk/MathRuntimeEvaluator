#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"
#include "Constant.h"

namespace ASCIIMathMLLibrary
{
	// Child class of Expression - represents a variable
	class Variable : public Expression
	{
		// The name of the variable
		string _variableName;

	public:
		// Basic constructor
		Variable(string variableName);

		// Simplify this expression
		// For CompoundExpressions, this method executes all operations and
		// returns the simplest Expression
		// For Variables, this method looks its name up in the WorkingMemory, and
		// returns a Constant with its value.
		// For Constants, this method returns this object.
		virtual shared_ptr<Expression> Simplify(
			const WorkingMemory& workingMemory);

		// Gets the double value associated with this expression, or throws an
		// error
		virtual double GetValue();

		// Gets a string representation of this object
		virtual string& GetStringRepresentation();
	};
}
#endif