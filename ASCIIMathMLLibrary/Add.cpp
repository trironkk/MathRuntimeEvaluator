#include "Add.h"

namespace ASCIIMathMLLibrary
{
	// Basic constructor
	Add::Add() {}

	// Performs this operation
	Expression& Add::Evaluate(CompoundExpression compoundExpression,
		const WorkingMemory& workingMemory)
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