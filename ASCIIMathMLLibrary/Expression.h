#ifndef EXRESSION_H
#define EXRESSION_H

#include <memory>

#include "Constants.h"
#include "WorkingMemory.h"
namespace ASCIIMathMLLibrary
{
	// Abstract class that represents a generic expression
	class Expression
	{
	public:
		virtual SharedExpressionPointer Evaluate(WorkingMemory& wm) = 0;
	};
}

#endif