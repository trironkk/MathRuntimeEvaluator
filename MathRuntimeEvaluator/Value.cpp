#include "Value.h"

#include "WorkingMemory.h"
#include "Utilities.h"

using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Identifier constructor
	Value::Value(string identifier) :
		Number(0),
		Name(""),
		Type(UnassignedVariable)
	{
		if (IsDouble(identifier))
		{
			Type = RawValue;
			Number = ToDouble(identifier);
		}
		else if (WorkingMemory::Contains(identifier))
		{
			Type = AssignedVariable;
			Name = identifier;
			Number = WorkingMemory::GetValue(Name);
		}
		else
		{
			Type = UnassignedVariable;
			Name = identifier;
		}
	}

	// RawValue constructor
	Value::Value(double value) :
		Number(value),
		Name(""),
		Type(RawValue)
	{
	}

	// Get a string representation of the Value's type
	std::string Value::GetTypeString() const
	{
		switch(Type)
		{
		case Value::RawValue:
			return "RawValue";
		case Value::AssignedVariable:
			return "AssignedVariable";
		case Value::UnassignedVariable:
			return "UnassignedVariable";
		}
	}

	// Gets a string representation of this object
	std::string Value::GetStringRepresentation()
	{
		switch(Type)
		{
		case Value::RawValue:
			return "Value: " + ToString(Number);
		case Value::AssignedVariable:
			return "Value: " + Name + " = " + ToString(Number);
		case Value::UnassignedVariable:
			return "Value: " + Name;
		}
	}
}