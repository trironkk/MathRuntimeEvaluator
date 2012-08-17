#ifndef OPERATION_H
#define OPERATION_H

#include <string>
#include <list>
#include <deque>
#include <map>

#include "IPrintable.h"
#include "Value.h"

namespace MathRuntimeEvaluatorNamespace
{
	struct Operation : public IPrintable
	{
		// Returns a string representation of this Operation
		virtual std::string GetIdentifier() const = 0;

		// Returns a helpful string explaining how to use this Operation
		virtual std::string GetUsage() const = 0;

		// Returns the number of parameters this Operation works with
		virtual int GetParameterCount() const = 0;

		// Returns an integer representing the rank of this Operation
		// Functions:		3
		// Negation:		3
		// Multiplication:	2
		// Division:		2
		// Addition:		1
		// Subtraction:		1
		virtual int GetRank() const;
		
		// Returns true if this operator is a function
		// NOTE: We default to returning true because only operators will ever
		// have return false.
		virtual bool IsFunction() const;
		
		// Perform this operation
		virtual Value Evaluate(const std::deque<Value>& parameters) const = 0;

		// Gets a string representation of this object
		virtual std::string GetStringRepresentation();

		// Parameter types formatting string
		// - '#'
		//     - The parameter at this index must be defined - it cannot be an
		//       unassigned variable
		// - 'v'
		//     - The parameter at this index must be assignable - it cannot be
		//       a raw number
		// - ' '
		//     - The parameter at this index can be anything - there are no
		//       restrictions
		// - '*'
		//     - There are an indefinite number of parameters. All following
		//       parameters must abide by the previous character
		virtual std::string ParameterTypes() const;

		// Parameter type checking methods
		void ValidateParameterTypes(
			const std::deque<Value>& parameters) const;
	};
}

#endif