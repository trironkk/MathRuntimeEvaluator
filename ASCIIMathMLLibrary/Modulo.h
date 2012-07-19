#ifndef MODULO_H
#define MODULO_H

#include "BinaryOperator.h"

namespace ASCIIMathMLLibrary
{
	class Modulo : public BinaryOperator
	{
	public:
		// Basic constructor
		Modulo();

		// Perform this operation
		virtual std::shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			std::list<std::shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual std::string& GetStringRepresentation();
	};
}

#endif