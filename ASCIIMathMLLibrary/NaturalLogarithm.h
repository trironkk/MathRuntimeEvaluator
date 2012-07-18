#ifndef NATURALLOGARITHM_H
#define NATURALLOGARITHM_H

#include "UnaryOperator.h"

namespace ASCIIMathMLLibrary
{
	class NaturalLogarithm : public UnaryOperator
	{
	public:
		// Basic constructor
		NaturalLogarithm();

		// Perform this operation
		virtual shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual string& GetStringRepresentation();
	};
}

#endif