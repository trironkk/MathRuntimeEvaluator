#include "MathRuntimeEvaluator.h"

#include "Parser.h"
#include "Expression.h"
#include "Evaluator.h"


using std::string;
using std::stringstream;

namespace MathRuntimeEvaluator
{
	//class MathRuntimeEvaluator
	//{
	//public:
		// Takes in a string representation of an expression and returns the result
		static double Evaluate(string expressionString)
		{
			Expression expression(Parser::ParseString(expressionString));
			return Evaluator::Evaluate(expression);
		}

		// Takes in a string stream representation of an expression and returns the
		// result
		static double Evaluate(stringstream expressionStream)
		{
			Expression expression(Parser::ParseString(expressionStream));
			return Evaluator::Evaluate(expression);
		}
	//}
}