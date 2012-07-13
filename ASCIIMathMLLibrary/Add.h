#ifndef ADD_H
#define ADD_H

#include "BinaryOperator.h"
#include "Constants.h"
#include "Variable.h"

namespace ASCIIMathMLLibrary
{
	// Child class of BinaryExpressionOperator - represents addition
	class Add : public BinaryOperator
	{
	public:
		// Basic constructor
		Add(shared_ptr<Expression> left, shared_ptr<Expression> right);

		// Evaluates the ExpressionValues, freeing the left and the right side and
		// returning a new ExpressionValue
		virtual shared_ptr<Expression> Evaluate(const WorkingMemory& workingMemory);

		// Write a friendly string representation of this object to the inputed
		// ostream
		virtual std::ostream& Print(std::ostream& os);
	};
}

#endif