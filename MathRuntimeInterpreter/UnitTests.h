#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <iostream>
#include <string>
#include <stack>
#include <memory>
#include <math.h>

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