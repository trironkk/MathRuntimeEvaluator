#ifndef RAND_H
#define RAND_H

#include "Operator.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

namespace MathRuntimeEvaluator
{
	class Rand : public Operator
	{
	public:
		// Perform this operation
		virtual std::shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			std::vector<double>& parameters);
		
		// Returns the number of parameters involved in this object
		virtual int GetParameterCount() { return 1; }
		
		// Gets a string representation of this operation
		virtual std::string& GetStringRepresentation();
	};
}

#endif