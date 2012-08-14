#ifndef VALUE_H
#define VALUE_H

#include <string>

namespace MathRuntimeEvaluator
{
	class Value
	{
	public:
		// Enumerated types of Values
		enum Type
		{
			Number,
			AssignedVariable,
			UnassignedVariable
		};
	
		// Default constructor
		Value();

		// Number constructor
		Value(double val);
		
		// UnassignedVariable and AssignedVariable constructor
		Value(std::string name);

	private:
		double _Number;
		std::string _Name;
		Type _Type;
	};
}

#endif