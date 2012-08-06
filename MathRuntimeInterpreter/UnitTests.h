#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <iostream>
#include <string>
#include <stack>
#include <memory>
#include <math.h>

#include "../MathRuntimeEvaluator/Constant.h"
#include "../MathRuntimeEvaluator/Variable.h"
#include "../MathRuntimeEvaluator/CompoundExpression.h"
#include "../MathRuntimeEvaluator/WorkingMemory.h"
#include "../MathRuntimeEvaluator/MathRuntimeEvaluatorException.h"

#include "../MathRuntimeEvaluator/Parser.h"

namespace MathRuntimeEvaluator
{
namespace UnitTests
{
	// Parses and evaluates a string expression, and then checks it against an
	// expected value.
	void RunUnitTest(std::string expressionString, double expectedValue);

	// Runs a battery of unit tests
	void RunUnitTestBattery();
}
}
#endif