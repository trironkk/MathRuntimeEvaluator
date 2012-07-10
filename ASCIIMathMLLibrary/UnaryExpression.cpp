#include "UnaryExpression.h"

namespace ASCIIMathMLLibrary
{
	UnaryExpression::UnaryExpression() :
		_variableData(VariableExpressionData()),
		_involvedVariables(InvolvedVariables())
	{
		_variableData[""] = 0;
		_involvedVariables.push_back("");
	}

	SharedExpressionPointer UnaryExpression::Evaluate(WorkingMemory& wm)
	{
		InvolvedVariables::iterator iter = _involvedVariables.begin();
		while (iter != _involvedVariables.end())
		{
			if (*iter == "")
			{
				iter++;
				continue;	
			}
			
			if (wm.Contains(*iter) && _variableData[*iter] != 0)
			{
				_variableData[""] += _variableData[*iter] * wm.GetValue(*iter);
				_variableData[*iter] = 0;
			}

			iter++;
		}
		return SharedExpressionPointer(this);
	}

	void UnaryExpression::AddVariableCoefficient(String variableName,
		double coefficient)
	{
		if (_variableData.find(variableName) == _variableData.end())
		{
			DeclaredVariables::iterator iter = _involvedVariables.begin();
			if (_involvedVariables.size() > 0)
				while (iter != _involvedVariables.end() && (*(iter)) < variableName)
					iter++;
			_involvedVariables.insert(iter, variableName);
		}
		_variableData[variableName] = coefficient;
	}

	std::ostream& operator<<(std::ostream& os, const UnaryExpression ue)
	{
		bool printed = false;
		InvolvedVariables::const_iterator iter;
		for (iter = ue._involvedVariables.begin();
			iter != ue._involvedVariables.end();
			)
		{
			if (*iter == "" || ue._variableData.at(*iter) == 0)
			{
				iter++;
				continue;
			}
			os << ue._variableData.at(*(iter));
			os << *(iter);
			printed = true;
			if (!(++iter == ue._involvedVariables.end()))
				os << " + ";
		}

		if (*(ue._involvedVariables.begin()) == "" &&
			(ue._variableData.at("") != 0 || ue._involvedVariables.size() == 1))
		{
			if (ue._involvedVariables.size() > 1 && printed)
				os << " + ";
			os << ue._variableData.at("");
		}

		return os;
	}

}