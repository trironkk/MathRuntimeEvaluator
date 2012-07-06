#include "ConstantExpression.h"

namespace ASCIIMathMLLibrary
{
	ConstantExpression::ConstantExpression(double value) : _value(value) { }

	SharedExpressionPointer ConstantExpression::Evaluate(WorkingMemory& wm)
	{
		return SharedExpressionPointer(this);
	}
}
