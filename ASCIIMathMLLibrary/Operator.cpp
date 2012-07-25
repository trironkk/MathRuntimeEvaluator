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
		"%", "ln", "~", "sqrt"
	};
	vector<string> OPERATORS(operators, std::end(operators));

	// Returns true if the string is an operator, and false otherwise
	bool IsOperator(const std::string str)
	{
		return find(OPERATORS.begin(), OPERATORS.end(), str) != OPERATORS.end();
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
		else if (str == "%")
			return 2;
		else if (str == "^")
			return 4;
		else if (str == "~")
			return 5;
		else
			return 3;
	}

	// Basic constructor
	Operator::Operator() {}

	// Calls GetValue() on each of the parameters, and returns a vector of
	// results
	shared_ptr<vector<double>> Operator::GetValuesFromParameters(
		const list<shared_ptr<Expression>>& parameters,
		const WorkingMemory& workingMemory)
	{
		shared_ptr<vector<double>> result(new vector<double>(parameters.size()));

		list<shared_ptr<Expression>>::const_iterator iter = parameters.begin();

		for (unsigned int i = 0; i < parameters.size(); i++, iter++)
		{
			(*(result)).at(i) =
				(*((*(*iter)).Simplify(workingMemory))).GetValue();
		}

		return result;
	}
}