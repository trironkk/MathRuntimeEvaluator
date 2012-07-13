#include "BinaryOperator.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	BinaryOperator::BinaryOperator(
		shared_ptr<Expression> left, shared_ptr<Expression> right) :
		Operator(), Left(left), Right(right)
	{
	}
}