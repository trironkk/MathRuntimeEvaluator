#ifndef OPERATOR_H
#define OPERATOR_H

#include <list>
#include <vector>
#include <memory>
#include <math.h>

#include "Constant.h"
#include "WorkingMemory.h"
#include "CompoundExpression.h"

namespace ASCIIMathMLLibrary
{
	class CompoundExpression;
	
	// Abstract base class of ExpressionComponent - represents a operator
	class Operator : public IPrintable
	{
	public:
		// Basic Constructor
		Operator();

		// Performs this operation
		virtual std::shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			std::list<std::shared_ptr<Expression>>& parameters) = 0;

		// Returns the number of parameters involved in this object
		virtual int GetParameterCount() = 0;
	
		// Gets a string representation of this operation
		virtual std::string& GetStringRepresentation() = 0;

		// Returns the rank of this operation - higher rank operations are
		// evaluated before lower operations
		// 3 - Unary Operations
		// 2 - Multiply/Divide/Modulo
		// 1 - Add/Subtract
		virtual int GetRank() = 0;

	protected:
		// Calls GetValue() on each of the parameters, and returns a vector of
		// results
		std::shared_ptr<std::vector<double>> Operator::GetValuesFromParameters(
			const std::list<std::shared_ptr<Expression>>& parameters,
			const WorkingMemory& workingMemory);
	};
}

#endif