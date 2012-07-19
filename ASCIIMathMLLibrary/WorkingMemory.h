#ifndef WORKING_MEMORY_H
#define WORKING_MEMORY_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>

#include "Exception.h"
#include "IPrintable.h"

namespace ASCIIMathMLLibrary
{
	class WorkingMemory : public IPrintable
	{
	private:
		std::unordered_map<std::string, double> _workingMemory;
		std::list<std::string> _declaredVariables;

		static const int MAX_VARIABLE_NAME_LENGTH = 32;
		static const std::string ILLEGAL_CHARACTERS;
		void ValidateVariableName(std::string variableName);

	public:
		WorkingMemory();
		bool Contains(std::string variableName) const;
		double WorkingMemory::GetValue(std::string variableName) const;
		void WorkingMemory::SetValue(std::string variableName, double value);

		virtual std::string& GetStringRepresentation();
	};
}

#endif