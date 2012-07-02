#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <hash_map>

namespace ASCIIMathMLLibrary
{
	class Expression;

	typedef std::string string;
	typedef std::shared_ptr<Expression> SharedExpressionPointer;

	typedef StringToDoubleHashMap hash_map<const string, double>;

	typedef SharedExpressionPointer (*Operation)(Expression l, Expression r);
}

#endif