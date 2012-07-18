#ifndef TAN_H
#define TAN_H

#include "UnaryOperator.h"

namespace ASCIIMathMLLibrary
{
	class Tan : public UnaryOperator
	{
	public:
		// Basic constructor
		Tan();

		// Perform this operation
		virtual shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual string& GetStringRepresentation();
	};
}

#endif