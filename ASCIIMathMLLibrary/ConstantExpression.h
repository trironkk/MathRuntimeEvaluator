#ifndef CONSTANT_EXRESSION_H
#define CONSTANT_EXRESSION_H

#include <memory>

#include "Constants.h"
#include "UnaryExpression.h"

namespace ASCIIMathMLLibrary
{
	// Class that represents a concrete value
	class ConstantExpression: public UnaryExpression
	{
	private:
		double _value;
	public:
		ConstantExpression(double value);
		virtual SharedExpressionPointer
			ConstantExpression::Evaluate(WorkingMemory& wm);
	};
}

#endif