#ifndef IPRINTABLE_H
#define IPRINTABLE_H

#include <iostream>
#include <string>

namespace MathRuntimeEvaluator
{
	class IPrintable
	{
	public:
		// Write a friendly string representation of this object to the inputed
		// ostream
		std::ostream& Print(std::ostream& os);

		// Call the child class's implementation of Print, and then write a new
		// line character.
		std::ostream& PrintLine(std::ostream& os);

		// Gets a string representation of this object
		virtual std::string GetStringRepresentation() = 0;
	};
}

#endif