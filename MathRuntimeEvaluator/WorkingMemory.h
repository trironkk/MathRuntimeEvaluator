#ifndef WORKING_MEMORY_H
#define WORKING_MEMORY_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>

#include "MathRuntimeEvaluatorException.h"
#include "IPrintable.h"

// The maximum length of a variable name
int const MAX_VARIABLE_NAME_LENGTH = 32;

// An array of illegal characters
const char* const ILLEGAL_CHARACTERS =
		",./;'[]\\-=`!@#$%^&*()<>?:\"{}|+";

class __declspec(dllexport) WorkingMemory
{
private:
	// Get a singleton instance, which persists in this method's static scope
	static std::unordered_map<std::string, double>& GetMap();
	static std::list<std::string>& GetVariableList();

	// Default constructor - Hidden to follow the Singleton pattern
	WorkingMemory();

public:
	// Returns true if the variable has been declared, and false otherwise.
	static bool Contains(std::string variableName);

	// Returns the double value associated with a variable name.
	static double WorkingMemory::GetValue(std::string variableName);

	// Sets the double value associated with a variable name.
	static void WorkingMemory::SetValue(std::string variableName,
		double value);

	// Throws an MathRuntimeEvaluatorException if the variable name is
	// invalid. Otherwise, simply returns
	static void ValidateVariableName(std::string variableName);

	// The same methods that IPrintable implements, but staticly declared, so
	// that the same conventions for printing can be used.
	static std::ostream& Print(std::ostream& os);
	static std::ostream& PrintLine(std::ostream& os);
	static std::string GetStringRepresentation();
};

#endif