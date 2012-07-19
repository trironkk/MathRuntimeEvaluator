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
		virtual std::shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			std::list<std::shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual std::string& GetStringRepresentation();
	};
}

#endif