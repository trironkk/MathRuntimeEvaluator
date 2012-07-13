#ifndef UNARY_OPERATOR_H
#define UNARY_OPERATOR_H

#include "Operator.h"

namespace ASCIIMathMLLibrary
{
	// Child class of ExpressionComponent - represents a operator
	class UnaryOperator : public Operator
	{
		// Represents the ExpressionValues for the left side of the operation
		shared_ptr<Expression> Value;

	public:
		// Basic constructor
		UnaryOperator(shared_ptr<Expression> value);

		// Evaluates the ExpressionValues, freeing the value and returning a new
		// ExpressionValue
		virtual shared_ptr<Expression> Evaluate(const WorkingMemory& workingMemory) = 0;

		// Write a friendly string representation of this object to the inputed
		// ostream
		virtual std::ostream& Print(std::ostream& os) = 0;
	};
}

#endif