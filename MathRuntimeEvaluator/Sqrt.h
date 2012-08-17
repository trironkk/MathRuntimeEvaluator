#ifndef SQRT_H
#define SQRT_H

#include "Operation.h"

namespace MathRuntimeEvaluatorNamespace
{
	struct Sqrt : public Operation
	{
		// Returns a string representation of this Operator
		virtual std::string GetIdentifier() const;
		
		// Returns a helpful string explaining how to use this Operator
		virtual std::string GetUsage() const;

		// Returns the number of parameters this operation works with
		virtual int GetParameterCount() const;

		// Perform this operation
		virtual Value& Evaluate(const std::deque<Value>& parameters) const;
	};
}

#endif