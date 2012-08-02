#include "Operations.h"

using std::pair;
using std::set;
using std::map;
using std::list;
using std::string;

namespace MathRuntimeEvaluator
{
	// Returns a vector of all available operations
	const std::list<Operation*>& Operations::GetOperations()
	{
		static bool initialized;
		static std::list<Operation*> operations;
		if (initialized == false)
		{
			operations.push_back(new Add());
			operations.push_back(new Subtract());
			operations.push_back(new Multiply());
			operations.push_back(new Divide());
		}
		return operations;
	}

	// Returns true if the operation is a function, and false otherwise
	const bool Operations::IsFunction(std::string identifier) 
	{
		static bool initialized;
		static map<string, bool> isFunctionMap;
		if (initialized == false)
		{
			list<Operation*> operations = GetOperations();
			for (list<Operation*>::const_iterator iter = operations.begin();
				iter != operations.end();
				iter++)
			{
				isFunctionMap[(*iter)->GetIdentifier()] = (*iter)->IsFunction();
			}
		}
		return isFunctionMap[identifier];
	}
	
	// Returns true if the identifier is associated with an operation, and
	// false otherwise
	const bool Operations::IsOperation(std::string identifier) 
	{
		static bool initialized;
		static set<string> isOperationSet;
		if (initialized == false)
		{
			list<Operation*> operations = GetOperations();
			for (list<Operation*>::const_iterator iter = operations.begin();
				iter != operations.end();
				iter++)
			{
				isOperationSet.insert((*iter)->GetIdentifier());
			}
		}
		return isOperationSet.find(identifier) != isOperationSet.end();
	}

	// Returns the number of parameters the operation takes in
	const int Operations::GetParameterCount(std::string identifier)
	{
		static bool initialized;
		static map<string, int> parameterCountMap;
		if (initialized == false)
		{
			list<Operation*> operations = GetOperations();
			for (list<Operation*>::const_iterator iter = operations.begin();
				iter != operations.end();
				iter++)
			{
				parameterCountMap[(*iter)->GetIdentifier()] =
					(*iter)->GetParameterCount();
			}
		}
		return parameterCountMap[identifier];
	}

	// Returns the rank of an operation
	const int Operations::GetRank(std::string identifier)
	{
		static bool initialized;
		static map<string, int> rankMap;
		if (initialized == false)
		{
			list<Operation*> operations = GetOperations();
			for (list<Operation*>::const_iterator iter = operations.begin();
				iter != operations.end();
				iter++)
			{
				rankMap[(*iter)->GetIdentifier()] =
					(*iter)->GetRank();
			}
		}
		return rankMap[identifier];
	}

	// Returns a helpful string describing how the operation is used
	const string& Operations::GetUsage(std::string identifier)
	{
		static bool initialized;
		static map<string, string> usageMap;
		if (initialized == false)
		{
			list<Operation*> operations = GetOperations();
			for (list<Operation*>::const_iterator iter = operations.begin();
				iter != operations.end();
				iter++)
			{
				string identifier = (*iter)->GetIdentifier();
				string usage = (*iter)->GetUsage();
				pair<string,string> _pair(identifier, usage);
				usageMap.insert(_pair);
			}
		}
		return usageMap[identifier];
	}

	// Returns a pointer to the operation
	const Operation* Operations::GetOperation(std::string identifier)
	{
		static bool initialized;
		static map<string, const Operation*> operationsMap;
		if (initialized == false)
		{
			list<Operation*> operations = GetOperations();
			for (list<Operation*>::const_iterator iter = operations.begin();
				iter != operations.end();
				iter++)
			{
				// This is tricky. We have to dereference the const_iterator, and
				// then save a pointer to it. Because of the * operator is
				// overloaded, * and & are not inverse operations.
				operationsMap[(*iter)->GetIdentifier()] = &(**iter);
			}
		}
		return operationsMap[identifier];
	}
}
