#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
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
#include "UnitTests.h"

using namespace MathRuntimeEvaluator;
using namespace std;
namespace MathRuntimeEvaluator
{
	namespace Parser
	{
		// Launches an interpreter and persists until the user terminates
		void LaunchInterpreter();

		// Perform a pre-parse on a string, looking for and executing interpreter
		// commands and handling working memory management.
		bool Preparse(stringstream& stream);

		// Prints help text
		void PrintHelp();
	}
}
#endif