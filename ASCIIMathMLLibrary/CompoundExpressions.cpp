#include "CompoundExpression.h"

namespace ASCIIMathMLLibrary
{
	//Basic Constructor
	CompoundExpression::CompoundExpression() :
		_expressions(stack<shared_ptr<Expression>>()),
		_operations(stack<shared_ptr<Operator>>()),
		_objectTypes(stack<ExpressionComponent::Types>()) {  }

	// Pushing functionality overloaded to manage two kinds of objects
	void CompoundExpression::Push(shared_ptr<Expression> expression)
	{
		_expressions.push(expression);
		_objectTypes.push(ExpressionComponent::Expression);
	}

	void CompoundExpression::Push(shared_ptr<Operator> operation)
	{
		_operations.push(operation);
		_objectTypes.push(ExpressionComponent::Operator);
	}

	// Popping functionality overloaded to manage two kinds of objects
	shared_ptr<Expression> CompoundExpression::TopExpression()
	{
		if (_objectTypes.top() != ExpressionComponent::Expression)
			throw ASCIIMathMLException(
"Tried to retrieve an Expression, but the top item of the stack is not an Expression."
			);

		return _expressions.top();
	}

	shared_ptr<Operator> CompoundExpression::TopOperator()
	{
		if (_objectTypes.top() != ExpressionComponent::Operator)
			throw ASCIIMathMLException(
"Tried to retrieve an Operator, but the top item of the stack is not an Operator."
			);

		return _operations.top();
	}

	// Check the type of the top of the stack
	ExpressionComponent::Types CompoundExpression::CheckType()
	{
		return _objectTypes.top();
	}

	void CompoundExpression::Pop()
	{
		if (CheckType() == ExpressionComponent::Expression)
		{
			_expressions.pop();
		}
		else if (CheckType() == ExpressionComponent::Operator)
		{
			_operations.pop();
		}
		else
		{
			throw ASCIIMathMLException(
"Unrecognized ExpressionComponent enumeration. Update CompoundExpression::Pop()."
				);
		}
		_objectTypes.pop();
	}
}