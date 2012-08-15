#include "Value.h"

#include "WorkingMemory.h"

using std::string;

namespace MathRuntimeEvaluatorNamespace
{
	// Number constructor
	Value::Value(double val) :
		Number(val),
		Name(""),
		Type(Type::RawValue)
	{ }

	// UnassignedVariable and AssignedVariable constructor
	Value::Value(string name) :
		Number(0),
		Name(name),
		Type(Type::UnassignedVariable)
	{
		if (WorkingMemory::Contains(Name))
		{
			Number = WorkingMemory::GetValue(Name);
			Type = Type::AssignedVariable;
		}
	}
}