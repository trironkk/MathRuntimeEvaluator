#include "WorkingMemory.h"

using std::unordered_map;
using std::list;
using std::string;
using std::stringstream;

// Get a singleton instance fields, which persists through the methods' static
//scope
std::unordered_map<std::string, double>& WorkingMemory::GetMap()
{
	static std::unordered_map<std::string, double> map;
	return map;
}
std::list<std::string>& WorkingMemory::GetVariableList()
{
	static std::list<std::string> declaredVariables;
	return declaredVariables;
}

// Returns true if the variable has been declared, and false otherwise.
bool WorkingMemory::Contains(string variableName)
{
	return GetMap().find(variableName) != GetMap().end();
}

// Returns the double value associated with a variable name.
double WorkingMemory::GetValue(string variableName)
{
	return GetMap().at(variableName);
}

// Sets the double value associated with a variable name.
void WorkingMemory::SetValue(string variableName, double value)
{
	// Validate that the variable name is valid. Throw an exception if it
	// isn't.
	WorkingMemory::ValidateVariableName(variableName);

	// If it's a new variable name...
	if (GetMap().find(variableName) == GetMap().end())
	{
		// Maintain the alphabetical ordering of the list...
		std::list<std::string>::iterator iter = GetVariableList().begin();
		if (GetVariableList().size() > 0)
			while (iter != GetVariableList().end() && (*(iter)) <
					variableName)
			{
				iter++;
			}
		GetVariableList().insert(iter, variableName);
	}

	// Perform the actual assignment.
	GetMap()[variableName] = value;
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

// The same methods that IPrintable implements, but staticly declared, so
// that the same conventions for printing can be used.
std::ostream& WorkingMemory::Print(std::ostream& os)
{
	return os << WorkingMemory::GetStringRepresentation();
}
std::ostream& WorkingMemory::PrintLine(std::ostream& os)
{
	WorkingMemory::Print(os);
	return os << std::endl;
}
std::string WorkingMemory::GetStringRepresentation()
{
	string result = "";

	// Set the width of the columns to 10 characters longer than the longest
	// variable name
	std::list<string>::iterator iter = std::max_element(
		GetVariableList().begin(),
		GetVariableList().end(),
		[] (string left, string	right)
		{
			return left.length() < right.length();
		}
	);
	unsigned int maxLength = 10;
	if (iter != GetVariableList().end())
		maxLength += (*iter).length();

	// Write the heading
	result += "\n";
	result += "Name" + string(maxLength - 4, ' ') + "Value\n";
	result += "----" + string(maxLength - 4, ' ') + "-----\n";

	// String stream for converting double to strings
	stringstream convert;

	// Write every variable and its value
	for (iter = GetVariableList().begin();
		iter != GetVariableList().end();
		iter++)
	{
		result += *iter;
		result += string(maxLength - (*iter).length(), ' ');
		convert.str("");
		convert << GetMap().at(*(iter));
		result += convert.str();
		result += "\n";
	}

	return result;
}
