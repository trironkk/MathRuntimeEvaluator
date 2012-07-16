#include "BinaryOperator.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	BinaryOperator::BinaryOperator(
		Expression* left, Expression* right) :
		Operator(), Left(left), Right(right)
	{
	}
}