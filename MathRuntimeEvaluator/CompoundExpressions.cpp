#include "CompoundExpression.h"

using std::deque;
using std::list;
using std::vector;
using std::stack;
using std::shared_ptr;
using std::string;
using std::istringstream;
using std::stringstream;

namespace MathRuntimeEvaluator
{
	// Basic Constructor
	CompoundExpression::CompoundExpression() :
		_expressions(deque<shared_ptr<Expression>>()),
		_operations(deque<shared_ptr<Operation>>()),
		_objectTypes(deque<ExpressionComponent::Types>()) {  }

	// Pushing expressions onto the stack
	void CompoundExpression::PushBack(shared_ptr<Expression> expression)
	{
		_expressions.push_back(expression);
		_objectTypes.push_back(ExpressionComponent::Expression);
	}

	void CompoundExpression::PushFront(shared_ptr<Expression> expression)
	{
		_expressions.push_front(expression);
		_objectTypes.push_front(ExpressionComponent::Expression);
	}

	// Pushing Expressions - Abbreviated
	void CompoundExpression::PushFront(double value)
	{
		PushFront(*(new shared_ptr<Expression>(new Constant(value))));
	}

	void CompoundExpression::PushFront(string identifier)
	{
		if (Operations::IsOperation(identifier))
		{
			PushFront(Operations::GetOperation(identifier));
		}
		else if (IsDouble(identifier))
		{
			PushFront(*(new shared_ptr<Expression>(new Constant(
				ToDouble(identifier)))));
		}
		else
		{
			PushFront(*(new shared_ptr<Expression>(new Variable(identifier))));
		}
	}

	void CompoundExpression::PushBack(double value)
	{
		PushBack(*(new shared_ptr<Expression>(new Constant(value))));
	}

	void CompoundExpression::PushBack(string identifier)
	{
		if (Operations::IsOperation(identifier))
		{
			PushBack(Operations::GetOperation(identifier));
		}
		else if (IsDouble(identifier))
		{
			PushBack(*(new shared_ptr<Expression>(new Constant(
				ToDouble(identifier)))));
		}
		else
		{
			PushBack(*(new shared_ptr<Expression>(new Variable(identifier))));
		}
	}
	
	// Pushing operators onto the stack
	void CompoundExpression::PushBack(shared_ptr<Operation> operation)
	{
		_operations.push_back(operation);
		_objectTypes.push_back(ExpressionComponent::Operation);
	}

	void CompoundExpression::PushFront(shared_ptr<Operation> operation)
	{
		_operations.push_front(operation);
		_objectTypes.push_front(ExpressionComponent::Operation);
	}

	// Retrieving an item of the stack
	shared_ptr<Expression> CompoundExpression::FrontExpression()
	{
		if (_objectTypes.front() != ExpressionComponent::Expression)
			throw MathRuntimeEvaluatorException(
"Tried to retrieve an Expression, but the front item of the stack is not an Expression."
			);

		return _expressions.front();
	}

	shared_ptr<Operation> CompoundExpression::FrontOperation()
	{
		if (_objectTypes.front() != ExpressionComponent::Operation)
			throw MathRuntimeEvaluatorException(
"Tried to retrieve an Operation, but the front item of the stack is not an Operation."
			);

		return _operations.front();
	}

	shared_ptr<Expression> CompoundExpression::BackExpression()
	{
		if (_objectTypes.back() != ExpressionComponent::Expression)
			throw MathRuntimeEvaluatorException(
"Tried to retrieve an Expression, but the front item of the stack is not an Expression."
			);

		return _expressions.back();
	}

