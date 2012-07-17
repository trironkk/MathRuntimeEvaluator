#ifndef DIVIDE_H
#define DIVIDE_H

#include "Operator.h"
namespace ASCIIMathMLLibrary
{
	// Child class of Operator - represents division
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

		// Write a friendly string representation of this object to the inputed
		// ostream
		virtual std::ostream& Print(std::ostream& os);
	};
}

#endif