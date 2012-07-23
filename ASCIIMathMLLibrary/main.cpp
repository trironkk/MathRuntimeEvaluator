#include <iostream>
#include <string>
#include <stack>
#include <memory>

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

#include "Parser.h"
#include "Exception.h"
#include "WorkingMemory.h"

using namespace ASCIIMathMLLibrary;
using namespace std;

void EvaluateCompoundExpression(CompoundExpression ce, WorkingMemory memory)
{
	ce.Print(cout);
	cout << " = ";
	ce.Simplify(memory);
	ce.PrintLine(cout);
}

int main()
{
	// Proof of concept for WorkingMemory
	WorkingMemory memory;
	memory.SetValue("a", 1);
	memory.SetValue("d", 2);
	memory.SetValue("c", 9);
	memory.SetValue("b", 5);
	memory.PrintLine(cout);
	cout << std::endl;

	CompoundExpression ce1;
	ce1.PushBack("a");
	ce1.PushBack(10);
	ce1.PushBack<Add>();
	EvaluateCompoundExpression(ce1, memory);

	CompoundExpression ce2;
	ce2.PushBack("a");
	ce2.PushBack(10);
	ce2.PushBack<Subtract>();
	EvaluateCompoundExpression(ce2, memory);

	CompoundExpression ce3;
	ce3.PushBack("a");
	ce3.PushBack(10);
	ce3.PushBack<Multiply>();
	EvaluateCompoundExpression(ce3, memory);

	CompoundExpression ce4;
	ce4.PushBack("a");
	ce4.PushBack(10);
	ce4.PushBack<Divide>();
	EvaluateCompoundExpression(ce4, memory);

	std::istringstream s("123.12 + a*b + c * sqrt(4)\n");
	cout << "123.12 + a*b + c * sqrt(4)\n" << std::endl;
	std::string result;
	int i = 0;
	do {
		result = Parser::ReadNextToken(s);
		cout << i++ << "\t" << result << std::endl;
		// We need to update the position of the stringstream. It's not happening.
	} while (result != "");
	delete s;
	std::cin.get();
}