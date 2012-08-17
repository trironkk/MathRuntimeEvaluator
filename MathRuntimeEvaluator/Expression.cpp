#include "Expression.h"

using std::string;
using std::deque;
using std::shared_ptr;

namespace MathRuntimeEvaluatorNamespace
{
	// Basic Constructor
	Expression::Expression() :
		_values(deque<Value>()),
		_operations(deque<shared_ptr<Operation>>()),
		_expressionComponentTypes(deque<ComponentType>())
	{
	}

	// Pushing items to the back of this expression
	void Expression::PushBack(Value value)
	{
		_expressionComponentTypes.push_back(ComponentType::VALUE);
		_values.push_back(value);
	}
	
	void Expression::PushBack(std::shared_ptr<Operation> operation)
	{
		_expressionComponentTypes.push_back(ComponentType::OPERATION);
		_operations.push_back(operation);
	}

	// Pushing items to the back of this expression
	void Expression::PushFront(Value& value)
	{
		_expressionComponentTypes.push_front(ComponentType::VALUE);
		_values.push_front(value);
	}
	
	void Expression::PushFront(std::shared_ptr<Operation> operation)
	{
		_expressionComponentTypes.push_front(ComponentType::OPERATION);
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

	int Expression::OperationsSize()
	{
		return _operations.size();
	}

	// Get the front items
	Expression::ComponentType Expression::FrontType()
	{
		return _expressionComponentTypes.front();
	}

	Value Expression::FrontValue()
	{
		return _values.front();
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
