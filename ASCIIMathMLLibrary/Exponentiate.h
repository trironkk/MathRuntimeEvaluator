#ifndef EXPONENTIATE_H
#define EXPONENTIATE_H

#include "BinaryOperator.h"

namespace ASCIIMathMLLibrary
{
	class Exponentiate : public BinaryOperator
	{
	public:
		// Basic constructor
		Exponentiate();

		// Perform this operation
		virtual std::shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			std::list<std::shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual std::string& GetStringRepresentation();
	};
}

#endif