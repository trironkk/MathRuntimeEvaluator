#include "Add.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	Add::Add(shared_ptr<Expression> left, shared_ptr<Expression> right) :
		BinaryOperator(left, right) { }


	// Evaluates the Expression, freeing the left and the right side and returning
	// a new ExpressionValue
	shared_ptr<Expression> Add::Evaluate(const WorkingMemory& workingMemory)
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