	shared_ptr<Operation> CompoundExpression::BackOperation()
	{
		if (_objectTypes.back() != ExpressionComponent::Operation)
			throw MathRuntimeEvaluatorException(
"Tried to retrieve an Operation, but the front item of the stack is not an Operation."
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
		else if (CheckBackType() == ExpressionComponent::Operation)
		{
			_operations.pop_back();
		}
		else
		{
			throw MathRuntimeEvaluatorException(
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
		else if (CheckFrontType() == ExpressionComponent::Operation)
		{
			_operations.pop_front();
		}
		else
		{
			throw MathRuntimeEvaluatorException(
"Unrecognized ExpressionComponent enumeration. Update CompoundExpression::Pop()."
				);
		}
		_objectTypes.pop_front();
	}

	// Get the item at the specified index
	shared_ptr<Expression> CompoundExpression::AtExpression(int index)
	{
		if (_objectTypes.at(index) != ExpressionComponent::Expression)
			throw MathRuntimeEvaluatorException(
"Tried to retrieve an Expression, but the front item of the stack is not an Expression."
			);

		int count = 0;
		for (int i = 0; i < index; i++)
		{
			if (_objectTypes.at(i) == ExpressionComponent::Expression)
				count++;
		}
		return _expressions.at(count);
	}

	shared_ptr<Operation> CompoundExpression::AtOperation(int index)
	{
		if (_objectTypes.at(index) != ExpressionComponent::Operation)
			throw MathRuntimeEvaluatorException(
"Tried to retrieve an Operator, but the front item of the stack is not an Operator."
			);

		int count = 0;
		for (int i = 0; i < index; i++)
		{
			if (_objectTypes.at(i) == ExpressionComponent::Operation)
				count++;
		}
		return _operations.at(count);
	}

	// Check the type of the top of the stack
	ExpressionComponent::Types CompoundExpression::CheckBackType()
	{
		if (_objectTypes.size() == 0)
			throw MathRuntimeEvaluatorException("CompoundExpression is empty.");
		return _objectTypes.back();
	}

	ExpressionComponent::Types CompoundExpression::CheckFrontType()
	{
		if (_objectTypes.size() == 0)
			throw MathRuntimeEvaluatorException("CompoundExpression is empty.");
		return _objectTypes.front();
	}

	ExpressionComponent::Types CompoundExpression::CheckAtType(int index)
	{
		return _objectTypes.at(index);
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
			throw MathRuntimeEvaluatorException(
"Cannot simplify an expression with 0 terms."
				);
		}

		// Handle the case of having a variable name that is not in Working Memory
		for (std::deque<std::shared_ptr<Expression>>::iterator iter =
				_expressions.begin();
			iter != _expressions.end();
			iter++)
		{
			if (!IsDouble((*iter)->GetStringRepresentation()) &&
				!workingMemory.Contains((*(*iter)).GetStringRepresentation()))
			{
				throw MathRuntimeEvaluatorException(
"Undefined variable: " + (*iter)->GetStringRepresentation() + "."
					);
			}
		}

		// Handle the case of the compound expression not containing an operator
		if (_operations.size() == 0)
		{
			if (_expressions.size() > 1)
				throw MathRuntimeEvaluatorException(
"No operator present."
				);
			double result;
			if (IsDouble((*FrontExpression()).GetStringRepresentation()))
			{
				result = (*FrontExpression()).GetValue();
			}
			else
			{
				result = workingMemory.GetValue(
					(*FrontExpression()).GetStringRepresentation()
				);
			}
			PopFront();
			PushFront(result);
			return FrontExpression();
		}

		// Holds the expressions
		stack<shared_ptr<Expression>> expressionStack;

		// Reduce the expression to one term
		do
		{
			// Collect Expressions until an operator is encountered
			while(CheckFrontType() != ExpressionComponent::Operation)
			{
				expressionStack.push(FrontExpression());
				PopFront();
			}

			// Get the operation
			shared_ptr<Operation> operation(FrontOperation());
			PopFront();

			// Get the parameters
			int parameterCount = (*operation).GetParameterCount();
			list<shared_ptr<Expression>> parameters;

			// Handle the case of an indefinite number of parameters. All we need
			// to do is get the actual parameter count, which we recorded as the
			// first parameter to be popped off the stack when we parsed the
			// expression.
			if (parameterCount == -1)
			{
				istringstream(
					(*(expressionStack.top())).GetStringRepresentation()
				) >> parameterCount;
				expressionStack.pop();
			}

			for (int i = 0; i < parameterCount; i++)
			{
				if (expressionStack.size() == 0)
				{
					throw MathRuntimeEvaluatorException(
"Malformed expression - not enough parameters."
						);
				}
				parameters.push_front(expressionStack.top());
				expressionStack.pop();
			}

			// Extract the parameter values into a vector of doubles
			vector<double> parameterValues;
			for (list<shared_ptr<Expression>>::iterator iter = parameters.begin();
				iter != parameters.end();
				iter++)
			{
				double val = (*iter)->Simplify(workingMemory)->GetValue();
				parameterValues.push_back(val);
			}

			// Evaluate the operation and push the result onto the expressionStack
			PushFront(operation->Evaluate(parameterValues));
		} while (expressionStack.size() > 1 || Size() > 1);

		// Ensure there's exactly one term left
		if (expressionStack.size() != 0)
		{
			throw MathRuntimeEvaluatorException("Improperly formed CompoundExpression.");
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
		throw MathRuntimeEvaluatorException(
"Cannot get the value of a CompoundExpression with more than one term."
			);
		}

		return (*FrontExpression()).GetValue();
	}
	
	// Gets a string representation of this object
	string& CompoundExpression::GetStringRepresentation()
	{
		return GetInfixStringRepresentation();
	}

	string& CompoundExpression::GetInfixStringRepresentation()
	{
		int index = 0;
		stack<string> stringStack;
		while (index < Size())
		{
			// If the next term is an expression, collect it
			if (CheckAtType(index) != ExpressionComponent::Operation)
			{
				stringStack.push(
					(*(AtExpression(index++))).GetStringRepresentation()
					);
				continue;
			}

			// Otherwise, it's an operation, so extract it and print this
			// component of the CompoundExpression
			shared_ptr<Operation> operation(AtOperation(index++));

			// Get the parameters
			int parameterCount = (*operation).GetParameterCount();
			vector<string> parameterStrings;
			for (int i = 0; i < parameterCount; i++)
			{
				parameterStrings.push_back(stringStack.top());
				stringStack.pop();
			}
			
			// Print the operation and its parameters
			string component;
			if (parameterCount == 1)
			{
				component += (*(operation)).GetStringRepresentation();
				component += "(";
				component += parameterStrings[0];
				component += ")";
			}
			else if (parameterCount == 2)
			{
				component += "(";
				component += parameterStrings[0];
				component += " ";
				component += (*(operation)).GetStringRepresentation();
				component += " ";
				component += parameterStrings[1];
				component += ")";
			}
			stringStack.push(component);
		}

		if (stringStack.size() == 0)
			throw MathRuntimeEvaluatorException(
"There are no parameters in this CompoundExpression."
				);

		return *(new string(stringStack.top()));
	}

	string& CompoundExpression::GetPostfixStringRepresentation()
	{
		stringstream os;
		int expressionsIndex = 0;
		int operationsIndex = 0;
		for (unsigned int i = 0; i < _objectTypes.size(); i++)
		{
			if (_objectTypes.at(i) == ExpressionComponent::Expression)
			{
				(*_expressions.at(expressionsIndex++)).Print(os);
			}
			else if (_objectTypes.at(i) == ExpressionComponent::Operation)
			{
				(*_operations.at(operationsIndex++)).Print(os);
			}
			if (i < _objectTypes.size() - 1)
				os << ' ';
		}
		return *(new string(os.str()));
	}
}