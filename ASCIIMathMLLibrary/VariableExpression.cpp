#include "VariableExpression.h"

namespace ASCIIMathMLLibrary
{
	VariableExpression::VariableExpression(String variable_name)
		: _variable_name(variable_name) { }

	String VariableExpression::GetVariableName()
	{
		return _variable_name;
	}

	SharedExpressionPointer VariableExpression::Evaluate(WorkingMemory& wm)
	{
		if (wm.Contains(_variable_name))
		{
			return SharedExpressionPointer(
				new ConstantExpression(
					wm.GetValue(_variable_name)
				)
			);
		} else {
			return SharedExpressionPointer(this);
		}
	}
}