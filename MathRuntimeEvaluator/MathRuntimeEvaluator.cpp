#include "MathRuntimeEvaluator.h"

#include "Parser.h"
#include "Expression.h"
#include "Evaluator.h"


using std::string;
using std::stringstream;
using namespace MathRuntimeEvaluatorNamespace;

double MathRuntimeEvaluator::Evaluate(string expressionString)
{
	Expression expression(Parser::ParseString(expressionString));
	return Evaluator::Evaluate(expression);
}

// Takes in a string stream representation of an expression and returns the
// result
double MathRuntimeEvaluator::Evaluate(stringstream expressionStream)
{
	Expression expression(Parser::ParseString(expressionStream));
	return Evaluator::Evaluate(expression);
}
