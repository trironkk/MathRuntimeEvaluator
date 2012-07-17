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
		return _objectTypes.back();
	}
	
	// Check the size of the CompountExpression
	int CompoundExpression::Size()
	{
		return _objectTypes.size();
	}

	// Run each operator's Evaluate method
	void CompoundExpression::Simplify(const WorkingMemory workingMemory)
	{
		// Handle the case of having no items in the stack
//		if (Size() == 0)
//		{
//			throw ASCIIMathMLException(
//"Cannot simplify an expression with 0 terms."
//				);
//		}
//
//		// Reduce the expression to one term
//		while (Size() > 1)
//		{
//			// Extract the operator
//			shared_ptr<Operator> currentOperator = TopOperator();
//			Pop();
//
//			// Extract the parameters
//			list<shared_ptr<Expression>> parameters;
//			int parameterCount = (*currentOperator).GetParameterCount();
//			for (int i = 0; i < parameterCount; i++)
//			{
//				parameters.push_back(TopExpression());
//				Pop();
//			}
//
//			// Evaluate the operation and push the result on the stack
//			Push((*currentOperator).Evaluate(workingMemory, parameters));
//			// TODO: These parameters will be going in backwards
//			// TODO: The order that these operators will be evaluated is backwards.
//		}
//
//		if (CheckType() != ExpressionComponent::Operator)
//		{
//			throw ASCIIMathMLException(
//"Improperly formed CompoundExpression."
//				);
//		}
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
		}

		return os;
	}
}