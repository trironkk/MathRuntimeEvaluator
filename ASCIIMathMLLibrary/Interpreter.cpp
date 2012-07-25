#include "Interpreter.h"

using namespace ASCIIMathMLLibrary;
using namespace std;

namespace ASCIIMathMLLibrary
{
	namespace Parser
	{
		WorkingMemory memory;

		bool persist = true;

		bool Preparse(istream& stream)
		{
			string token = ReadNextToken(stream);

			if (token == "exit") { persist = false; return false; }
			else if (token == "help") { PrintHelp(); return false; }
			else if (token == "memory") { memory.PrintLine(cout); return false; }
		}

		void LaunchInterpreter()
		{
			// Default variables
			memory.SetValue("pi", 3.1415926535897932384626);
			memory.SetValue("e", 2.7182818284590452353602);

			string input;
			while (persist)
			{
				try
				{
					cout << ">>> ";
					getline(cin, input);
					istringstream stream(input);
					if (Preparse(stream) == false)
						continue;

					CompoundExpression compoundExpression(ParseString(input));

					compoundExpression.Simplify(memory);
					compoundExpression.PrintLine(cout);
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
help   Display this screen \n \
memory Display all defined variables\n \
exit   Close this session\n \
\n \
Help: \n \
Arithmetic Operations: \n \
+      Addition \n \
-      Subtraction or Negation \n \
*      Multiplication \n \
/      Division \n \
\n \
Supported Functions: \n \
pow    Exponentiation \n \
sin    Sin Function \n \
cos    Cos Function \n \
tan    Tan Function \n \
ln     Natural Logarithm \n \
log2   Base 2 Logarithm \n \
log10  Base 10 Logarithm \n \
mod    Modular Division \n \
sqrt   Square Root \n \
abs    Absolute Value \n \
\n \
Notes: \n \
- All operations will be assigned to the variable \"ans\" unless otherwise \n \
specified. \n \
- The constants \"e\" and \"pi\" are initialized by default. \n \
";
		}
	}
}