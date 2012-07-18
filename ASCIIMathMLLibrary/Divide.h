#ifndef DIVIDE_H
#define DIVIDE_H

#include "BinaryOperator.h"

namespace ASCIIMathMLLibrary
{
	class Divide : public BinaryOperator
	{
	public:
		// Basic constructor
		Divide();

		// Perform this operation
		virtual shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual string& GetStringRepresentation();
	};
}

#endif