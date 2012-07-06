#include <memory>

#include "BinaryExpression.h"

namespace ASCIIMathMLLibrary
{
	BinaryExpression::BinaryExpression(
		SharedExpressionPointer l,
		SharedExpressionPointer r,
		Operation o) : _left_hand_side(l), _right_hand_side(r), _operation(o) { }

	/*SharedExpressionPointer BinaryExpression::Evaluate(WorkingMemory& wm)
	{
		return 
	}*/
}
