#include "Modulo.h"

using std::deque;
using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a string representation of this Operator
	string Modulo::GetIdentifier() const { return "mod"; }

	// Returns a helpful string explaining how to use this Operator
	string Modulo::GetUsage() const
	{
		return
"mod(x,y) Modulo Division \n\
\n\
x: the dividend \n\
y: the divisor \n\
returns the remainder of x / y \n";
	}

	// Returns the number of parameters this operation works with
	int Modulo::GetParameterCount() const { return 2; }

	// Perform this operation
	Value& Modulo::Evaluate(const deque<Value>& parameters) const
	{
		ValidateParameterTypes(parameters);
		return *(new Value(fmod(parameters[0].Number, parameters[1].Number)));
	}
}