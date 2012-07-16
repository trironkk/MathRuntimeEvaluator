#include <iostream>
#include <stack>
#include <memory>

#include "WorkingMemory.h"
#include "Constant.h"
#include "Variable.h"
#include "Exception.h"

using namespace ASCIIMathMLLibrary;

int main()
{
	// Proof of concept for WorkingMemory
	WorkingMemory memory;
	memory.SetValue("a", 1);
	memory.SetValue("d", 2);
	memory.SetValue("c", 9);
	memory.SetValue("b", 5);
	std::cout << memory << std::endl; // TODO: Change to WorkingMemory::Print()
	
	// Proof of concept for Constants
	Constant constant1(0);
	Constant constant2(12);
	Constant constant3(17.37);
	constant1.PrintLine(std::cout);
	constant2.PrintLine(std::cout);
	constant3.PrintLine(std::cout);
	
	// Proof of concept for Variables
	Variable variable1("a");
	Variable variable2("b");
	Variable variable3("c");
	Variable variable4("d");
	variable1.PrintLine(std::cout);
	variable2.PrintLine(std::cout);
	variable3.PrintLine(std::cout);
	variable4.PrintLine(std::cout);
	
	// Proof of concept for Operators



	// Proof of concept for CompoundExpressions


	std::cin.get();
}