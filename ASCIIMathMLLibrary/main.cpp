#include <iostream>
#include <stack>
#include <memory>

#include "WorkingMemory.h"
#include "Exception.h"

using namespace ASCIIMathMLLibrary;

int main()
{
	WorkingMemory memory;

	// Proof of concept for WorkingMemory
	memory.SetValue("a", 1);
	memory.SetValue("d", 2);
	memory.SetValue("c", 9);
	memory.SetValue("b", 5);
	std::cout << memory << std::endl;
	
	// Proof of concept for ExpressionComponents
	//std::stack<std::shared_ptr<ExpressionComponent>> ExpressionComponentStack;
	

	std::cin.get();
}