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
		else if (WorkingMemory::Contains(Name))
		{
			Type = AssignedVariable;
			Number = WorkingMemory::GetValue(Name);
			Name = identifier;
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
}