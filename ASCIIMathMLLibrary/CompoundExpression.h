#ifndef	COMPOUND_EXPRESSION_H
#define COMPOUND_EXPRESSION_H

#include <deque>
#include <list>
#include <stack>
#include <memory>
#include <string>
#include <sstream>
#include <iostream>

#include "Expression.h"
#include "ExpressionComponent.h"
#include "Operator.h"
#include "WorkingMemory.h"
#include "Variable.h"
#include "Constant.h"

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
		std::deque<std::shared_ptr<Expression>> _expressions;
		
		// A LIFO data structure for the involved operations
		std::deque<std::shared_ptr<Operator>> _operations;

		// A LIFO data structure for tracking the types of inserted objects
		std::deque<ExpressionComponent::Types> _objectTypes;

	public:
		// Basic Constructor
		CompoundExpression();

		// Pushing expressions onto the stack
		void PushFront(std::shared_ptr<Expression> expression);
		void PushBack(std::shared_ptr<Expression> expression);

		// Pushing Expressions - Abbreviated
		void PushFront(double value);
		void PushFront(std::string variableName);
		void PushBack(double value);
		void PushBack(std::string variableName);

		// Pushing operators onto the stack
		void PushFront(std::shared_ptr<Operator> operation);
		void PushBack(std::shared_ptr<Operator> operation);

		// Pushing Operators - Abbreviated
		// Note: Template functions cannot be prototyped, so we define them here
		template <class T>
		void PushFront() { PushFront(*(new shared_ptr<T>(new T()))); }
		template <class T>
		void PushBack() { PushBack(*(new shared_ptr<T>(new T()))); }

		// Retreiving an item of the stack
		std::shared_ptr<Expression> FrontExpression();
		std::shared_ptr<Operator> FrontOperator();
		std::shared_ptr<Expression> BackExpression();
		std::shared_ptr<Operator> BackOperator();

		// Removing an item from the stack
		void PopFront();
		void PopBack();

		// Get the item at the specified index
		std::shared_ptr<Expression> AtExpression(int index);
		std::shared_ptr<Operator> AtOperator(int index);

		// Check the type of the top of the stack
		ExpressionComponent::Types CheckFrontType();
		ExpressionComponent::Types CheckBackType();
		ExpressionComponent::Types CheckAtType(int index);
		
		// Returns the number of items
		int Size();

		// Simplify this expression
		// For CompoundExpressions, this method executes all operations and
		// returns the simplest Expression
		// For Variables, this method looks its name up in the WorkingMemory, and
		// returns a Constant with its value.
		// For Constants, this method returns this object
		virtual std::shared_ptr<Expression> Simplify(
			const WorkingMemory& workingMemory);

		// Gets the double value associated with this expression, or throws an
		// error
		virtual double GetValue();

		// Gets a string representation of this object
		virtual std::string& GetStringRepresentation();
		std::string& GetInfixStringRepresentation();
		std::string& GetPostfixStringRepresentation();
	};
}

#endif