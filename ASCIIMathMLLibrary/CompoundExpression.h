#ifndef	COMPOUND_EXPRESSION_H
#define COMPOUND_EXPRESSION_H

#include "Expression.h"
#include "ExpressionComponent.h"
#include "Operator.h"

namespace ASCIIMathMLLibrary
{
	class Operator;

	// Child class of Expression - represents a compound expression, organized
	// with a postfix scheme
	class CompoundExpression : Expression
	{
		// Note: these data structures are deques because the Print method will
		// require random access. For all other operations, they should behave
		// like a stack.

		// A LIFO data structure for the involved expressions
		deque<shared_ptr<Expression>> _expressions;
		
		// A LIFO data structure for the involved operations
		deque<shared_ptr<Operator>> _operations;

		// A LIFO data structure for tracking the types of inserted objects
		deque<ExpressionComponent::Types> _objectTypes;

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
		
		// Write a friendly string representation of this object to the inputed
		// ostream
		virtual std::ostream& Print(std::ostream& os);

	};
}

#endif