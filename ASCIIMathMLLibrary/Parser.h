#ifndef PARSER_H
#define PARSER_H

#include <string>

#include "Constants.h"
#include "Expression.h"
#include "Exception.h"

namespace ASCIIMathMLLibrary
{
	Expression& ParseExpression(String line);
}

#endif