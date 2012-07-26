#include "IPrintable.h"

using std::ostream;

namespace MathRuntimeEvaluator
{
	// Write a friendly string representation of this object to the inputed
	// ostream
	ostream& IPrintable::Print(ostream& os)
	{
		return os << GetStringRepresentation();
	}

	// Call the child class's implementation of Print, and then write a new
	// line character.
	ostream& IPrintable::PrintLine(ostream& os)
	{
		Print(os);
		return os << std::endl;
	}
}