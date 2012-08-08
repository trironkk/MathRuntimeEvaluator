#ifndef EXPOSED_FUNCTIONALITY
#define	EXPOSED_FUNCTIONALITY

#include <string>
#include <sstream>

namespace MathRuntimeEvaluator
{
	// Takes in a string representation of an expression and returns the result
	__declspec(dllexport) double Evaluate(std::string expression);

	// Takes in a string stream representation of an expression and returns the
	// result
	__declspec(dllexport) double Evaluate(std::stringstream expression);
}

#endif