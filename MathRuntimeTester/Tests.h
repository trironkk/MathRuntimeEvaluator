#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <string>
#include <stack>
#include <memory>
#include <math.h>

namespace MathRuntimeTester
{
	// Parses and evaluates a string expression, and then checks it against an
	// expected value.
	void RunTest(std::string expressionString, double expectedValue);

	// Runs a battery of unit tests
	void RunTestBattery();
}
#endif