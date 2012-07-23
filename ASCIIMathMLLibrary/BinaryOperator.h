#ifndef BINARYOPERATOR_H
#define BINARYOPERATOR_H

#include "Operator.h"

namespace ASCIIMathMLLibrary
{
	// Abstract base class of ExpressionComponent - represents a operator
	class BinaryOperator : public Operator
	{
	public:
		// Basic Constructor
		BinaryOperator();

		// Performs this operation
		virtual std::shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			std::list<std::shared_ptr<Expression>>& parameters) = 0;

		// Returns the number of parameters involved in this object
		int GetParameterCount();
	
		// Gets a string representation of this operation
		virtual std::string& GetStringRepresentation() = 0;
	};
}

#endif