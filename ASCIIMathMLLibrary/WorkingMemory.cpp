#include "WorkingMemory.h"

using std::unordered_map;
using std::list;
using std::string;
using std::stringstream;

namespace ASCIIMathMLLibrary
{
	const string WorkingMemory::ILLEGAL_CHARACTERS =
			",./;'[]\\-=`!@#$%^&*()<>?:\"{}|+";

	WorkingMemory::WorkingMemory() :
		_workingMemory(unordered_map<string, double>()),
		_declaredVariables(list<std::string>()) { }
	
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

	string& WorkingMemory::GetStringRepresentation()
	{
		string& result = *(new string());

		// Set the width of the columns to 10 characters longer than the longest
		// variable name
		std::list<string>::iterator iter = std::max_element(
			_declaredVariables.begin(),
			_declaredVariables.end(),
			[] (string left, string	right)
			{
				return left.length() < right.length();
			}
		);
		unsigned int maxLength = 10 + (*iter).length();

		// Write the heading
		result += "Name" + string(maxLength - 4, ' ') + "Value\n";
		result += "----" + string(maxLength - 4, ' ') + "-----\n";

		// String stream for converting double to strings
		stringstream convert;

		// Write every variable and its value
		for (iter = _declaredVariables.begin();
			iter != _declaredVariables.end();
			iter++)
		{
			result += *iter;
			result += string(maxLength - (*iter).length(), ' ');
			convert.str("");
			convert << _workingMemory.at(*(iter));
			result += convert.str();
			result += "\n";
		}

		// Strip off the trailing newline character
		result.resize(result.length() - 1);
		
		return result;
	}
}