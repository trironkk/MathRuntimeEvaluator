#include "UnitTests.h"

using namespace ASCIIMathMLLibrary;
using namespace std;
namespace UnitTests
{

	WorkingMemory memory;
	void RunUnitTest(string expressionString, double expectedValue)
	{
		CompoundExpression ce = Parser::ParseString(expressionString);
		cout << expressionString << " = ";
		ce.Simplify(memory);
		ce.PrintLine(cout);

		ostringstream convert;
		convert << expectedValue;

		if (ce.GetStringRepresentation() != convert.str())
		{
			stringstream errorStream;
			errorStream << "\n";
			errorStream << "The following expression failed to evaluated appropriately:\n";
			errorStream << "Expression:     " << expressionString << "\n";
			errorStream << "Expected Value: " << convert.str() << "\n";
			errorStream << "Actual Value:   " << ce.GetStringRepresentation() << "\n";
			errorStream << "\n";
			cout << errorStream.str();
			//throw ASCIIMathMLException(errorStream.str());
		}
	}

	void RunUnitTestBattery()
	{
		// Initilize the working memory
		memory.SetValue("pi", 3.1415926535897932384626);
		memory.SetValue("e", 2.7182818284590452353602);

		// Basic Arithmetic
		cout << "Basic Arithmetic" << endl;
		RunUnitTest("5+2", 7);
		RunUnitTest("5-2", 3);
		RunUnitTest("5*2", 10);
		RunUnitTest("5/2", 2.5);

		// Negations
		cout << endl << "Negations" << endl;
		RunUnitTest("5+-2", 3);
		RunUnitTest("-5+2", -3);
		RunUnitTest("-5+-2", -7);

		// Order of Operations
		cout << endl << "Order of Operations" << endl;
		RunUnitTest("4+5*3", 19);
		RunUnitTest("4*5+3", 23);
		RunUnitTest("4/5+3", 3.8);
		RunUnitTest("4+5/2", 6.5);
		RunUnitTest("4/5-3", -2.2);
		RunUnitTest("4-5/2", 1.5);

		// Order of Operations with Negations
		cout << endl << "Order of Operations with Negations" << endl;
		RunUnitTest("-4*5+3", -17);
		RunUnitTest("4*5+-3", 17);
		RunUnitTest("4/-5+3", 2.2);

		// pow operation
		cout << endl << "pow operation" << endl;
		RunUnitTest("pow(4,2)", 16);
		RunUnitTest("pow(2,2.6)", 6.06287);
		RunUnitTest("pow(9.1,2.6)", 311.5356);
		RunUnitTest("pow(4,-2)", 0.0625);
		RunUnitTest("pow(-4,2)", 16);
		RunUnitTest("pow(-4,-3)", -0.015625);

		// trigonometric operations
		cout << endl << "trigonometric operations" << endl;
		RunUnitTest("sin(4)", -0.756802);
		RunUnitTest("cos(4)", -0.653644);
		RunUnitTest("tan(4)", 1.15782);

		// square root operation
		cout << endl << "square root operation" << endl;
		RunUnitTest("sqrt(4)",  2);
		RunUnitTest("sqrt(44)", 6.63325);

		// absolute value operation
		cout << endl << "absolute value operation" << endl;
		RunUnitTest("abs(4)",  4);
		RunUnitTest("abs(-4)", 4);

		// logarithmic operations
		cout << endl << "logarithmic operations" << endl;
		RunUnitTest("log10(100)",  2);
		RunUnitTest("ln(100)", 4.60517);
		RunUnitTest("log2(64)", 6);

		// modulo operation
		cout << endl << "modulo operation" << endl;
		RunUnitTest("mod(100, 7)",  2);

		std::cin.get();
	}
}