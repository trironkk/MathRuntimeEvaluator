#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "BinaryOperator.h"

namespace ASCIIMathMLLibrary
{
	class Multiply : public BinaryOperator
	{
	public:
		// Basic constructor
		Multiply();

		// Perform this operation
		virtual shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual string& GetStringRepresentation();
	};
}

#endif