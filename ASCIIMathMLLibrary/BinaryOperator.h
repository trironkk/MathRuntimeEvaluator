#ifndef BINARY_OPERATOR_H
#define BINARY_OPERATOR_H

#include "Operator.h"

namespace ASCIIMathMLLibrary
{
	// Child class of Operator - represents a operator
	class BinaryOperator : public Operator
	{
		// Represents the ExpressionValues for the left side of the operation
		shared_ptr<Expression> Left;

		// Represents the ExpressionValues for the right side of the operation
		shared_ptr<Expression> Right;

	public:
		// Basic constructor
		BinaryOperator(shared_ptr<Expression> left, shared_ptr<Expression> right);

		// Evaluates the ExpressionValues, freeing the left and the right side and
		// returning a new ExpressionValue
		virtual shared_ptr<Expression> Evaluate(const WorkingMemory& workingMemory) = 0;

		// Write a friendly string representation of this object to the inputed
		// ostream
		virtual std::ostream& Print(std::ostream& os) = 0;
	};
}

#endif