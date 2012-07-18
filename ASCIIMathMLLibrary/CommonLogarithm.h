#ifndef COMMONLOGARITHM_H
#define COMMONLOGARITHM_H

#include "UnaryOperator.h"

namespace ASCIIMathMLLibrary
{
	class CommonLogarithm : public UnaryOperator
	{
	public:
		// Basic constructor
		CommonLogarithm();

		// Perform this operation
		virtual shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual string& GetStringRepresentation();
	};
}

#endif