#include <iostream>
#include <string>
#include <stack>
#include <memory>

#include "Operator.h"
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
	Parser::LaunchInterpreter();
}