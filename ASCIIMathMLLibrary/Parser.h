#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <string.h>
#include <list>
#include <stack>
#include <sstream>
#include <iostream>

#include "CompoundExpressionFactory.h"
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
#include "Exponentiate.h"
#include "NaturalLogarithm.h"
#include "Modulo.h"
#include "CommonLogarithm.h"
#include "Sin.h"
#include "Cos.h"
#include "Tan.h"
#include "AbsoluteValue.h"
#include "SquareRoot.h"

namespace ASCIIMathMLLibrary
{
	namespace Parser
	{
		// Parse a line of input
		CompoundExpression& ParseString(std::string str);
		CompoundExpression& ParseString(std::istringstream& stream);

		// Internal parsing method - necessary to clean up parenthetical recursive
		// calls
		std::list<std::string> InternalParse(std::istringstream& stream);


		// Return the next token, and adjust the stringstream accordingly
		std::string ReadNextToken(std::istringstream& stream);
	}
}

#endif