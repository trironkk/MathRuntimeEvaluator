#ifndef SQRT_H
#define SQRT_H

#include "Operation.h"

namespace MathRuntimeEvaluator
{
	struct Sqrt : public Operation
	{
		// Returns a string representation of this Operator
		virtual const std::string& GetIdentifier() const;
		
		// Returns a helpful string explaining how to use this Operator
		virtual const std::string& GetUsage() const;

		// Returns true if this operator is +, -, *, or /, and false otherwise
		virtual bool IsFunction() const;

		// Returns the number of parameters this Operator works with
		virtual int GetParameterCount() const;

		// Perform this operation
		virtual double Evaluate(const std::vector<double>& parameters) const;
	};
}

#endif