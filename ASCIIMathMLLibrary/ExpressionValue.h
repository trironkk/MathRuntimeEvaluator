#ifndef EXPRESSION_VALUE_H
#define EXPRESSION_VALUE_H

#include "ExpressionComponent.h"

namespace ASCIIMathMLLibrary
{
	// Child class of ExpressionValues - represents a variable
	struct Variable : public ExpressionValue
	{
		// The name of the variable
		string VariableName;

		// Basic constructor
		Variable(string variableName);
		// A print function for the variable
		virtual std::ostream& Print(std::ostream& os);
	};

	// Child class of ExpressionValues - represents a constant
	struct Constant : public ExpressionValue
	{
		// The value of this particular Expression Value
		double Value;

		// Basic constructor
		Constant(double value);
		// A print function for the constant
		virtual std::ostream& Print(std::ostream& os);
	};
}

#endif