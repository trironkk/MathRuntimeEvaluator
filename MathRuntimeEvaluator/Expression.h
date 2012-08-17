#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <memory>
#include <deque>
#include <string>

#include "Operation.h"
#include "Value.h"
#include "IPrintable.h"

namespace MathRuntimeEvaluatorNamespace
{
	class Expression : public IPrintable
	{
	public:
		enum ComponentType
		{
			VALUE,
			OPERATION
		};

	private:
		std::deque<std::shared_ptr<Operation>> _operations;
		std::deque<Value> _values;
		std::deque<ComponentType> _expressionComponentTypes;

	public:
		// Basic Constructor
		Expression();

		// Pushing items to the back of this expression
		void PushBack(Value value);
		void PushBack(std::shared_ptr<Operation> operation);

		// Pushing items to the front of this expression
		void PushFront(Value& value);
		void PushFront(std::shared_ptr<Operation> operation);

		// Returns the number of items in this expression
		int Size();
		int ValuesSize();
		int OperationsSize();

		// Returns the front item
		ComponentType FrontType();
		Value FrontValue();
		std::shared_ptr<Operation> FrontOperation();

		// Remove and free the front item
		void PopFrontValue();
		void PopFrontOperation();

		// Gets a string representation of this expression
		std::string GetStringRepresentation();
	};
}

#endif