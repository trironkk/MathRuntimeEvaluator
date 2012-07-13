#ifndef CONSTANT_H
#define CONSTANT_H

#include "Expression.h"

namespace ASCIIMathMLLibrary
{
	// Child class of Expression - represents a constant value
	class Constant : public Expression
	{
		// The value
		double _value;

	public:
		// Basic constructor
		Constant(double value);

		// Write a friendly string representation of this object to the inputed
		// ostream
		virtual std::ostream& Print(std::ostream& os);
	};
}

#endif