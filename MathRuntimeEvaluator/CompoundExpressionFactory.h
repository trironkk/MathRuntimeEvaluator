#ifndef COMPOUND_EXPRESSION_FACTORY
#define COMPOUND_EXPRESSION_FACTORY

#include <list>
#include <string>

#include "CompoundExpression.h"
#include "Variable.h"
#include "Constant.h"
#include "Utilities.h"

namespace MathRuntimeEvaluator
{
	// Construct and return a new CompoundExpression for a list of strings
	// Note: this assumes the strings come in postfix order.
	CompoundExpression& NewCompoundExpression(
		const std::list<std::string>& identifiers);
}

#endif