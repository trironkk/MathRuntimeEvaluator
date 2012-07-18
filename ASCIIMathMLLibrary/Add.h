#ifndef ADD_H
#define ADD_H

#include "BinaryOperator.h"

namespace ASCIIMathMLLibrary
{
	class Add : public BinaryOperator
	{
	public:
		// Basic constructor
		Add();

		// Perform this operation
		virtual shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual string& GetStringRepresentation();
	};
}

#endif