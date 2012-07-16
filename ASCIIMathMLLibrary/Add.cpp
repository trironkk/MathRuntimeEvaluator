#include "Add.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	Add::Add(Expression* left, Expression* right) :
		BinaryOperator(left, right) { }

	// Evaluates the Expression, freeing the left and the right side and returning
	// a new ExpressionValue
	Expression& Add::Evaluate(const WorkingMemory& workingMemory)
	{
		throw ASCIIMathMLException("Not yet implemented.");
	}

	// Write a friendly string representation of this object to the inputed
	// ostream
	std::ostream& Add::Print(std::ostream& os)
	{
		os << " + ";
		return os;
	}
}