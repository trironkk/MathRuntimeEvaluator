#ifndef POW_H
#define POW_H

#include "Operator.h"

namespace ASCIIMathMLLibrary
{
	class Pow : public Operator
	{
	public:
		// Perform this operation
		virtual std::shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			std::vector<double>& parameters);
		
		// Returns the number of parameters involved in this object
		virtual int GetParameterCount() { return 2; }
		
		// Indicates the format of this operator - arithmetic or function
		virtual Format::Type GetFormat() { return Format::Function; }

		// Gets a string representation of this operation
		virtual std::string& GetStringRepresentation();
	};
}

#endif