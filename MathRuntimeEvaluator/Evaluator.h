#ifndef EVALUATOR_H
#define	EVALUATOR_H

#include <deque>
#include <stack>
#include <sstream>

#include "MathRuntimeEvaluatorException.h"
#include "Expression.h"

using std::deque;
using std::stack;
using std::vector;
using std::istringstream;
using std::shared_ptr;

namespace MathRuntimeEvaluator
{
namespace Evaluator
{
	double Evaluate(Expression expression)
	{
		// Handle the case of having no items in the stack
		if (expression.Size() == 0)
		{
			throw MathRuntimeEvaluatorException(
"Cannot simplify an expression with 0 terms."
				);
		}

		// Handle the case of having unresolved variable names
		if (expression.VariablesSize() > 0)
		{
			throw MathRuntimeEvaluatorException(
"Undefined variables detected."
				);
		}

		// Handle the case of the compound expression not containing an operator
		if (expression.OperationsSize() == 0)
		{
			if (expression.ValuesSize() > 1)
				throw MathRuntimeEvaluatorException(
	"No operator present."
				);

			return expression.FrontValue();
		}

		// Holds the values
		stack<double> valuesStack;

		// Reduce the expression to one term
		do
		{
			// Collect Expressions until an operator is encountered
			while(expression.FrontType() != ExpressionComponent::Operation)
			{
				valuesStack.push(expression.FrontValue());
				expression.PopFrontValue();
			}

			// Get the operation
			shared_ptr<Operation> operation(expression.FrontOperation());
			expression.PopFrontOperation();

			// Get the parameters
			int parameterCount = (*operation).GetParameterCount();
			deque<double> parameters;

			// Handle the case of an indefinite number of parameters. All we need
			// to do is get the actual parameter count, which we recorded as the
			// first parameter to be popped off the stack when we parsed the
			// expression.
			if (parameterCount == -1)
			{
				parameterCount = (int)valuesStack.top();
				valuesStack.pop();
			}

			// Pass the appropriate number of parameters from the valuesStack
			// to the parameter list
			for (int i = 0; i < parameterCount; i++)
			{
				if (valuesStack.size() == 0)
				{
					throw MathRuntimeEvaluatorException(
	"Malformed expression - not enough parameters."
						);
				}
				parameters.push_front(valuesStack.top());
				valuesStack.pop();
			}

			// Evaluate the operation and push the result onto the expressionStack
			expression.PushFront(operation->Evaluate(parameters));
		} while (valuesStack.size() > 1 || expression.Size() > 1);

		// Ensure there's exactly one term left
		if (valuesStack.size() != 0)
		{
			throw MathRuntimeEvaluatorException("Improperly formed CompoundExpression.");
		}

		// Return the first term in the underlying Expression deque
		return expression.FrontValue();
	}
}
}

#endif