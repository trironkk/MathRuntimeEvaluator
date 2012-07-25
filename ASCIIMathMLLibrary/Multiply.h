#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "Operator.h"

namespace ASCIIMathMLLibrary
{
	class Multiply : public Operator
	{
	public:
		// Perform this operation
		virtual std::shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			std::vector<double>& parameters);
		
		// Returns the number of parameters involved in this object
		virtual int GetParameterCount() { return 2; }

		// Indicates the format of this operator - arithmetic or function
		virtual Format::Type GetFormat() { return Format::Arithmetic; }

		// Gets a string representation of this operation
		virtual std::string& GetStringRepresentation();
	};
}

#endif