#ifndef ADD_H
#define ADD_H

#include "Operator.h"

namespace ASCIIMathMLLibrary
{
	// Child class of Operator - represents addition
	class Add : public Operator
	{
	public:
		// Basic constructor
		Add();

		// Performs this operation
		virtual Expression& Evaluate(CompoundExpression compoundExpression,
			const WorkingMemory& workingMemory);

		// Write a friendly string representation of this object to the inputed
		// ostream
		virtual std::ostream& Print(std::ostream& os);
	};
}

#endif