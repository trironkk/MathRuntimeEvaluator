#ifndef SUBTRACT_H
#define SUBTRACT_H

#include "Operator.h"
namespace ASCIIMathMLLibrary
{
	// Child class of Operator - represents subtraction
	class Subtract : public Operator
	{
	public:
		// Basic constructor
		Subtract ();

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