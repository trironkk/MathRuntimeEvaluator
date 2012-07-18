#ifndef IPRINTABLE_H
#define IPRINTABLE_H

#include "Constants.h"

namespace ASCIIMathMLLibrary
{
	class IPrintable
	{
	public:
		// Write a friendly string representation of this object to the inputed
		// ostream
		ostream& Print(std::ostream& os);

		// Call the child class's implementation of Print, and then write a new
		// line character.
		ostream& PrintLine(std::ostream& os);

		// Gets a string representation of this object
		virtual string& GetStringRepresentation() = 0;
	};
}

#endif