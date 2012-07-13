#ifndef	COMPOUND_EXPRESSION_H
#define COMPOUND_EXPRESSION_H

#include "Expression.h"
#include "ExpressionComponentType.h"
#include "Operator.h"

namespace ASCIIMathMLLibrary
{
	// Child class of Expression - represents a compound expression, organized
	// with a postfix scheme
	class CompoundExpression : Expression
	{
		// A LIFO stack of the involved expressions
		stack<Expression> _expressions;
		
		// A LIFO stack of the involved operations
		stack<Operator> _operations;

		// A LIFO stack tracking the types of inserted objects
		stack<ExpressionComponentType> _objectTypes;

	public:
		// Basic Constructor
		CompoundExpression();
	};
}

#endif