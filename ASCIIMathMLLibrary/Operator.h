#ifndef OPERATOR_H
#define OPERATOR_H

#include <list>
#include <vector>
#include <memory>
#include <math.h>
#include <string>
#include <algorithm>

#include "OperatorType.h"
#include "Constant.h"
#include "WorkingMemory.h"

namespace ASCIIMathMLLibrary
{
	// Forward declaration of CompoundExpression - necessary because of cyclic
	// dependency
	class CompoundExpression;

	// Returns true if the string is an operator, and false otherwise
	bool IsOperator(const std::string str);

	// Returns true if the string is an arithmetic operator, and false otherwise
	bool IsArithmeticOperator(const std::string str);

	// Returns the rank of the operator associated with the input string
	int GetOperatorRank(const std::string str);

	// Abstract base class of ExpressionComponent - represents a operator
	class Operator : public IPrintable
	{
	public:
		// Performs this operation
		virtual std::shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			std::vector<double>& values) = 0;

		// Indicates the format of this operator - arithmetic or function
		virtual Format::Type GetFormat() = 0;

		// Returns the number of parameters involved in this object
		virtual int GetParameterCount() = 0;
	
		// Gets a string representation of this operation
		virtual std::string& GetStringRepresentation() = 0;
		
		// Perform this operation
		std::shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			std::list<std::shared_ptr<Expression>>& parameters);

	protected:
		// Calls GetValue() on each of the parameters, and returns a vector of
		// results
		std::vector<double>& Operator::GetValuesFromParameters(
			const std::list<std::shared_ptr<Expression>>& parameters,
			const WorkingMemory& workingMemory);
	};
}

#endif