#include "Expression.h"

using std::string;
using std::deque;
using std::shared_ptr;
using ExpressionComponent::Types;

namespace MathRuntimeEvaluatorNamespace
{
	// Basic Constructor
	Expression::Expression() :
		_values(deque<double>()),
		_operations(deque<shared_ptr<Operation>>()),
		_variables(deque<string>()),
		_expressionComponentTypes(deque<Types>())
	{
	}

	// Pushing items to the back of this expression
	void Expression::PushBack(double value)
	{
		_expressionComponentTypes.push_back(Types::Value);
		_values.push_back(value);
	}
	
	void Expression::PushBack(std::string variableName)
	{
		_expressionComponentTypes.push_back(Types::Variable);
		_variables.push_back(variableName);
	}

	void Expression::PushBack(std::shared_ptr<Operation> operation)
	{
		_expressionComponentTypes.push_back(Types::Operation);
		_operations.push_back(operation);
	}

	// Pushing items to the back of this expression
	void Expression::PushFront(double value)
	{
		_expressionComponentTypes.push_front(Types::Value);
		_values.push_front(value);
	}
	
	void Expression::PushFront(std::string variableName)
	{
		_expressionComponentTypes.push_front(Types::Variable);
		_variables.push_front(variableName);
	}

	void Expression::PushFront(std::shared_ptr<Operation> operation)
	{
		_expressionComponentTypes.push_front(Types::Operation);
		_operations.push_front(operation);
	}

	// Returns the number of items in this expression
	int Expression::Size()
	{
		return _expressionComponentTypes.size();
	}

	int Expression::ValuesSize()
	{
		return _values.size();
	}

	int Expression::VariablesSize()
	{
		return _variables.size();
	}

	int Expression::OperationsSize()
	{
		return _operations.size();
	}

	// Get the front items
	Types Expression::FrontType()
	{
		return _expressionComponentTypes.front();
	}

	double Expression::FrontValue()
	{
		return _values.front();
	}

	string Expression::FrontVariable()
	{
		return _variables.front();
	}

	shared_ptr<Operation> Expression::FrontOperation()
	{
		return _operations.front();
	}

	// Returns the front item
	void Expression::PopFrontValue()
	{
		_expressionComponentTypes.pop_front();
		_values.pop_front();
	}

	void Expression::PopFrontVariable()
	{
		_expressionComponentTypes.pop_front();
		_variables.pop_front();
	}

	void Expression::PopFrontOperation()
	{
		_expressionComponentTypes.pop_front();
		_operations.pop_front();
	}

	// Gets a string representation of this expression
	std::string Expression::GetStringRepresentation()
	{
		return "expression string";
	}
}
