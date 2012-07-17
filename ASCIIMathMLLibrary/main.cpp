#include <iostream>
#include <stack>
#include <memory>

#include "WorkingMemory.h"
#include "Constant.h"
#include "Variable.h"
#include "Add.h"
#include "Exception.h"
#include "CompoundExpression.h"

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
	shared_ptr<Constant> constant1(new Constant(0));
	shared_ptr<Constant> constant2(new Constant(12));
	shared_ptr<Constant> constant3(new Constant(17.37));
	(*constant1).PrintLine(std::cout);
	(*constant2).PrintLine(std::cout);
	(*constant3).PrintLine(std::cout);
	
	// Proof of concept for Variables
	shared_ptr<Variable> variable1(new Variable("a"));
	shared_ptr<Variable> variable2(new Variable("b"));
	shared_ptr<Variable> variable3(new Variable("c"));
	shared_ptr<Variable> variable4(new Variable("d"));
	(*variable1).PrintLine(std::cout);
	(*variable2).PrintLine(std::cout);
	(*variable3).PrintLine(std::cout);
	(*variable4).PrintLine(std::cout);
	
	// Proof of concept for Operators
	shared_ptr<Add> add(new Add());
	(*add).PrintLine(std::cout);

	// Proof of concept for CompoundExpressions
	CompoundExpression compoundExpression1;
	compoundExpression1.PushBack(variable1);
	compoundExpression1.PushBack(constant1);
	compoundExpression1.PushBack(add);
	compoundExpression1.PrintLine(std::cout);

	compoundExpression1.Simplify(memory);
	compoundExpression1.PrintLine(std::cout);

	std::cin.get();
}