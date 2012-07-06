#include <iostream>

#include "WorkingMemory.h"

namespace ASCIIMathMLLibrary
{
	const String WorkingMemory::ILLEGAL_CHARACTERS =
			",./;'[]\\-=`!@#$%^&*()<>?:\"{}|+";

	WorkingMemory::WorkingMemory() :
		_workingMemory(WorkingMemoryData()),
		_declaredVariables(std::vector<String>()) { }
	
	bool WorkingMemory::Contains(String variableName)
	{
		return _workingMemory.find(variableName) != _workingMemory.end();
	}

	double WorkingMemory::GetValue(String variableName)
	{
		return _workingMemory[variableName];
	}

	void WorkingMemory::SetValue(String variableName, double value)
	{
		ValidateVariableName(variableName);
		if (_workingMemory.find(variableName) == _workingMemory.end())
		{
			_declaredVariables.push_back(variableName);
		}
		_workingMemory[variableName] = value;
	}

	void WorkingMemory::ValidateVariableName(String variableName)
	{
		if (variableName.length() > MAX_VARIABLE_NAME_LENGTH)
		{
			throw ASCIIMathMLException(
				"The variable name's length is longer than 32 characters.\n"
			);
		}
		
		for (std::string::iterator iter = variableName.begin();
										iter < variableName.end();
										iter++)
		{
			if (ILLEGAL_CHARACTERS.find(*iter) != String::npos)
			{
				throw ASCIIMathMLException(
					"The variable name contains one or more illegal characters.\n"
				);
			}
		}

		if (isdigit(*variableName.begin()))
		{
			throw ASCIIMathMLException(
				"The variable name begins with a digit.\n"
			);
		}
	}

	std::ostream& operator<<(std::ostream& os, const WorkingMemory wm)
	{
		int maxLength = 4;
		for (int i = 0; i < wm._declaredVariables.size(); i++)
		{
			if (maxLength < wm._declaredVariables[i].length())
				maxLength = wm._declaredVariables[i].length();
		}

		maxLength += 6;

		os.width(maxLength);
		os << std::left << "Name";
		os << "Value" << std::endl;
		os.width(maxLength);
		os << std::left << "----";
		os << "------" << std::endl;


		for (int i = 0; i < wm._declaredVariables.size(); i++)
		{
			os.width(maxLength);
			os << wm._declaredVariables[i];
			os << wm._workingMemory.at(wm._declaredVariables[i]) << std::endl;
		}
		return os;
	}
}