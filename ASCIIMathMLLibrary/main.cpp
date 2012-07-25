#include <iostream>
#include <string>
#include <stack>
#include <memory>

// Operators
#include "Operator.h"

// Expressions
#include "Constant.h"
#include "Variable.h"
#include "CompoundExpression.h"

#include "Parser.h"
#include "Exception.h"
#include "WorkingMemory.h"
#include "UnitTests.h"
#include "Interpreter.h"

int main()
{
	UnitTests::RunUnitTestBattery();
	Parser::LaunchInterpreter();
}