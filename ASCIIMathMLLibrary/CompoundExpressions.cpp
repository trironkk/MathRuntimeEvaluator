#include "CompoundExpression.h"

namespace ASCIIMathMLLibrary
{
	// Basic Constructor
	CompoundExpression::CompoundExpression() :
		_expressions(deque<shared_ptr<Expression>>()),
		_operations(deque<shared_ptr<Operator>>()),
		_objectTypes(deque<ExpressionComponent::Types>()) {  }

	// Pushing items onto the stack
	void CompoundExpression::Push(shared_ptr<Expression> expression)
	{
		_expressions.push_back(expression);
		_objectTypes.push_back(ExpressionComponent::Expression);
	}

	void CompoundExpression::Push(shared_ptr<Operator> operation)
	{
		_operations.push_back(operation);
		_objectTypes.push_back(ExpressionComponent::Operator);
	}

	// Retreiving the top item of the stack
	shared_ptr<Expression> CompoundExpression::TopExpression()
	{
		if (_objectTypes.back() != ExpressionComponent::Expression)
			throw ASCIIMathMLException(
"Tried to retrieve an Expression, but the top item of the stack is not an Expression."
			);

		return _expressions.back();
	}

	shared_ptr<Operator> CompoundExpression::TopOperator()
	{
		if (_objectTypes.back() != ExpressionComponent::Operator)
			throw ASCIIMathMLException(
"Tried to retrieve an Operator, but the top item of the stack is not an Operator."
			);

		return _operations.back();
	}

	// Removing the top item from the stack
	void CompoundExpression::Pop()
	{
		if (CheckType() == ExpressionComponent::Expression)
		{
			_expressions.pop_back();
		}
		else if (CheckType() == ExpressionComponent::Operator)
		{
			_operations.pop_back();
		}
		else
		{
			throw ASCIIMathMLException(
"Unrecognized ExpressionComponent enumeration. Update CompoundExpression::Pop()."
				);
		}
		_objectTypes.pop_back();
	}

	// Check the type of the top of the stack
	ExpressionComponent::Types CompoundExpression::CheckType()
	{
		return _objectTypes.back();
	}
	
	// Write a friendly string representation of this object to the inputed
	// ostream
	std::ostream& CompoundExpression::Print(std::ostream& os)
	{
		int expressionsIndex = 0;
		int operationsIndex = 0;
		for (unsigned int i = 0; i < _objectTypes.size(); i++)
		{
			if (_objectTypes.at(i) == ExpressionComponent::Expression)
			{
				os << _expressions.at(expressionsIndex).get();
			}
			else if (_objectTypes.at(i) == ExpressionComponent::Operator)
			{
				os << _operations.at(operationsIndex).get();
			}
			else
			{
				throw ASCIIMathMLException(
"Unrecognized ExpressionComponent enumeration. Update CompoundExpression::Print()."
					);
			}
		}

		return os;
	}
}