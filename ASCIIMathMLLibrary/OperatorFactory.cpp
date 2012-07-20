#include "OperatorFactory.h"

using std::string;

namespace ASCIIMathMLLibrary
{
	Operator& NewOperator(const string& identifier)
	{
		if (identifier == "+")			{ return *(new Add()); }
		else if (identifier == "/")		{ return *(new Divide()); }
		else if (identifier == "*")		{ return *(new Multiply()); }
		else if (identifier == "-")		{ return *(new Subtract()); }
		else if (identifier == "sin")	{ return *(new Sin()); }
		else if (identifier == "cos")	{ return *(new Cos()); }
		else if (identifier == "tan")	{ return *(new Tan()); }
		else if (identifier == "abs")	{ return *(new AbsoluteValue()); }
		else if (identifier == "log")	{ return *(new CommonLogarithm()); }
		else if (identifier == "%")		{ return *(new Modulo()); }
		else if (identifier == "ln")	{ return *(new NaturalLogarithm()); }
		// Note: This symbol is traditionally a '-' character, but that would
		// collide with Subtract, so we use '~' instead.
		else if (identifier == "~")		{ return *(new Negate()); }
		else if (identifier == "sqrt")	{ return *(new SquareRoot()); }
		else
		{
			throw ASCIIMathMLException(
				"Unrecognized identifier in Operator construction."
			);
		}
	}
}