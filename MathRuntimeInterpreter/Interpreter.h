#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <stack>
#include <memory>


// Expressions
#include "../MathRuntimeEvaluator/Constant.h"
#include "../MathRuntimeEvaluator/Variable.h"
#include "../MathRuntimeEvaluator/CompoundExpression.h"
#include "../MathRuntimeEvaluator/Operation.h"
#include "../MathRuntimeEvaluator/Operations.h"
#include "../MathRuntimeEvaluator/MathRuntimeEvaluatorException.h"
#include "../MathRuntimeEvaluator/WorkingMemory.h"
#include "../MathRuntimeEvaluator/Parser.h"
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