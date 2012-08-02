#ifndef SUBTRACT_H
#define SUBTRACT_H

#include "Operation.h"

namespace MathRuntimeEvaluator
{
	struct Subtract : public Operation
	{
		// Returns a string representation of this Operator
		virtual const std::string& GetIdentifier() const;
		
		// Returns a helpful string explaining how to use this Operator
		virtual const std::string& GetUsage() const;

		// Returns true if this operator is a function
		virtual bool IsFunction() const;

		// Returns the number of parameters this Operator works with
		virtual int GetParameterCount() const;

		// Returns an integer representing the rank of this Operation
		virtual int GetRank() const;

		// Perform this operation
		virtual double Evaluate(const std::vector<double>& parameters) const;
	};
}

#endif