#include "MathRuntimeEvaluator.h"

#include "Parser.h"
#include "Expression.h"
#include "Evaluator.h"

using std::string;
using std::stringstream;
using std::istringstream;
using namespace MathRuntimeEvaluatorNamespace;

// Takes in a string representation of an expression and returns the result
double MathRuntimeEvaluator::Evaluate(string expressionString)
{
	return Evaluate(stringstream(expressionString));
}

double MathRuntimeEvaluator::Evaluate(stringstream expressionStream)
{
	Expression expression(Parser::Parse(expressionStream));
	return Evaluator::Evaluate(expression).Number;
}

// Takes in a string stream representation of an expression and returns the
// next token
std::string MathRuntimeEvaluator::ReadNextToken(std::string& line)
{
	std::istringstream line_stringstream(line);
	std::string result = ReadNextToken(line_stringstream);
	line = line_stringstream.str();
	return ReadNextToken(result);
}

std::string MathRuntimeEvaluator::ReadNextToken(std::istringstream& line)
{
	return Parser::ReadNextToken(line);
}

std::string MathRuntimeEvaluator::GetUsage(std::string identifier)
{
	return Operations::GetUsage(identifier);
}

bool MathRuntimeEvaluator::IsOperation(std::string identifier)
{
	return Operations::IsOperation(identifier);
}