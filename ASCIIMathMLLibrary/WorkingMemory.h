#ifndef WORKING_MEMORY_H
#define WORKING_MEMORY_H

#include <vector>
#include <algorithm>

#include "Constants.h"
#include "Exception.h"

namespace ASCIIMathMLLibrary
{
	class WorkingMemory
	{
	private:
		WorkingMemoryData _workingMemory;
		DeclaredVariables _declaredVariables;

		static const int MAX_VARIABLE_NAME_LENGTH = 32;
		static const String ILLEGAL_CHARACTERS;
		void ValidateVariableName(String variableName);

	public:
		WorkingMemory();
		bool Contains(String variableName);
		double WorkingMemory::GetValue(String variableName);
		void WorkingMemory::SetValue(String variableName, double value);
		
		friend std::ostream& operator<<(std::ostream& os,
			const WorkingMemory wm);
	};
}

#endif