#ifndef MODULO_H
#define MODULO_H

#include "BinaryOperator.h"

namespace ASCIIMathMLLibrary
{
	class Modulo : public BinaryOperator
	{
	public:
		// Basic constructor
		Modulo();

		// Perform this operation
		virtual shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual string& GetStringRepresentation();
	};
}

#endif