#ifndef OPERATOR_H
#define OPERATOR_H

#include "WorkingMemory.h"
#include "CompoundExpression.h"

namespace ASCIIMathMLLibrary
{
	class CompoundExpression;
	
	// Abstract base class of ExpressionComponent - represents a operator
	class Operator
	{
	public:
		// Basic Constructor
		Operator();

		// Performs this operation
		virtual Expression& Evaluate(CompoundExpression compoundExpression,
			const WorkingMemory& workingMemory) = 0;

		// Write a friendly string representation of this object to the inputed
		// ostream
		virtual std::ostream& Print(std::ostream& os) = 0;
	};
}

#endif