#ifndef ADD_H
#define ADD_H

#include "BinaryOperator.h"

namespace ASCIIMathMLLibrary
{
	class Add : public BinaryOperator
	{
	public:
		// Basic constructor
		Add();

		// Perform this operation
		virtual std::shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			std::list<std::shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual std::string& GetStringRepresentation();
	};
}

#endif