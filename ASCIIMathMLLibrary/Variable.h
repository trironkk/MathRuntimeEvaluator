#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"

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

		// Write a friendly string representation of this object to the inputed
		// ostream
		virtual std::ostream& Print(std::ostream& os);
	};
}
#endif