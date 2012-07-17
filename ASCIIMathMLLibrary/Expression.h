#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Constants.h"
#include "IPrintable.h"

namespace ASCIIMathMLLibrary
{
	// Abstract base class of expressions
	class Expression : public IPrintable
	{
	public:
		// Basic Constructor
		Expression();
	};
}

#endif