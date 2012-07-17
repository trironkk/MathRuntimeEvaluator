#ifndef	COMPOUND_EXPRESSION_H
#define COMPOUND_EXPRESSION_H

#include "Expression.h"
#include "ExpressionComponent.h"
#include "Operator.h"
#include "WorkingMemory.h"

namespace ASCIIMathMLLibrary
{
	class Operator;

	// Child class of Expression - represents a compound expression, organized
	// with a postfix scheme
	class CompoundExpression : public Expression
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
		void PushFront(shared_ptr<Expression> expression);
		void PushFront(shared_ptr<Operator> operation);
		void PushBack(shared_ptr<Expression> expression);
		void PushBack(shared_ptr<Operator> operation);

		// Retreiving an item of the stack
		shared_ptr<Expression> FrontExpression();
		shared_ptr<Operator> FrontOperator();
		shared_ptr<Expression> BackExpression();
		shared_ptr<Operator> BackOperator();

		// Removing an item from the stack
		void PopFront();
		void PopBack();

		// Check the type of the top of the stack
		ExpressionComponent::Types CheckFrontType();
		ExpressionComponent::Types CheckBackType();
		
		// Returns the number of items
		int Size();

		// Simplify this expression
		// For CompoundExpressions, this method executes all operations and
		// returns the simplest Expression
		// For Variables, this method looks its name up in the WorkingMemory, and
		// returns a Constant with its value.
		// For Constants, this method returns this object
		virtual shared_ptr<Expression> Simplify(
			const WorkingMemory& workingMemory);

		// Gets the double value associated with this expression, or throws an
		// error
		virtual double GetValue();

		// Write a friendly string representation of this object to the inputed
		// ostream
		virtual std::ostream& Print(std::ostream& os);


	};
}

#endif