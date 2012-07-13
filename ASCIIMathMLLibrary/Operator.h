#ifndef OPERATOR_H
#define OPERATOR_H

#include "WorkingMemory.h"
#include "Expression.h"

namespace ASCIIMathMLLibrary
{
	// Abstract base class of ExpressionComponent - represents a operator
	class Operator
	{
	public:
		// Basic Constructor
		Operator();

		// Evaluates the ExpressionValues, freeing all member ExpressionValue
		// objects returning a new ExpressionValue
		virtual shared_ptr<Expression> Evaluate(const WorkingMemory& workingMemory) = 0;

		// Write a friendly string representation of this object to the inputed
		// ostream
		virtual std::ostream& Print(std::ostream& os) = 0;
	};
}

#endif