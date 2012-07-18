#ifndef OPERATOR_H
#define OPERATOR_H

#include <math.h>

#include "Constants.h"
#include "Constant.h"
#include "WorkingMemory.h"
#include "CompoundExpression.h"

namespace ASCIIMathMLLibrary
{
	class CompoundExpression;
	
	// Abstract base class of ExpressionComponent - represents a operator
	class Operator : public IPrintable
	{
	public:
		// Basic Constructor
		Operator();

		// Performs this operation
		virtual shared_ptr<Expression> Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters) = 0;

		// Returns the number of parameters involved in this object
		virtual int GetParameterCount() = 0;
	
		// Gets a string representation of this operation
		virtual string GetStringRepresentation() = 0;

	protected:
		// Calls GetValue() on each of the parameters, and returns a vector of
		// results
		shared_ptr<vector<double>> Operator::GetValuesFromParameters(
			const list<shared_ptr<Expression>>& parameters,
			const WorkingMemory& workingMemory);
	};
}

#endif