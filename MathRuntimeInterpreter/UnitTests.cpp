#include "UnitTests.h"

using namespace std;

namespace MathRuntimeInterpreter
{
namespace UnitTests
{
	//WorkingMemory memory;

	// Parses and evaluates a string expression, and then checks it against an
	// expected value.
	void RunUnitTest(string expressionString, double expectedValue)
	{
		//Evaluate(expressionString);

		//CompoundExpression ce;

		//// Try to parse...
		//try
		//{
		//	ce = Parser::Parse(expressionString);
		//	cout << expressionString << " = ";
		//}
		//catch (MathRuntimeEvaluatorException& e)
		//{
		//	// Print the error.
		//	cout << endl;
		//	cout << "Encountered an exception while parsing: ";
		//	cout << endl << e << endl << endl;
		//	return;
		//}
		
		//// Try to simplify...
		//try
		//{
		//	ce.Simplify(memory);
		//}
		//catch (MathRuntimeEvaluatorException& e)
		//{
		//	// Print the error.
		//	cout << endl;
		//	cout << "Encountered an exception while simplifying: ";
		//	cout << endl << e << endl << endl;
		//	return;
		//}

		//// Try to print...
		//try
		//{
		//	ce.PrintLine(cout);
		//}
		//catch (MathRuntimeEvaluatorException& e)
		//{
		//	// Print the error.
		//	cout << endl;
		//	cout << "Encountered an exception while printing: ";
		//	cout << endl << e << endl << endl;
		//	return;
		//}

		//// Evaluate accuracy...
		//if (ce.GetValue() != expectedValue)
		//{
		//	stringstream errorStream;
		//	errorStream << "\n";
		//	errorStream << "The following expression failed to evaluated appropriately:\n";
		//	errorStream << "Expression:     " << expressionString << "\n";
		//	errorStream << "Expected Value: " << expectedValue << "\n";
		//	errorStream << "Actual Value:   " << ce.GetValue() << "\n";
		//	errorStream << "\n";
		//	cout << errorStream.str();
		//}
	}

	// Runs a battery of unit tests
	void RunUnitTestBattery()
	{
		//// Initilize the working memory
		//memory.SetValue("pi", 3.1415926535897932384626);
		//memory.SetValue("e", 2.7182818284590452353602);

		// Basic Arithmetic
		cout << "Basic Arithmetic" << endl;
		RunUnitTest("5+2", 5+2);
		RunUnitTest("5-2", 5-2);
		RunUnitTest("5*2", 5*2);
		RunUnitTest("5/2", 5.0/2.0);

		// Negations
		cout << endl << "Negations" << endl;
		RunUnitTest("5+-2", 5+-2);
		RunUnitTest("-5+2", -5+2);
		RunUnitTest("-5+-2", -5+-2);

		// Order of Operations
		cout << endl << "Order of Operations" << endl;
		RunUnitTest("4+5*3", 4+5*3);
		RunUnitTest("4*5+3", 4*5+3);
		RunUnitTest("4/5+3", 4.0/5.0+3);
		RunUnitTest("4+5/2", 4+5.0/2.0);
		RunUnitTest("4/5-3", 4.0/5.0-3);
		RunUnitTest("4-5/2", 4-5.0/2.0);
		RunUnitTest("(4-5)/2", (4-5.0)/2.0);
		RunUnitTest("(4+5)*3", (4+5)*3);

		// Order of Operations with Negations
		cout << endl << "Order of Operations with Negations" << endl;
		RunUnitTest("-4*5+3", -4*5+3);
		RunUnitTest("4*5+-3", 4*5+-3);
		RunUnitTest("4/-5+3", 4.0/-5.0+3);

		// pow operation
		cout << endl << "pow operation" << endl;
		RunUnitTest("pow(4,2)", pow(4.0,2));
		RunUnitTest("pow(2,2.6)", pow(2,2.6));
		RunUnitTest("pow(9.1,2.6)", pow(9.1,2.6));
		RunUnitTest("pow(4,-2)", pow(4.0,-2));
		RunUnitTest("pow(-4,2)", pow(-4,2.0));
		RunUnitTest("pow(-4,-3)", pow(-4,-3.0));

		// trigonometric operations
		cout << endl << "trigonometric operations" << endl;
		RunUnitTest("sin(4)", sin(4.0));
		RunUnitTest("cos(4)", cos(4.0));
		RunUnitTest("tan(4)", tan(4.0));

		// square root operation
		cout << endl << "square root operation" << endl;
		RunUnitTest("sqrt(4)",  sqrt(4.0));
		RunUnitTest("sqrt(44)", sqrt(44.0));

		// absolute value operation
		cout << endl << "absolute value operation" << endl;
		RunUnitTest("abs(4)",  abs(4));
		RunUnitTest("abs(-4)", abs(-4));

		// logarithmic operations
		cout << endl << "logarithmic operations" << endl;
		RunUnitTest("log10(100)",  log10(100.0));
		RunUnitTest("ln(100)", log(100.0));
		RunUnitTest("log2(64)", 6);
		RunUnitTest("log(2,64)", 6);
		RunUnitTest("log(10,100)", log10(100.0));
		RunUnitTest("log(e,100)", log(100.0));

		//// modulo operation
		//cout << endl << "modulo operation" << endl;
		//RunUnitTest("mod(100, 7)",  2);

		//// sum operation
		//cout << endl << "sum operation" << endl;
		//RunUnitTest("sum(10)", 10);
		//RunUnitTest("sum(10,4)", 14);
		//RunUnitTest("sum(-1,-19,100)",  80);
		//RunUnitTest("sum()",  0);

		//// avg operation
		//cout << endl << "avg operation" << endl;
		//RunUnitTest("avg(10)", 10);
		//RunUnitTest("avg(10,4)", 7);
		//RunUnitTest("avg(-1,-19,100)",  80.0/3.0);
		//
		//// stddev operation
		//cout << endl << "stddev operation" << endl;
		//RunUnitTest("stddev(2,4,4,4,5,5,7,9)", 2);

		// big number tests (handling conversions to and from scientific notation)
		cout << endl << "big number tests " << endl;
		RunUnitTest("12903984128374", 12903984128374);
		//RunUnitTest("pow(pi, 20)", pow(memory.GetValue("pi"), 20.0));

		// Stuff that's supposed to break it.
		cout << endl << "Stuff that's supposed to break it..." << endl;
		RunUnitTest("1 / 0", 0);
		RunUnitTest("sqrt(-1)", 0);

		
	}
}
}