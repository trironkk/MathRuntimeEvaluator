#ifndef OPERATION_H
#define OPERATION_H

#include <string>
#include <list>
#include <vector>
#include <map>

namespace MathRuntimeEvaluator
{
	struct Operation
	{
		// Returns a string representation of this Operation
		virtual const std::string& GetIdentifier() const = 0;

		// Returns a helpful string explaining how to use this Operation
		virtual const std::string& GetUsage() const = 0;

		// Returns true if this operator is +, -, *, or /, and false otherwise
		virtual bool IsFunction() const = 0;

		// Returns the number of parameters this Operation works with
		virtual int GetParameterCount() const = 0;

		// Returns an integer representing the rank of this Operation
		// Functions:		3
		// Multiplication:	2
		// Division:		2
		// Addition:		1
		// Subtraction:		1
		virtual int GetRank() const;

		// Perform this operation
		virtual double Evaluate(const std::vector<double>& parameters) const = 0;
	};
}

#endif