#include <iostream>

#include "WorkingMemory.h"

#include "VariableExpression.h"
#include "Exception.h"

using namespace ASCIIMathMLLibrary;

int main()
{
	WorkingMemory memory;
	
	// Simple expression: "a = 56"
	memory.SetValue("a", 56);

	// Let's evaluate: "a + 5"
	VariableExpression a("a");


	std::cin.get();
}