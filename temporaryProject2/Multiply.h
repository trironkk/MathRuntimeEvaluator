#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "Operation.h"

namespace MathRuntimeEvaluator
{
	struct Multiply : public Operation
	{
		// Returns a string representation of this Operator
		virtual const std::string& GetIdentifier() const;
		
		// Returns a helpful string explaining how to use this Operator
		virtual const std::string& GetUsage() const;

		// Returns true if this operator is +, -, *, or /, and false otherwise
		virtual bool IsFunction() const;

		// Returns the number of parameters this Operator works with
		virtual int GetParameterCount() const;
		
		// Returns an integer representing the rank of this Operation
		// Functions:		3
		// Multiplication:	2
		// Division:		2
		// Addition:		1
		// Subtraction:		1
		virtual int GetRank() const;

		// Perform this operation
		virtual double Evaluate(const std::vector<double>& parameters) const;
	};
}

#endif