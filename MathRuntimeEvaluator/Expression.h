#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <memory>
#include <deque>
#include <string>

#include "Operation.h"
#include "ExpressionComponent.h"
#include "IPrintable.h"

namespace MathRuntimeEvaluatorNamespace
{
	// Abstract base class of expressions
	class Expression : public IPrintable
	{
		std::deque<double> _values;
		std::deque<std::shared_ptr<Operation>> _operations;
		std::deque<std::string> _variables;
		std::deque<ExpressionComponent::Types> _expressionComponentTypes;
	public:
		// Basic Constructor
		Expression();

		// Pushing items to the back of this expression
		void PushBack(std::string variableName);
		void PushBack(double value);
		void PushBack(std::shared_ptr<Operation> operation);

		// Pushing items to the front of this expression
		void PushFront(std::string variableName);
		void PushFront(double value);
		void PushFront(std::shared_ptr<Operation> operation);

		// Returns the number of items in this expression
		int Size();
		int ValuesSize();
		int VariablesSize();
		int OperationsSize();

		// Returns the front item
		ExpressionComponent::Types FrontType();
		double FrontValue();
		std::string FrontVariable();
		std::shared_ptr<Operation> FrontOperation();

		// Returns the front item
		void PopFrontValue();
		void PopFrontVariable();
		void PopFrontOperation();

		// Gets a string representation of this expression
		std::string GetStringRepresentation();
	};
}

#endif