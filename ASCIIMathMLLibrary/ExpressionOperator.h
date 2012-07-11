#ifndef EXPRESSION_OPERATOR_H
#define EXPRESSION_OPERATOR_H

#include "ExpressionComponent.h"

namespace ASCIIMathMLLibrary
{
	// Child class of ExpressionComponent - represents a operator
	struct BinaryExpressionOperator : public ExpressionComponent
	{
		// Basic constructor
		BinaryExpressionOperator(ExpressionValue& left, ExpressionValue& right);

		// Represents the ExpressionValues for the left side of the operation
		ExpressionValue& Left;
		// Represents the ExpressionValues for the right side of the operation
		ExpressionValue& Right;
		// Evaluates the ExpressionValues, freeing the left and the right side and
		// returning a new ExpressionValue
		virtual ExpressionValue& Evaluate(const WorkingMemory& workingMemory);
	};

	// Child class of ExpressionComponent - represents a operator
	struct UnaryExpressionOperator : public ExpressionComponent
	{
		// Basic constructor
		UnaryExpressionOperator(ExpressionValue& value);

		// Represents the ExpressionValues for the left side of the operation
		ExpressionValue& Value;
		// Evaluates the ExpressionValues, freeing the value and returning a new
		// ExpressionValue
		virtual ExpressionValue& Evaluate(const WorkingMemory& workingMemory);
	};
}
#endif