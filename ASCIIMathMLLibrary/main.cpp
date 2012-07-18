#include <iostream>
#include <stack>
#include <memory>

#include "WorkingMemory.h"

// Operators
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Negate.h"
#include "Exponentiate.h"
#include "NaturalLogarithm.h"
#include "Modulo.h"
#include "CommonLogarithm.h"
#include "Sin.h"
#include "Cos.h"
#include "Tan.h"
#include "AbsoluteValue.h"
#include "SquareRoot.h"

// Expressions
#include "Constant.h"
#include "Variable.h"
#include "CompoundExpression.h"

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
	shared_ptr<Constant> constant1(new Constant(0));
	shared_ptr<Constant> constant2(new Constant(12));
	shared_ptr<Constant> constant3(new Constant(17.37));
	
	// Proof of concept for Variables
	shared_ptr<Variable> variable1(new Variable("a"));
	shared_ptr<Variable> variable2(new Variable("b"));
	shared_ptr<Variable> variable3(new Variable("c"));
	shared_ptr<Variable> variable4(new Variable("d"));
	
	// Proof of concept for Operators
	shared_ptr<Add> add(new Add());
	shared_ptr<Subtract> subtract(new Subtract());
	shared_ptr<Multiply> multiply(new Multiply());
	shared_ptr<Divide> divide(new Divide());
	shared_ptr<Negate> negate(new Negate());
	shared_ptr<Exponentiate> exponentiate(new Exponentiate());
	shared_ptr<NaturalLogarithm> naturalLogarithm(new NaturalLogarithm());
	shared_ptr<Modulo> modulo(new Modulo());
	shared_ptr<CommonLogarithm> commonLogarithm(new CommonLogarithm());
	shared_ptr<Sin> sin(new Sin());
	shared_ptr<Cos> cos(new Cos());
	shared_ptr<Tan> tan(new Tan());
	shared_ptr<AbsoluteValue> absoluteValue(new AbsoluteValue());
	shared_ptr<SquareRoot> squareRoot(new SquareRoot());

	// Proof of concept for CompoundExpressions
	cout << "compoundExpression1" << std::endl;
	CompoundExpression compoundExpression1;
	compoundExpression1.PushBack("a");
	compoundExpression1.PushBack(4);
	compoundExpression1.PushBack<Add>();
	compoundExpression1.Print(cout);
	cout << " = ";
	compoundExpression1.Simplify(memory);
	compoundExpression1.PrintLine(cout);

	cout << "compoundExpression2" << std::endl;
	CompoundExpression compoundExpression2;
	compoundExpression2.PushBack(constant3);
	compoundExpression2.PushBack(constant2);
	compoundExpression2.PushBack(add);
	compoundExpression2.PushBack(variable3);
	compoundExpression2.PushBack(variable2);
	compoundExpression2.PushBack(add);
	compoundExpression2.PushBack(add);
	compoundExpression2.Print(std::cout);
	cout << " = ";
	compoundExpression2.Simplify(memory);
	compoundExpression2.PrintLine(cout);

	cout << "compoundExpression3" << std::endl;
	CompoundExpression compoundExpression3;
	compoundExpression3.PushBack(variable3);
	compoundExpression3.PushBack(variable2);
	compoundExpression3.PushBack(subtract);
	compoundExpression3.Print(cout);
	cout << " = ";
	compoundExpression3.Simplify(memory);
	compoundExpression3.PrintLine(cout);

	cout << "compoundExpression4" << std::endl;
	CompoundExpression compoundExpression4;
	compoundExpression4.PushBack(constant3);
	compoundExpression4.PushBack(constant2);
	compoundExpression4.PushBack(subtract);
	compoundExpression4.PushBack(variable3);
	compoundExpression4.PushBack(subtract);
	compoundExpression4.PushBack(variable2);
	compoundExpression4.PushBack(subtract);
	compoundExpression4.Print(std::cout);
	cout << " = ";
	compoundExpression4.Simplify(memory);
	compoundExpression4.PrintLine(cout);

	cout << "compoundExpression5" << std::endl;
	CompoundExpression compoundExpression5;
	compoundExpression5.PushBack(variable3);
	compoundExpression5.PushBack(variable4);
	compoundExpression5.PushBack(multiply);
	compoundExpression5.Print(cout);
	cout << " = ";
	compoundExpression5.Simplify(memory);
	compoundExpression5.PrintLine(cout);

	cout << "compoundExpression6" << std::endl;
	CompoundExpression compoundExpression6;
	compoundExpression6.PushBack(variable3);
	compoundExpression6.PushBack(variable4);
	compoundExpression6.PushBack(divide);
	compoundExpression6.Print(cout);
	cout << " = ";
	compoundExpression6.Simplify(memory);
	compoundExpression6.PrintLine(cout);

	cout << "compoundExpression7" << std::endl;
	CompoundExpression compoundExpression7;
	compoundExpression7.PushBack(constant3);
	compoundExpression7.PushBack(negate);
	compoundExpression7.PushBack(constant3);
	compoundExpression7.PushBack(add);
	compoundExpression7.Print(cout);
	cout << " = ";
	compoundExpression7.Simplify(memory);
	compoundExpression7.PrintLine(cout);

	cout << "compoundExpression8" << std::endl;
	CompoundExpression compoundExpression8;
	compoundExpression8.PushBack(constant3);
	compoundExpression8.PushBack(variable4);
	compoundExpression8.PushBack(exponentiate);
	compoundExpression8.Print(cout);
	cout << " = ";
	compoundExpression8.Simplify(memory);
	compoundExpression8.PrintLine(cout);

	cout << "compoundExpression9" << std::endl;
	CompoundExpression compoundExpression9;
	compoundExpression9.PushBack(constant3);
	compoundExpression9.PushBack(naturalLogarithm);
	compoundExpression9.Print(cout);
	cout << " = ";
	compoundExpression9.Simplify(memory);
	compoundExpression9.PrintLine(cout);

	cout << "compoundExpression10" << std::endl;
	CompoundExpression compoundExpression10;
	compoundExpression10.PushBack(variable3);
	compoundExpression10.PushBack(variable2);
	compoundExpression10.PushBack(modulo);
	compoundExpression10.Print(cout);
	cout << " = ";
	compoundExpression10.Simplify(memory);
	compoundExpression10.PrintLine(cout);

	cout << "compoundExpression11" << std::endl;
	CompoundExpression compoundExpression11;
	compoundExpression11.PushBack(variable2);
	compoundExpression11.PushBack(commonLogarithm);
	compoundExpression11.Print(cout);
	cout << " = ";
	compoundExpression11.Simplify(memory);
	compoundExpression11.PrintLine(cout);

	cout << "compoundExpression12" << std::endl;
	CompoundExpression compoundExpression12;
	compoundExpression12.PushBack(variable1);
	compoundExpression12.PushBack(sin);
	compoundExpression12.Print(cout);
	cout << " = ";
	compoundExpression12.Simplify(memory);
	compoundExpression12.PrintLine(cout);

	cout << "compoundExpression13" << std::endl;
	CompoundExpression compoundExpression13;
	compoundExpression13.PushBack(variable1);
	compoundExpression13.PushBack(cos);
	compoundExpression13.Print(cout);
	cout << " = ";
	compoundExpression13.Simplify(memory);
	compoundExpression13.PrintLine(cout);

	cout << "compoundExpression14" << std::endl;
	CompoundExpression compoundExpression14;
	compoundExpression14.PushBack(variable1);
	compoundExpression14.PushBack(tan);
	compoundExpression14.Print(cout);
	cout << " = ";
	compoundExpression14.Simplify(memory);
	compoundExpression14.PrintLine(cout);

	cout << "compoundExpression15" << std::endl;
	CompoundExpression compoundExpression15;
	compoundExpression15.PushBack(variable2);
	compoundExpression15.PushBack(variable3);
	compoundExpression15.PushBack(subtract);
	compoundExpression15.PushBack(absoluteValue);
	compoundExpression15.Print(cout);
	cout << " = ";
	compoundExpression15.Simplify(memory);
	compoundExpression15.PrintLine(cout);

	cout << "compoundExpression16" << std::endl;
	CompoundExpression compoundExpression16;
	compoundExpression16.PushBack(variable3);
	compoundExpression16.PushBack(squareRoot);
	compoundExpression16.Print(cout);
	cout << " = ";
	compoundExpression16.Simplify(memory);
	compoundExpression16.PrintLine(cout);

	std::cin.get();
}