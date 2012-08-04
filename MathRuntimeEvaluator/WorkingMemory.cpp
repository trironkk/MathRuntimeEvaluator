#include "WorkingMemory.h"

using std::unordered_map;
using std::list;
using std::string;
using std::stringstream;

namespace MathRuntimeEvaluator
{
	// Default constructor
	WorkingMemory::WorkingMemory() :
		_workingMemory(unordered_map<string, double>()),
		_declaredVariables(list<std::string>()) { }
	
	// Returns true if the variable has been declared, and false otherwise.
	bool WorkingMemory::Contains(string variableName) const
	{
		return _workingMemory.find(variableName) != _workingMemory.end();
	}

	// Returns the double value associated with a variable name.
	double WorkingMemory::GetValue(string variableName) const
	{
		return _workingMemory.at(variableName);
	}

	// Sets the double value associated with a variable name.
	void WorkingMemory::SetValue(string variableName, double value)
	{
		// Validate that the variable name is valid. Throw an exception if it
		// isn't.
		ValidateVariableName(variableName);

		// If it's a new variable name...
		if (_workingMemory.find(variableName) == _workingMemory.end())
		{
			// Maintain the alphabetical ordering of the list...
			std::list<std::string>::iterator iter = _declaredVariables.begin();
			if (_declaredVariables.size() > 0)
				while (iter != _declaredVariables.end() && (*(iter)) <
						variableName)
				{
					iter++;
				}
			_declaredVariables.insert(iter, variableName);
		}

		// Perform the actual assignment.
		_workingMemory[variableName] = value;
	}

	// Throws an MathRuntimeEvaluatorException if the variable name is invalid.
	// Otherwise, simply returns.
	void WorkingMemory::ValidateVariableName(string variableName)
	{
		// Assert that the variable name is not too long...
		if (variableName.length() > MAX_VARIABLE_NAME_LENGTH)
		{
			throw MathRuntimeEvaluatorException(
				"The variable name's length is longer than 32 characters.\n"
			);
		}
		
		// Assert that the variable name is not too short...
		if (variableName.length() < 1)
		{
			throw MathRuntimeEvaluatorException(
				"The variable name's must be at least one character.\n"
			);
		}
		
		// Assert that the variable name does not contain illegal characters...
		for (std::string::iterator iter = variableName.begin();
										iter < variableName.end();
										iter++)
		{
			if (strchr(ILLEGAL_CHARACTERS, *iter) != NULL)
			{
				throw MathRuntimeEvaluatorException(
					"The variable name contains one or more illegal characters.\n"
				);
			}
			char* i = ",./;'[]\\-=`!@#$%^&*()<>?:\"{}|+";
			
		}

		// Assert that the variable name does not begin with a number...
		if (isdigit(*variableName.begin()))
		{
			throw MathRuntimeEvaluatorException(
				"The variable name begins with a digit.\n"
			);
		}
	}

	// Returns a string representation of the working memory.
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
		unsigned int maxLength = 10;
		if (iter != _declaredVariables.end())
			maxLength += (*iter).length();

		// Write the heading
		result += "\n";
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

		return result;
	}
}