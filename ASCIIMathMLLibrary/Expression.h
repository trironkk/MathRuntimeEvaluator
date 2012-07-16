#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Constants.h"

namespace ASCIIMathMLLibrary
{
	// Abstract base class of expressions
	class Expression
	{
	public:
		// Basic Constructor
		Expression();

		// Write a friendly string representation of this object to the inputed
		// ostream
		virtual std::ostream& Print(std::ostream& os) = 0;

		// Call the child class's implementation of Print, and then write a new
		// line character.
		std::ostream& PrintLine(std::ostream& os);
	};
}

#endif