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

using namespace ASCIIMathMLLibrary;
using namespace std;
namespace ASCIIMathMLLibrary
{
	namespace Parser
	{
		bool Preparse(std::stringstream& stream);
		void LaunchInterpreter();
		void PrintHelp();
	}
}
#endif