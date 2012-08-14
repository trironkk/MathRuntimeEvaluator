#ifndef VALUE_H
#define VALUE_H

#include <string>

namespace MathRuntimeEvaluator
{
	class Value
	{
		// Enumerated types of Values
		enum Type
		{
			Number,
			AssignedVariable,
			UnassignedVariable
		}
		
		// Number constructor
		Value(double val);

		// UnassignedVariable and AssignedVariable constructor
		Value(std::string name);


	};
}

#endif