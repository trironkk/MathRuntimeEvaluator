#ifndef VALUE_H
#define VALUE_H

#include <string>

namespace MathRuntimeEvaluatorNamespace
{
	class Value
	{
	public:
		// Enumerated types of Values
		enum Type
		{
			RawValue,
			AssignedVariable,
			UnassignedVariable
		};
	
		// Default constructor
		Value();

		// Number constructor
		Value(double val);
		
		// UnassignedVariable and AssignedVariable constructor
		Value(std::string identifier);

		double Number;
		std::string Name;
		Type Type;
	};
}

#endif