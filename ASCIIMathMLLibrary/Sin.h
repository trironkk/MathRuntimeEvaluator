#ifndef SIN_H
#define SIN_H

#include "UnaryOperator.h"

namespace ASCIIMathMLLibrary
{
	class Sin : public UnaryOperator
	{
	public:
		// Basic constructor
		Sin();

		// Perform this operation
		virtual std::shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			std::list<std::shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual std::string& GetStringRepresentation();
	};
}

#endif