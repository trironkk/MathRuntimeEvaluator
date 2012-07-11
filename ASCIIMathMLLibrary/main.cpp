#include <iostream>

#include "WorkingMemory.h"
#include "ExpressionComponent.h"
#include "Exception.h"

using namespace ASCIIMathMLLibrary;

int main()
{
	WorkingMemory memory;

	// Initialize some variable values
	memory.SetValue("a", 1);
	memory.SetValue("d", 2);
	memory.SetValue("c", 9);
	memory.SetValue("b", 5);
	std::cout << memory << std::endl;

	// Put together some UnaryExpressions
	//UnaryExpression expression1;
	//expression1.AddVariableCoefficient("a", 5);
	//std::cout << expression1 << std::endl;

	//UnaryExpression expression2;
	//expression2.AddVariableCoefficient("a", 5);
	//expression2.AddVariableCoefficient("", -15);
	//expression2.AddVariableCoefficient("b", -2.5);
	//std::cout << expression2 << std::endl;

	//UnaryExpression expression3;
	//expression3.AddVariableCoefficient("", 57);
	//std::cout << expression3 << std::endl;

	//UnaryExpression expression4;
	//expression4.AddVariableCoefficient("a", 5);
	//expression4.AddVariableCoefficient("", 0);
	//expression4.AddVariableCoefficient("b", -2.5);
	//std::cout << expression4 << std::endl;
	//
	//UnaryExpression expression5;
	//expression5.AddVariableCoefficient("", 0);
	//std::cout << expression5 << std::endl;

	//UnaryExpression expression6;
	//expression6.AddVariableCoefficient("a", 5);
	//expression6.AddVariableCoefficient("", 5);
	//expression6.AddVariableCoefficient("b", -2.5);
	//SharedExpressionPointer s = expression6.Evaluate(memory);
	//std::cout << dynamic_cast<UnaryExpression&>(*(s.get())) << std::endl;

	std::cin.get();
}