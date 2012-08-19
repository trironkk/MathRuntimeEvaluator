#ifndef VALUE_H
#define VALUE_H

#include <string>

#include "IPrintable.h"

namespace MathRuntimeEvaluatorNamespace
{
	class Value : public IPrintable
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

		// Identifier constructor
		Value(std::string identifier);

		// RawValue constructor
		Value(double value);

		// Get a string representation of the Value's type
		std::string GetTypeString() const;
		
		// Gets a string representation of this object
		virtual std::string GetStringRepresentation();

		double Number;
		std::string Name;
		Type Type;
	};
}

#endif