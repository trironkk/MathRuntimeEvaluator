#ifndef COS_H
#define COS_H

#include "UnaryOperator.h"

namespace ASCIIMathMLLibrary
{
	class Cos : public UnaryOperator
	{
	public:
		// Basic constructor
		Cos();

		// Perform this operation
		virtual shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual string& GetStringRepresentation();
	};
}

#endif