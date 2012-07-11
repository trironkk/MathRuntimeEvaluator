#ifndef EXRESSION_COMPONENT_H
#define EXRESSION_COMPONENT_H

#include <iostream>

#include "Constants.h"
#include "WorkingMemory.h"

namespace ASCIIMathMLLibrary
{
	// Abstract base class of expression components - values and operators
	struct ExpressionComponent
	{
		// Pure virtual print function requires non-abstract child classes to
		// implement
		virtual std::ostream& Print(std::ostream& os) = 0;
	};

	// Abstract base class of expression values - variables and constants
	struct ExpressionValue : public ExpressionComponent
	{
		virtual std::ostream& Print(std::ostream& os) = 0;
	};

	// Abstract base class of ExpressionComponent - represents a operator
	struct ExpressionOperator : public ExpressionComponent
	{
		// Evaluates the ExpressionValues, freeing all member ExpressionValue
		// objects returning a new ExpressionValue
		virtual ExpressionValue& Evaluate(const WorkingMemory& workingMemory) = 0;
	};
}
#endif