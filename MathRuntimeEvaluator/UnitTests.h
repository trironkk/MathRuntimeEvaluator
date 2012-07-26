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
	// Parses and evaluates a string expression, and then checks it against an
	// expected value.
	void RunUnitTest(std::string expressionString, double expectedValue);

	// Runs a battery of unit tests
	void RunUnitTestBattery();
}

#endif