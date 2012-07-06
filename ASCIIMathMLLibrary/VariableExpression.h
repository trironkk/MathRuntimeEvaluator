#ifndef VARIABLE_EXRESSION_H
#define VARIABLE_EXRESSION_H

#include <memory>

#include "Constants.h"
#include "WorkingMemory.h"
#include "UnaryExpression.h"
#include "ConstantExpression.h"

namespace ASCIIMathMLLibrary
{
	// Class that represents a variable
	class VariableExpression : public UnaryExpression
	{
	private:
		String _variable_name;
	public:
		VariableExpression(String variable_name);
		String GetVariableName();
		virtual SharedExpressionPointer
			VariableExpression::Evaluate(WorkingMemory& wm);
	};
}

#endif