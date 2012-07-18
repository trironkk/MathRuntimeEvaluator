#ifndef SQUAREROOT_H
#define SQUAREROOT_H

#include "UnaryOperator.h"

namespace ASCIIMathMLLibrary
{
	class SquareRoot : public UnaryOperator
	{
	public:
		// Basic constructor
		SquareRoot();

		// Perform this operation
		virtual shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual string& GetStringRepresentation();
	};
}

#endif