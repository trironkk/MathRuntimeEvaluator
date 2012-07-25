#include "Operator.h"

using std::shared_ptr;
using std::list;
using std::string;
using std::vector;

namespace ASCIIMathMLLibrary
{
	// A vector of the string representations of operators
	const char *operators[] = {
		"+", "-", "*", "/",
		"sin", "cos", "tan",
		"abs", "log", "pow",
		"mod", "ln", "~", "sqrt"
	};
	vector<string> OPERATORS(operators, std::end(operators));

	// A vector of the string representations of arithmetic operators
	const char *arithmeticOperators[] = {
		"+", "-", "*", "/"
	};
	vector<string> ARITHMETIC_OPERATORS(
		arithmeticOperators, std::end(arithmeticOperators));

	// Returns true if the string is an operator, and false otherwise
	bool IsOperator(const std::string str)
	{
		return find(OPERATORS.begin(), OPERATORS.end(), str) != OPERATORS.end();
	}

	// Returns true if the string is an arithmetic operator, and false otherwise
	bool IsArithmeticOperator(const std::string str)
	{
		return find(ARITHMETIC_OPERATORS.begin(),
			ARITHMETIC_OPERATORS.end(),
			str) != ARITHMETIC_OPERATORS.end();
	}

	// Returns the rank of the operator associated with the input string
	int GetOperatorRank(const string str)
	{
		if (str == "+")
			return 1;
		else if (str == "-")
			return 1;
		else if (str == "*")
			return 2;
		else if (str == "/")
			return 2;
		else if (str == "~")
			return 3;
		else
			throw ASCIIMathMLException(
"Unrecognized arithmetic operator : " + str + "."
				);
	}

	// Calls GetValue() on each of the parameters, and returns a vector of
	// results
	vector<double>& Operator::GetValuesFromParameters(
		const list<shared_ptr<Expression>>& parameters,
		const WorkingMemory& workingMemory)
	{
		vector<double>* result = new vector<double>(parameters.size());

		list<shared_ptr<Expression>>::const_iterator iter = parameters.begin();

		for (unsigned int i = 0; i < parameters.size(); i++, iter++)
		{
			(*result).at(i) =
				(*((*(*iter)).Simplify(workingMemory))).GetValue();
		}

		return *result;
	}

	// Performs this operation
	shared_ptr<Expression> Operator::Evaluate(
			const WorkingMemory& workingMemory,
			list<shared_ptr<Expression>>& parameters)
	{
		// Get the values of each of the parameters
		vector<double> values = GetValuesFromParameters(parameters,
			workingMemory);

		// Perform the operation and return
		return Evaluate(workingMemory, values);
	}
}