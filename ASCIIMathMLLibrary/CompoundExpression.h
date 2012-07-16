#ifndef	COMPOUND_EXPRESSION_H
#define COMPOUND_EXPRESSION_H

#include "Expression.h"
#include "ExpressionComponent.h"
#include "Operator.h"

namespace ASCIIMathMLLibrary
{
	// Child class of Expression - represents a compound expression, organized
	// with a postfix scheme
	class CompoundExpression : Expression
	{
		// A LIFO stack of the involved expressions
		stack<shared_ptr<Expression>> _expressions;
		
		// A LIFO stack of the involved operations
		stack<shared_ptr<Operator>> _operations;

		// A LIFO stack tracking the types of inserted objects
		stack<ExpressionComponent::Types> _objectTypes;

	public:
		// Basic Constructor
		CompoundExpression();

		// Pushing items onto the stack
		void Push(shared_ptr<Expression> expression);
		void Push(shared_ptr<Operator> operation);

		// Retreiving the top item of the stack
		shared_ptr<Expression> TopExpression();
		shared_ptr<Operator> TopOperator();

		// Removing the top item from the stack
		void Pop();

		// Check the type of the top of the stack
		ExpressionComponent::Types CheckType();
	};
}

#endif