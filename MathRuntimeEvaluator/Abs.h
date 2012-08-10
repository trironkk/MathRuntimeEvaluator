#ifndef ABS_H
#define ABS_H

#include "Operation.h"

namespace MathRuntimeEvaluatorNamespace
{
	struct Abs : public Operation
	{
		// Returns a string representation of this Operation
		virtual std::string GetIdentifier() const;
		
		// Returns a helpful string explaining how to use this Operator
		virtual std::string GetUsage() const;

		// Returns the number of parameters this operation works with
		virtual int GetParameterCount() const;

		// Perform this operation
		virtual double Evaluate(const std::deque<double>& parameters) const;
	};
}

#endif