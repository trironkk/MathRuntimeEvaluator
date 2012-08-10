#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <stack>
#include <memory>

#include "MathRuntimeEvaluator.h"
#include "UnitTests.h"

using namespace std;

namespace MathRuntimeInterpreter
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