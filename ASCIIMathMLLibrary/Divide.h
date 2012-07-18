#ifndef DIVIDE_H
#define DIVIDE_H

#include "Operator.h"

namespace ASCIIMathMLLibrary
{
	class Divide : public Operator
	{
	public:
		// Basic constructor
		Divide();

		// Perform this operation
		virtual shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters);

		// Returns the number of parameters involved in this operation
		virtual int GetParameterCount();

		// Gets a string representation of this operation
		virtual string& GetStringRepresentation();
	};
}

#endif