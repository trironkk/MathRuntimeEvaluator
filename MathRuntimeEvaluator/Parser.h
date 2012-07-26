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

#include "CompoundExpressionFactory.h"
#include "OperatorFactory.h"
#include "Exception.h"
#include "WorkingMemory.h"
#include "Constant.h"
#include "Variable.h"
#include "CompoundExpression.h"

// Operators
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Negate.h"

namespace MathRuntimeEvaluator
{
	namespace Parser
	{
		// Parse a line of input
		CompoundExpression& ParseString(std::string str);
		CompoundExpression& ParseString(std::istream& stream);

		// Internal parsing method - necessary to clean up parenthetical recursive
		// calls. This is an implementation of the shunting yard algorithm for
		// converting the infix string expression into a postfix
		// CompoundExpression object.
		std::list<std::string> InternalParse(std::istream& stream,
			bool expectingClose=false, bool expectingComma=false);


		// Return the next token, and adjust the stringstream accordingly
		std::string ReadNextToken(std::istream& stream);
	}
}

#endif