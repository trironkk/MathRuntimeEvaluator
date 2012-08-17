#include "Tests.h"

#include "MathRuntimeEvaluator.h"
#include "WorkingMemory.h"
#include "MathRuntimeEvaluatorException.h"

#include <windows.h>

using namespace std;

namespace MathRuntimeTester
{
	HANDLE hConsole;
	// Parses and evaluates a string expression, and then checks it against an
	// expected value.
	void RunTest(string expressionString, double expectedValue)
	{
		double result;
		try
		{
			// Print the expression
			cout << expressionString;

			// Perform parsing and evaluation
			result = MathRuntimeEvaluator::Evaluate(expressionString);

			// Print the result
			cout << " ?= " << result << std::endl;
		}
		catch (MathRuntimeEvaluatorException& e)
		{

			// Print the error
			SetConsoleTextAttribute(hConsole, 12);
			cout << endl;
			cout << "Encountered an exception while simplifying: ";
			cout << endl << e << endl << endl;
			SetConsoleTextAttribute(hConsole, 15);
			return;
		}

		// Evaluate accuracy...
		if (result != expectedValue)
		{
			SetConsoleTextAttribute(hConsole, 12);
			stringstream errorStream;
			errorStream << "\n";
			errorStream << "The following expression failed to evaluated appropriately:\n";
			errorStream << "Expression:     " << expressionString << "\n";
			errorStream << "Expected Value: " << expectedValue << "\n";
			errorStream << "Actual Value:   " << result << "\n";
			errorStream << "\n";
			cout << errorStream.str();
			SetConsoleTextAttribute(hConsole, 15);
		}
	}

	// Runs a battery of unit tests
	void RunTestBattery()
	{
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		WorkingMemory::SetValue("pi", 3.1415926535897932384626);
		WorkingMemory::SetValue("e", 2.7182818284590452353602);

		// Basic Arithmetic
		cout << "Basic Arithmetic" << endl;
		RunTest("5+2", 5+2);
		RunTest("5-2", 5-2);
		RunTest("5*2", 5*2);
		RunTest("5/2", 5.0/2.0);

		// Negations
		cout << endl << "Negations" << endl;
		RunTest("5+-2", 5+-2);
		RunTest("-5+2", -5+2);
		RunTest("-5+-2", -5+-2);

		// Order of Operations
		cout << endl << "Order of Operations" << endl;
		RunTest("4+5*3", 4+5*3);
		RunTest("4*5+3", 4*5+3);
		RunTest("4/5+3", 4.0/5.0+3);
		RunTest("4+5/2", 4+5.0/2.0);
		RunTest("4/5-3", 4.0/5.0-3);
		RunTest("4-5/2", 4-5.0/2.0);
		RunTest("(4-5)/2", (4-5.0)/2.0);
		RunTest("(4+5)*3", (4+5)*3);

		// Order of Operations with Negations
		cout << endl << "Order of Operations with Negations" << endl;
		RunTest("-4*5+3", -4*5+3);
		RunTest("4*5+-3", 4*5+-3);
		RunTest("4/-5+3", 4.0/-5.0+3);

		// pow operation
		cout << endl << "pow operation" << endl;
		RunTest("pow(4,2)", pow(4.0,2));
		RunTest("pow(2,2.6)", pow(2,2.6));
		RunTest("pow(9.1,2.6)", pow(9.1,2.6));
		RunTest("pow(4,-2)", pow(4.0,-2));
		RunTest("pow(-4,2)", pow(-4,2.0));
		RunTest("pow(-4,-3)", pow(-4,-3.0));

		// trigonometric operations
		cout << endl << "trigonometric operations" << endl;
		RunTest("sin(4)", sin(4.0));
		RunTest("cos(4)", cos(4.0));
		RunTest("tan(4)", tan(4.0));

		// square root operation
		cout << endl << "square root operation" << endl;
		RunTest("sqrt(4)",  sqrt(4.0));
		RunTest("sqrt(44)", sqrt(44.0));

		// absolute value operation
		cout << endl << "absolute value operation" << endl;
		RunTest("abs(4)",  abs(4));
		RunTest("abs(-4)", abs(-4));

		// logarithmic operations
		cout << endl << "logarithmic operations" << endl;
		RunTest("log10(100)",  log10(100.0));
		RunTest("ln(100)", log(100.0));
		RunTest("log2(64)", 6);
		RunTest("log(2,64)", 6);
		RunTest("log(10,100)", log10(100.0));
		RunTest("log(e,100)", log(100.0));

		//// modulo operation
		//cout << endl << "modulo operation" << endl;
		//RunTest("mod(100, 7)",  2);

		//// sum operation
		//cout << endl << "sum operation" << endl;
		//RunTest("sum(10)", 10);
		//RunTest("sum(10,4)", 14);
		//RunTest("sum(-1,-19,100)",  80);
		//RunTest("sum()",  0);

		//// avg operation
		//cout << endl << "avg operation" << endl;
		//RunTest("avg(10)", 10);
		//RunTest("avg(10,4)", 7);
		//RunTest("avg(-1,-19,100)",  80.0/3.0);
		//
		//// stddev operation
		//cout << endl << "stddev operation" << endl;
		//RunTest("stddev(2,4,4,4,5,5,7,9)", 2);

		// big number tests (handling conversions to and from scientific notation)
		cout << endl << "big number tests " << endl;
		RunTest("12903984128374", 12903984128374);
		//RunTest("pow(pi, 20)", pow(memory.GetValue("pi"), 20.0));

		// Stuff that's supposed to break it.
		cout << endl << "Stuff that's supposed to break it..." << endl;
		RunTest("1 / 0", 0);
		RunTest("sqrt(-1)", 0);
	}
}