#ifndef NEGATE_H
#define NEGATE_H

#include "Operation.h"

namespace MathRuntimeEvaluatorNamespace
{
	struct Negate : public Operation
	{
		// Returns a string representation of this Operator
		virtual std::string GetIdentifier() const;
		
		// Returns a helpful string explaining how to use this Operator
		virtual std::string GetUsage() const;

		// Returns true if this operator is ~, +, -, *, or /, and false otherwise
		virtual bool IsFunction() const;

		// Returns the number of parameters this operation works with
		virtual int GetParameterCount() const;

		// Returns an integer representing the rank of this Operation
		virtual int GetRank() const;

		// Perform this operation
		virtual double Evaluate(const std::deque<double>& parameters) const;
	};
}

#endif