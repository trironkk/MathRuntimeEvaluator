#ifndef PARSER_H
#define PARSER_H

#include <algorithm>
#include <iterator>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>

#include "MathRuntimeEvaluatorException.h"
#include "WorkingMemory.h"

#include "Operations.h"
#include "Expression.h"
#include "Utilities.h"

namespace MathRuntimeEvaluatorNamespace
{
namespace Parser
{
	// Parse a line of input
	Expression& Parse(std::istream& stream);

	// Internal parsing method - necessary to clean up parenthetical recursive
	// calls. This is an implementation of the shunting yard algorithm for
	// converting the infix string expression into a postfix Expression object.
	std::list<std::string> InternalParse(std::istream& stream,
		bool expectingClose=false, bool expectingComma=false);

	// Return the next token, and adjust the stringstream accordingly
	std::string ReadNextToken(std::istream& stream);
}
}

#endif