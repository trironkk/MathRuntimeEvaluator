#ifndef ABSOLUTEVALUE_H
#define ABSOLUTEVALUE_H

#include "UnaryOperator.h"

namespace ASCIIMathMLLibrary
{
	class AbsoluteValue : public UnaryOperator
	{
	public:
		// Basic constructor
		AbsoluteValue();

		// Perform this operation
		virtual shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual string& GetStringRepresentation();
	};
}

#endif