#include <iostream>

#include "WorkingMemory.h"

namespace ASCIIMathMLLibrary
{
	const string WorkingMemory::ILLEGAL_CHARACTERS =
			",./;'[]\\-=`!@#$%^&*()<>?:\"{}|+";

	WorkingMemory::WorkingMemory() :
		_workingMemory(std::unordered_map<std::string, double>()),
		_declaredVariables(std::list<std::string>()) { }
	
	bool WorkingMemory::Contains(string variableName) const
	{
		return _workingMemory.find(variableName) != _workingMemory.end();
	}

	double WorkingMemory::GetValue(string variableName) const
	{
		return _workingMemory.at(variableName);
	}

	void WorkingMemory::SetValue(string variableName, double value)
	{
		ValidateVariableName(variableName);
		if (_workingMemory.find(variableName) == _workingMemory.end())
		{
			std::list<std::string>::iterator iter = _declaredVariables.begin();
			if (_declaredVariables.size() > 0)
				while (iter != _declaredVariables.end() && (*(iter)) < variableName)
					iter++;
			_declaredVariables.insert(iter, variableName);
		}
		_workingMemory[variableName] = value;
	}

	void WorkingMemory::ValidateVariableName(string variableName)
	{
		if (variableName.length() > MAX_VARIABLE_NAME_LENGTH)
		{
			throw ASCIIMathMLException(
				"The variable name's length is longer than 32 characters.\n"
			);
		}
		
		if (variableName.length() < 1)
		{
			throw ASCIIMathMLException(
				"The variable name's must be at least one character.\n"
			);
		}
		
		for (std::string::iterator iter = variableName.begin();
										iter < variableName.end();
										iter++)
		{
			if (ILLEGAL_CHARACTERS.find(*iter) != string::npos)
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
		unsigned int maxLength = 4;
		std::list<std::string>::const_iterator iter;
		for (iter = wm._declaredVariables.begin();
			iter != wm._declaredVariables.end();
			iter++)
		{
			if ((*(iter)).length() > maxLength)
				maxLength = (*(iter)).length();
		}

		maxLength += 6;

		os.width(maxLength);
		os << std::left << "Name";
		os << "Value" << std::endl;
		os.width(maxLength);
		os << std::left << "----";
		os << "------" << std::endl;

		for (iter = wm._declaredVariables.begin();
			iter != wm._declaredVariables.end();
			iter++)
		{
			os.width(maxLength);
			os << (*(iter));
			os << wm._workingMemory.at((*(iter))) << std::endl;
		}
		return os;
	}
}