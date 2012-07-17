#include "CompoundExpression.h"

namespace ASCIIMathMLLibrary
{
	// Basic Constructor
	CompoundExpression::CompoundExpression() :
		_expressions(deque<shared_ptr<Expression>>()),
		_operations(deque<shared_ptr<Operator>>()),
		_objectTypes(deque<ExpressionComponent::Types>()) {  }

	// Pushing items onto the stack
	void CompoundExpression::PushBack(shared_ptr<Expression> expression)
	{
		_expressions.push_back(expression);
		_objectTypes.push_back(ExpressionComponent::Expression);
	}

	void CompoundExpression::PushBack(shared_ptr<Operator> operation)
	{
		_operations.push_back(operation);
		_objectTypes.push_back(ExpressionComponent::Operator);
	}

	void CompoundExpression::PushFront(shared_ptr<Expression> expression)
	{
		_expressions.push_front(expression);
		_objectTypes.push_front(ExpressionComponent::Expression);
	}

	void CompoundExpression::PushFront(shared_ptr<Operator> operation)
	{
		_operations.push_front(operation);
		_objectTypes.push_front(ExpressionComponent::Operator);
	}

	// Retreiving an item of the stack
	shared_ptr<Expression> CompoundExpression::FrontExpression()
	{
		if (_objectTypes.front() != ExpressionComponent::Expression)
			throw ASCIIMathMLException(
"Tried to retrieve an Expression, but the front item of the stack is not an Expression."
			);

		return _expressions.front();
	}

	shared_ptr<Operator> CompoundExpression::FrontOperator()
	{
		if (_objectTypes.front() != ExpressionComponent::Operator)
			throw ASCIIMathMLException(
"Tried to retrieve an Operator, but the front item of the stack is not an Operator."
			);

		return _operations.front();
	}

	shared_ptr<Expression> CompoundExpression::BackExpression()
	{
		if (_objectTypes.back() != ExpressionComponent::Expression)
			throw ASCIIMathMLException(
"Tried to retrieve an Expression, but the front item of the stack is not an Expression."
			);

		return _expressions.back();
	}

	shared_ptr<Operator> CompoundExpression::BackOperator()
	{
		if (_objectTypes.back() != ExpressionComponent::Operator)
			throw ASCIIMathMLException(
"Tried to retrieve an Operator, but the front item of the stack is not an Operator."
			);

		return _operations.back();
	}

	// Removing an item from the stack
	void CompoundExpression::PopBack()
	{
		if (CheckBackType() == ExpressionComponent::Expression)
		{
			_expressions.pop_back();
		}
		else if (CheckBackType() == ExpressionComponent::Operator)
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

	void CompoundExpression::PopFront()
	{
		if (CheckFrontType() == ExpressionComponent::Expression)
		{
			_expressions.pop_front();
		}
		else if (CheckFrontType() == ExpressionComponent::Operator)
		{
			_operations.pop_front();
		}
		else
		{
			throw ASCIIMathMLException(
"Unrecognized ExpressionComponent enumeration. Update CompoundExpression::Pop()."
				);
		}
		_objectTypes.pop_front();
	}

	// Check the type of the top of the stack
	ExpressionComponent::Types CompoundExpression::CheckBackType()
	{
		return _objectTypes.back();
	}

	ExpressionComponent::Types CompoundExpression::CheckFrontType()
	{
		return _objectTypes.front();
	}
	
	// Check the size of the CompountExpression
	int CompoundExpression::Size()
	{
		return _objectTypes.size();
	}

	// Run each operator's Evaluate method
	shared_ptr<Expression> CompoundExpression::Simplify(
		const WorkingMemory& workingMemory)
	{
		// Handle the case of having no items in the stack
		if (Size() == 0)
		{
			throw ASCIIMathMLException(
"Cannot simplify an expression with 0 terms."
				);
		}

		// Holds the expressions
		stack<shared_ptr<Expression>> expressionStack;

		// Reduce the expression to one term
		do
		{
			// Collect Expressions until an operator is encountered
			while(CheckFrontType() != ExpressionComponent::Operator)
			{
				expressionStack.push(FrontExpression());
				PopFront();
			}

			// Get the operation
			shared_ptr<Operator> operation(FrontOperator());
			PopFront();

			// Get the parameters
			int parameterCount = (*operation).GetParameterCount();
			list<shared_ptr<Expression>> parameters;
			for (int i = 0; i < parameterCount; i++)
			{
				parameters.push_front(expressionStack.top());
				expressionStack.pop();
			}

			// Evaluate the operation and push the result onto the expressionStack
			PushFront((*operation).Evaluate(workingMemory, parameters));
		} while (expressionStack.size() > 1 || Size() > 1);

		// Ensure there's exactly one term left
		if (expressionStack.size() != 0)
		{
			throw ASCIIMathMLException("Improperly formed CompoundExpression.");
		}

		// Return the first term in the underlying Expression deque
		return FrontExpression();
	}

	// Gets the double value associated with this expression, or throws an
	// error
	double CompoundExpression::GetValue()
	{
		// Handle the case of having no items in the stack
		if (Size() != 1)
		{
		throw ASCIIMathMLException(
"Cannot get the value of a CompoundExpression with more than one term."
			);
		}

		return (*FrontExpression()).GetValue();
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
				(*_expressions.at(expressionsIndex++)).Print(os);
			}
			else if (_objectTypes.at(i) == ExpressionComponent::Operator)
			{
				(*_operations.at(operationsIndex++)).Print(os);
			}
			else
			{
				throw ASCIIMathMLException(
"Unrecognized ExpressionComponent enumeration. Update CompoundExpression::Print()."
					);
			}
			if (i < _objectTypes.size() - 1)
				os << ' ';
		}

		return os;
	}
}