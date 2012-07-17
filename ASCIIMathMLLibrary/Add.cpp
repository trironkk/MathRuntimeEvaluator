#include "Add.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	Add::Add() {}

	// Performs this operation
	shared_ptr<Expression> Add::Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters)
	{
		// Read in the right and left hand sides
		list<shared_ptr<Expression>>::iterator iter = parameters.begin();

		shared_ptr<Expression> lhs =
			(*(*iter)).Simplify(workingMemory);
		iter++;

		shared_ptr<Expression> rhs =
			(*(*iter)).Simplify(workingMemory);
		iter++;

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