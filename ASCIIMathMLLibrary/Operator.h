#ifndef OPERATOR_H
#define OPERATOR_H

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

		// Write a friendly string representation of this object to the inputed
		// ostream
		virtual std::ostream& Print(std::ostream& os) = 0;

		// Returns the number of parameters involved in this operation
		virtual int GetParameterCount() = 0;
	
	protected:
		// Calls GetValue() on each of the parameters, and returns a vector of
		// results
		shared_ptr<vector<double>> Operator::GetValuesFromParameters(
			const list<shared_ptr<Expression>>& parameters,
			const WorkingMemory& workingMemory);
	};
}

#endif