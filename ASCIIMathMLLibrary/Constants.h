#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <unordered_map>
#include <queue>
#include <functional>

using std::string;

namespace ASCIIMathMLLibrary
{
	struct ExpressionComponent;
	typedef std::queue<std::reference_wrapper<ExpressionComponent>>
		ExpressionComponentQueue;
}

#endif