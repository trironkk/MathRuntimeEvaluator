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
		Type(Type::UnassignedVariable)
	{
		if (IsDouble(identifier))
		{
			Type = Type::RawValue;
			Number = ToDouble(identifier);
		}
		else if (WorkingMemory::Contains(Name))
		{
			Type = Type::AssignedVariable;
			Number = WorkingMemory::GetValue(Name);
			Name = identifier;
		}
		else
		{
			Type = Type::UnassignedVariable;
			Name = identifier;
		}
	}
}