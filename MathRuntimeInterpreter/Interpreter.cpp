#include "Interpreter.h"

#include "WorkingMemory.h"
#include "MathRuntimeEvaluatorException.h"

using namespace std;

namespace MathRuntimeInterpreter
{
	namespace Parser
	{
		// Various variables declared in the namespace scope to avoid complicating
		// method signatures.
		string resultVariableName;
		string input;
		bool persist = true;

		// Launches an interpreter and persists until the user terminates
		void LaunchInterpreter()
		{
			// Default variables
			WorkingMemory::SetValue("pi", 3.1415926535897932384626);
			WorkingMemory::SetValue("e", 2.7182818284590452353602);

			// Welcome Message
			cout <<
"MathRuntimeEvaluator Demonstration";

			cout << "\n";
			PrintHelp();
			cout << "\n";

			while (persist)
			{
				try
				{
					cout << ">>> ";
					getline(cin, input);
					istringstream stream(input);

					resultVariableName = "ans";
					if (Preparse(stream) == false)
						continue;

					// Perform parsing and evaluation
					double result = MathRuntimeEvaluator::Evaluate(input);

					// Print the result
					cout << result << std::endl;
				}
				catch (MathRuntimeEvaluatorException& e)
				{
					// Print out the error
					cout << "Error: " << e << std::endl << std::endl;
				}
				catch (exception& e)
				{
					cout << e.what() << std::endl;
				}
			}
		}	

		// Perform a pre-parse on a string, looking for and executing interpreter
		// commands and handling working memory management.
		bool Preparse(istringstream& stream)
		{
			string token = MathRuntimeEvaluator::ReadNextToken(stream);

			if ("exit" == token) { persist = false; return false; }
			else if ("memory" == token) { WorkingMemory::PrintLine(cout); return false; }
			else if ("" == token) { return false; }
			else if ("help" == token)
			{
				// Determine if help is called by itself or with an input
				// parameter
				string operation = MathRuntimeEvaluator::ReadNextToken(stream);
				if ("" == operation)
				{
					PrintHelp();
					return false;
				}
				else
				{
					if (MathRuntimeEvaluator::IsOperation(operation))
					{
						cout << endl << MathRuntimeEvaluator::GetUsage(operation) << endl;
					}
					else
					{
						cout << endl << "Unknown operation: " << operation << endl << endl;
					}
					return false;
				}
			}
			return true;
		}

		// Prints help text
		void PrintHelp()
		{
			cout <<
" \
\n\
Interpreter Commands: \n\
	help             Display this help text \n\
	help [operation] Display the usage of the specified operation \n\
	memory           Display all defined variables\n\
	unittests        Perform a unit test battery run\n\
	exit             Close this session\n\
\n\
Operators: \n\
	+                Addition \n\
	-                Subtraction or Negation \n\
	*                Multiplication \n\
	/                Division \n\
	~                Negation \n\
\n\
Functions: \n\
	pow              Exponentiation \n\
	sin              Sine Function \n\
	cos              Cosine Function \n\
	tan              Tangent Function \n\
	ln               Natural Logarithm \n\
	log2             Base 2 Logarithm \n\
	log10            Base 10 Logarithm \n\
	log              Generic Logarithm \n\
	mod              Modular Division \n\
	sqrt             Square Root \n\
	abs              Absolute Value \n\
	sum              Sum \n\
	avg              Average \n\
	stddev           Standard Deviation \n\
\n\
Notes: \n\
- All operations will be assigned to the variable \"ans\" unless otherwise \n\
specified. \n\
- The constants \"e\" and \"pi\" are initialized by default. \n\
";
		}
	}
}