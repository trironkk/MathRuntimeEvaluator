#ifndef SUBTRACT_H
#define SUBTRACT_H

#include "BinaryOperator.h"

namespace ASCIIMathMLLibrary
{
	class Subtract : public BinaryOperator
	{
	public:
		// Basic constructor
		Subtract ();

		// Perform this operation
		virtual shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual string& GetStringRepresentation();
	};
}

#endif