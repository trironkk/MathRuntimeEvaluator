#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <unordered_map>

namespace ASCIIMathMLLibrary
{
	class Expression;

	typedef std::string									String;
	typedef std::shared_ptr<Expression>					SharedExpressionPointer;

	typedef std::unordered_map<std::string, double>		WorkingMemoryData;
	typedef std::unordered_map<std::string, double>		VariableExpressionData;
	typedef std::list<std::string>						DeclaredVariables;
	typedef std::list<std::string>						InvolvedVariables;

	typedef SharedExpressionPointer(*Operation)(Expression& l, Expression& r);
}

#endif