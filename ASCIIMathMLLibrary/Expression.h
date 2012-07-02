#ifndef EXRESSION_H
#define EXRESSION_H

#include <memory>

#include "Constants.h"

namespace ASCIIMathMLLibrary
{
	// Abstract class that represents a generic expression
	class Expression
	{
	public:
		virtual SharedExpressionPointer Evaluate() = 0;
	};
	
	// Abstract class that represents an expression of only one term
	class UnaryExpression : public Expression { };

	// Class that represents a variable
	class Variable : public UnaryExpression
	{
	private:
		string _variable_name;
	public:
		Variable(string variable_name);
		string GetVariableName();
	};

	// Class that represents a concrete value
	class Value : public UnaryExpression
	{
	private:
		double _value;
	public:
		Value(double value);
	};

	// Class that represents a left hand side, a right hand side, and an operation
	class BinaryExpression : public Expression
	{
	private:
		SharedExpressionPointer _left_hand_side;
		SharedExpressionPointer _right_hand_side;
		Operation _operation;
	public:
		BinaryExpression(
			SharedExpressionPointer l,
			SharedExpressionPointer r,
			Operation o
		);
	};
}

#endif