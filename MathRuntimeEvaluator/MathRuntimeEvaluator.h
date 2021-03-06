#ifndef MATH_RUNTIME_EVALUATOR_H
#define	MATH_RUNTIME_EVALUATOR_H

#include <string>
#include <sstream>

class __declspec(dllexport) MathRuntimeEvaluator
{
public:
	// Takes in a string representation of an expression and returns the result
	static double Evaluate(std::string expression);
	static double Evaluate(std::stringstream expression);

	// Takes in a string stream representation of an expression and returns the
	// result
	static std::string ReadNextToken(std::string& expression);
	static std::string ReadNextToken(std::istringstream& expression);

	// Exposing Operation fields
	static std::string GetUsage(std::string identifier);
	static bool IsOperation(std::string identifier);
};

#endif