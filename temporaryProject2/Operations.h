#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>

#include "Operation.h"

#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"

namespace MathRuntimeEvaluator
{
	struct Operations
	{
		// Returns a vector of all available operations
		static const std::list<Operation*>& GetOperations();

		// Returns true if the identifier is associated with an operation, and
		// false otherwise
		static const bool IsOperation(std::string identifier);

		// Returns true if the operation is a function, and false otherwise
		static const bool IsFunction(std::string identifier);

		// Returns the number of parameters the operation takes in
		static const int GetParameterCount(std::string identifier);

		// Returns the rank of an operation
		static const int GetRank(std::string identifier);

		// Returns a helpful string describing how the operation is used
		static const std::string& GetUsage(std::string identifier);

		// Returns a pointer to the operation
		static const Operation* GetOperation(std::string identifier);
	};
}

#endif