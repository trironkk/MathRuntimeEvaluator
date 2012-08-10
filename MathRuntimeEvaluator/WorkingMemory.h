#ifndef WORKING_MEMORY_H
#define WORKING_MEMORY_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>

#include "MathRuntimeEvaluatorException.h"
#include "IPrintable.h"

namespace MathRuntimeEvaluatorNamespace
{
	// The maximum length of a variable name
	int const MAX_VARIABLE_NAME_LENGTH = 32;

	// An array of illegal characters
	const char* const ILLEGAL_CHARACTERS =
			",./;'[]\\-=`!@#$%^&*()<>?:\"{}|+";

	class WorkingMemory : public IPrintable
	{
	private:
		// The underlying hash map relating variable names to double values.
		std::unordered_map<std::string, double> _workingMemory;

		// A linked list of all declared variables.
		std::list<std::string> _declaredVariables;

	public:
		// Default constructor.
		WorkingMemory();

		// Returns true if the variable has been declared, and false otherwise.
		bool Contains(std::string variableName) const;

		// Returns the double value associated with a variable name.
		double WorkingMemory::GetValue(std::string variableName) const;

		// Sets the double value associated with a variable name.
		void WorkingMemory::SetValue(std::string variableName, double value);

		// Throws an MathRuntimeEvaluatorException if the variable name is
		// invalid. Otherwise, simply returns
		void ValidateVariableName(std::string variableName);

		// Returns a string representation of the working memory.
		virtual std::string GetStringRepresentation();
	};
}

#endif