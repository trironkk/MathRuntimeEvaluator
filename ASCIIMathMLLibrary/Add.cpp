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
		throw ASCIIMathMLException("Not yet implemented.");
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