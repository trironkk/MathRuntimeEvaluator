#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "BinaryOperator.h"

namespace ASCIIMathMLLibrary
{
	class Multiply : public BinaryOperator
	{
	public:
		// Basic constructor
		Multiply();

		// Perform this operation
		virtual std::shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			std::list<std::shared_ptr<Expression>>& parameters);

		// Gets a string representation of this operation
		virtual std::string& GetStringRepresentation();

		// Returns the rank of this operation - higher rank operations are
		// evaluated before lower operations
		// 3 - Unary Operations
		// 2 - Multiply/Divide/Modulo
		// 1 - Add/Subtract
		virtual int GetRank();
	};
}

#endif