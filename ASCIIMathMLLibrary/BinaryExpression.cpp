#include <memory>

#include "BinaryExpression.h"

namespace ASCIIMathMLLibrary
{
	BinaryExpression::BinaryExpression(
		SharedExpressionPointer l,
		SharedExpressionPointer r,
		Operation o) : _left_hand_side(l), _right_hand_side(r), _operation(o) { }

	SharedExpressionPointer BinaryExpression::Evaluate(WorkingMemory& wm)
	{
		_left_hand_side.get()->Evaluate(wm);
		_right_hand_side.get()->Evaluate(wm);

		// Need to do more work...
		//		Need to consider VariableExpressions should be able to represent
		// expressions like 2a + 3b as a unary expression.
		return SharedExpressionPointer(this);
	}
}
