#include "OperatorFactory.h"

using std::string;

namespace MathRuntimeEvaluator
{
	Operator* NewOperator(const string& identifier)
	{
		if (identifier == "+")				{ return new Add(); }
		else if (identifier == "/")			{ return new Divide(); }
		else if (identifier == "*")			{ return new Multiply(); }
		else if (identifier == "-")			{ return new Subtract(); }
		// Note: This symbol is traditionally a '-' character, but that would
		// collide with Subtract, so we use '~' instead.
		else if (identifier == "~")			{ return new Negate(); }
		else if (identifier == "pow")		{ return new Pow(); }
		else if (identifier == "sin")		{ return new Sin(); }
		else if (identifier == "cos")		{ return new Cos(); }
		else if (identifier == "tan")		{ return new Tan(); }
		else if (identifier == "sqrt")		{ return new Sqrt(); }
		else if (identifier == "abs")		{ return new Abs(); }
		else if (identifier == "log2")		{ return new Log2(); }
		else if (identifier == "ln")		{ return new Ln(); }
		else if (identifier == "log")		{ return new Log(); }
		else if (identifier == "log10")		{ return new Log10(); }
		else if (identifier == "mod")		{ return new Mod(); }
		else if (identifier == "sum")		{ return new Sum(); }
		else if (identifier == "avg")		{ return new Avg(); }
		else if (identifier == "rand")		{ return new Rand(); }
		else if (identifier == "stddev"	)	{ return new StdDev(); }
		else
		{
			throw ASCIIMathMLException(
				"Unrecognized identifier in Operator construction."
			);
		}
	}
}