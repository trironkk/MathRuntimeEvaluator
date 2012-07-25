#include "Interpreter.h"

using namespace ASCIIMathMLLibrary;
using namespace std;

namespace ASCIIMathMLLibrary
{
	namespace Parser
	{
		WorkingMemory memory;
		string resultVariableName;
		string input;

		bool persist = true;

		bool Preparse(stringstream& stream)
		{
			string token = ReadNextToken(stream);

			if (token == "exit") { persist = false; return false; }
			else if (token == "memory") { memory.PrintLine(cout); return false; }
			else if (token == "unittests") { UnitTests::RunUnitTestBattery(); return false; }
	

			else if (token == "") { return false; }
			else if (token == "help")
			{
				string operation = ReadNextToken(stream);
				if (operation == "") { PrintHelp(); return false; }
				else { cout << std::endl << GetUsage(operation) << std::endl; return false;}
			}

			// If an assignment is specified...
			if (ReadNextToken(stream) == "=")
			{
				try
				{
					// Assert that the variable name is a valid one.
					memory.ValidateVariableName(token);

					// Record the variable name.
					resultVariableName = token;

					// Reset the input string to disclude the assignment
					getline(stream, input);
				}
				catch (ASCIIMathMLException&)
				{
					// The functionality of displaying the exception occurs in the constructor of the exception, itself. No need to do anything here.
				}
			}
		}

		void LaunchInterpreter()
		{
			// Default variables
			memory.SetValue("pi", 3.1415926535897932384626);
			memory.SetValue("e", 2.7182818284590452353602);

			// Welcome Message
			cout <<
"ASCIIMathMLLibrary Demonstration";

			cout << "\n";
			PrintHelp();
			cout << "\n";

			while (persist)
			{
				try
				{
					cout << ">>> ";
					getline(cin, input);
					stringstream stream(input);

					resultVariableName = "ans";
					if (Preparse(stream) == false)
						continue;

					CompoundExpression compoundExpression(ParseString(input));

					// Perform the math and print the result.
					compoundExpression.Simplify(memory);
					compoundExpression.PrintLine(cout);

					// Records the result.
					memory.SetValue(resultVariableName,
						compoundExpression.GetValue());

					cout << std::endl;
				}
				catch (ASCIIMathMLException&)
				{
					// The functionality of displaying the exception occurs in the constructor of the exception, itself. No need to do anything here.
				}
				catch (exception& e)
				{
					cout << e.what();
				}
			}
		}	

		void PrintHelp()
		{
			cout <<
" \
\n \
Interpreter Commands: \n \
    help             Display this help text \n \
    help [operation] Display the usage of the specified operation \n \
    memory           Display all defined variables\n \
    unittests        Perform a unit test battery run\n \
    exit             Close this session\n \
\n \
Arithmetic Operations: \n \
    +                Addition \n \
    -                Subtraction or Negation \n \
    *                Multiplication \n \
    /                Division \n \
\n \
Supported Functions: \n \
    pow              Exponentiation \n \
    sin              Sine Function \n \
    cos              Cosine Function \n \
    tan              Tangent Function \n \
    ln               Natural Logarithm \n \
    log2             Base 2 Logarithm \n \
    log10            Base 10 Logarithm \n \
    log              Generic Logarithm \n \
    mod              Modular Division \n \
    sqrt             Square Root \n \
    abs              Absolute Value \n \
    sum              Sum \n \
    avg              Average \n \
    stddev           Standard Deviation \n \
\n \
Notes: \n \
- All operations will be assigned to the variable \"ans\" unless otherwise \n \
specified. \n \
- The constants \"e\" and \"pi\" are initialized by default. \n \
";
		}
	}
}