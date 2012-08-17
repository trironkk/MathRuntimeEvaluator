#ifndef GETS_H
#define GETS_H

#include "Operation.h"

namespace MathRuntimeEvaluatorNamespace
{
	struct Gets : public Operation
	{
		// Returns a string representation of this Operator
		virtual std::string GetIdentifier() const;
		
		// Returns a helpful string explaining how to use this Operator
		virtual std::string GetUsage() const;

		// Returns true if this operator is +, -, *, or /, and false otherwise
		virtual bool IsFunction() const;

		// Returns the number of parameters this operation works with
		virtual int GetParameterCount() const;

		// Returns an integer representing the rank of this Operation
		virtual int GetRank() const;

		// Perform this operation
		virtual Value Evaluate(const std::deque<Value>& parameters) const;

		// Parameter types formatting string
		// - '#'
		//     - The parameter at this index must be defined - it must be a raw
		//       number or an assigned variable
		// - 'v'
		//     - The parameter at this index must be assignable - it must be an
		//       assigned or unassigned variable
		// - ' '
		//     - The parameter at this index can be anything - there are no
		//       restrictions
		// - '*'
		//     - There are an indefinite number of parameters. All following
		//       parameters must abide by the previous character
		virtual std::string ParameterTypes() const;
	};
}

#endif