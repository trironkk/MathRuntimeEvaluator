#ifndef UNARY_EXRESSION_H
#define UNARY_EXRESSION_H

#include <memory>

#include "Constants.h"
#include "Expression.h"
#include "WorkingMemory.h"

namespace ASCIIMathMLLibrary
{
	// Class that represents a variable expression
	class UnaryExpression : public Expression
	{
	private:
		VariableExpressionData _variableData;
		InvolvedVariables _involvedVariables;
	public:
		UnaryExpression();
		void AddVariableCoefficient(String variableName, double coefficient);
		virtual SharedExpressionPointer UnaryExpression::Evaluate(
			WorkingMemory& wm);
		friend std::ostream& operator<<(std::ostream& os, const UnaryExpression ue);
	};
}

#endif