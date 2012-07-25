#ifndef NEGATE_H
#define NEGATE_H

#include "Operator.h"

namespace ASCIIMathMLLibrary
{
	class Negate : public Operator
	{
	public:
		// Perform this operation
		virtual std::shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			std::vector<double>& parameters);
		
		// Returns the number of parameters involved in this object
		virtual int GetParameterCount() { return 1; }

		// Indicates the format of this operator - arithmetic or function
		virtual Format::Type GetFormat() { return Format::Arithmetic; }

		// Gets a string representation of this operation
		virtual std::string& GetStringRepresentation();
	};
}

#endif