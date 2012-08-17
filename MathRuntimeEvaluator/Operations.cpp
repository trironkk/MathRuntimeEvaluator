#include "Operations.h"

#include "MathRuntimeEvaluatorException.h"

using std::pair;
using std::set;
using std::map;
using std::list;
using std::string;
using std::shared_ptr;

namespace MathRuntimeEvaluatorNamespace
{
	// Returns a vector of all available operations
	const list<shared_ptr<Operation>>& Operations::GetOperations()
	{
		static bool initialized;
		static list<shared_ptr<Operation>> operations;
		if (initialized == false)
		{
			// Operators
			operations.push_back(*new shared_ptr<Operation>(new Add()));
			operations.push_back(*new shared_ptr<Operation>(new Subtract()));
			operations.push_back(*new shared_ptr<Operation>(new Multiply()));
			operations.push_back(*new shared_ptr<Operation>(new Divide()));
			operations.push_back(*new shared_ptr<Operation>(new Negate()));

			// Functions
			operations.push_back(*new shared_ptr<Operation>(new Pow()));
			operations.push_back(*new shared_ptr<Operation>(new Sin()));
			operations.push_back(*new shared_ptr<Operation>(new Cos()));
			operations.push_back(*new shared_ptr<Operation>(new Tan()));
			operations.push_back(*new shared_ptr<Operation>(new Sqrt()));
			operations.push_back(*new shared_ptr<Operation>(new Abs()));

			operations.push_back(*new shared_ptr<Operation>(new Ln()));
			operations.push_back(*new shared_ptr<Operation>(new Log2()));
			operations.push_back(*new shared_ptr<Operation>(new Log10()));
			operations.push_back(*new shared_ptr<Operation>(new Log()));

			// Assignments
			operations.push_back(*new shared_ptr<Operation>(new Gets()));

			initialized = true;
		}
		return operations;
	}
	
	// Returns true if the identifier is associated with an operation, and
	// false otherwise
	const bool Operations::IsOperation(string identifier) 
	{
		static bool initialized;
		static set<string> isOperationSet;
		if (initialized == false)
		{
			list<shared_ptr<Operation>> operations = GetOperations();
			for (list<shared_ptr<Operation>>::const_iterator iter =
					operations.begin();
				iter != operations.end();
				iter++)
			{
				isOperationSet.insert((*iter)->GetIdentifier());
			}
			initialized = true;			
		}
		return isOperationSet.find(identifier) != isOperationSet.end();
	}
	
	// Returns true if the operation is a function, and false otherwise
	const bool Operations::IsFunction(string identifier) 
	{
		return Operations::GetOperation(identifier)->IsFunction();
	}

	// Returns the number of parameters the operation takes in
	const int Operations::GetParameterCount(string identifier)
	{
		return Operations::GetOperation(identifier)->GetParameterCount();
	}

	// Returns the rank of an operation
	const int Operations::GetRank(string identifier)
	{
		return Operations::GetOperation(identifier)->GetRank();
	}

	// Returns a helpful string describing how the operation is used
	string Operations::GetUsage(string identifier)
	{
		return Operations::GetOperation(identifier)->GetUsage();
	}

	// Returns a shared pointer to the operation
	shared_ptr<Operation> Operations::GetOperation(string identifier)
	{
		static bool initialized;
		static map<string, shared_ptr<Operation>> operationsMap;
		if (initialized == false)
		{
			list<shared_ptr<Operation>> operations = GetOperations();
			for (list<shared_ptr<Operation>>::const_iterator iter =
						operations.begin();
					iter != operations.end();
					iter++)
			{
				operationsMap[(*iter)->GetIdentifier()] = (*iter);
			}
			initialized = true;
		}

		if (IsOperation(identifier) == false)
		{
			throw new MathRuntimeEvaluatorException(
"Identifier does not correspond to an operation."
				);
		}
		
		return operationsMap[identifier];
	}
}
