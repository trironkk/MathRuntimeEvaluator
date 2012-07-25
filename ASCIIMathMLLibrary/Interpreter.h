#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <string>
#include <stack>
#include <memory>

// Operators
#include "Operator.h"

// Expressions
#include "Constant.h"
#include "Variable.h"
#include "CompoundExpression.h"

#include "Parser.h"
#include "Exception.h"
#include "WorkingMemory.h"

using namespace ASCIIMathMLLibrary;
using namespace std;

namespace Interpreter
{
	void LaunchInterpreter()
	{
		while (true)
		{
			try
			{
				cout << ">>> ";
				getline(cin, input);
				CompoundExpression compoundExpression(Parser::ParseString(input));

				// Debugging
				//compoundExpression.PrintLine(cout);
				//cout << "infix:   " << compoundExpression.GetInfixStringRepresentation() << std::endl;
				//cout << "postfix: " << compoundExpression.GetPostfixStringRepresentation() << std::endl;
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
}

#endif