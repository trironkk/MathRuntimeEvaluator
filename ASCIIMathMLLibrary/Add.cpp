#include "Add.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	Add::Add() {}

	// Performs this operation
	shared_ptr<Expression> Add::Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>> parameters)
	{
		// Read in the right and left hand sides
		shared_ptr<Expression> lhs =
			(*parameters.front()).Simplify(workingMemory);
		parameters.pop_front();

		shared_ptr<Expression> rhs =
			(*parameters.front()).Simplify(workingMemory);
		parameters.pop_front();

		// Perform the addition and return
		return shared_ptr<Expression>(
			new Constant((*lhs).GetValue() + (*rhs).GetValue())
		);
	}

	// Returns the number of parameters involved in this operation
	int Add::GetParameterCount()
	{
		return 2;
	}

	// Write a friendly string representation of this object to the inputed
	// ostream
	std::ostream& Add::Print(std::ostream& os)
	{
		return os << "+";
	}
}