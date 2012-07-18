#ifndef WORKING_MEMORY_H
#define WORKING_MEMORY_H

#include <vector>
#include <algorithm>

#include "Constants.h"
#include "Exception.h"
#include "IPrintable.h"

namespace ASCIIMathMLLibrary
{
	class WorkingMemory : public IPrintable
	{
	private:
		std::unordered_map<string, double> _workingMemory;
		std::list<string> _declaredVariables;

		static const int MAX_VARIABLE_NAME_LENGTH = 32;
		static const string ILLEGAL_CHARACTERS;
		void ValidateVariableName(string variableName);

	public:
		WorkingMemory();
		bool Contains(string variableName) const;
		double WorkingMemory::GetValue(string variableName) const;
		void WorkingMemory::SetValue(string variableName, double value);

		virtual string& GetStringRepresentation();
	};
}

#endif