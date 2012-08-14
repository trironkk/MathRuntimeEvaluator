#include "Value.h"

#include "WorkingMemory.h"

using std::string;

namespace MathRuntimeEvaluator
{
	Value::Value(double val) :
		_Number(val),
		_Name(""),
		_Type(Type::Number)
	{ }

	Value::Value(string name) :
		_Number(0),
		_Name(name),
		_Type(Type::UnassignedVariable)
	{
		if (WorkingMemory::Contains(_Name))
		{
			_Number = WorkingMemory::GetValue(_Name);
			_Type = Type::AssignedVariable;
		}
	}
}