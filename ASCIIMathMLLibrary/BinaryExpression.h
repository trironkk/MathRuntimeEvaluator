#ifndef BINARY_EXRESSION_H
#define BINARY_EXRESSION_H

#include <memory>

#include "Expression.h"
#include "Constants.h"
#include "UnaryExpression.h"

namespace ASCIIMathMLLibrary
{
	// Class that represents a left hand side, a right hand side, and an operation
	class BinaryExpression : public Expression
	{
	private:
		SharedExpressionPointer _left_hand_side;
		SharedExpressionPointer _right_hand_side;
		Operation _operation;
	public:
		BinaryExpression(
			SharedExpressionPointer l,
			SharedExpressionPointer r,
			Operation o
		);

		virtual SharedExpressionPointer BinaryExpression::Evaluate(
			WorkingMemory& wm);

		friend std::ostream& operator<<(std::ostream& os, const BinaryExpression be);
	};
}

#endif