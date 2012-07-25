#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <iostream>
#include <string>
#include <stack>
#include <memory>
#include <math.h>

// Operators
#include "Operator.h"

// Expressions
#include "Constant.h"
#include "Variable.h"
#include "CompoundExpression.h"

#include "Parser.h"
#include "Exception.h"
#include "WorkingMemory.h"

namespace UnitTests
{
	void RunUnitTest(std::string expressionString, double expectedValue);
	void RunUnitTestBattery();
}

#endif