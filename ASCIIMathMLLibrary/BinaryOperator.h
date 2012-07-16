#ifndef BINARY_OPERATOR_H
#define BINARY_OPERATOR_H

#include "Operator.h"

namespace ASCIIMathMLLibrary
{
	// Child class of Operator - represents a operator
	class BinaryOperator : public Operator
	{
		// Represents the ExpressionValues for the left side of the operation
		Expression* Left;

		// Represents the ExpressionValues for the right side of the operation
		Expression* Right;

	public:
		// Basic constructor
		BinaryOperator(Expression* left, Expression* right);

		// Evaluates the ExpressionValues, freeing the left and the right side and
		// returning a new ExpressionValue
		virtual Expression& Evaluate(const WorkingMemory& workingMemory) = 0;

		// Write a friendly string representation of this object to the inputed
		// ostream
		virtual std::ostream& Print(std::ostream& os) = 0;
	};
}

#endif