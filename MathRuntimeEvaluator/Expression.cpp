#include "Expression.h"

#include "MathRuntimeEvaluatorException.h"

#include <iostream>
#include <sstream>

using std::string;
using std::deque;
using std::stringstream;
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
		deque<shared_ptr<Operation>>::iterator operationIter =
			_operations.begin();
		deque<Value>::iterator valueIter =
			_values.begin();
		deque<Expression::ComponentType>::iterator componentIter =
			_expressionComponentTypes.begin();
		int index = 0;

		stringstream result;

		result << "Expression:\n";

		while (componentIter != _expressionComponentTypes.end())
		{
			result << index << ":\t";
			if (*componentIter == VALUE)
			{
				
				result << valueIter->GetStringRepresentation() << "\n";
				valueIter++;
			}
			else
			{
				result << (*operationIter)->GetStringRepresentation() << "\n";
				operationIter++;
			}
			componentIter++;
			index++;
		}
		string final = result.str();
		final.erase(final.size()-1, 1);
		return final;
	}
}
