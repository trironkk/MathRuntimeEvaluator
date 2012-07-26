#include "Operator.h"

using std::shared_ptr;
using std::list;
using std::string;
using std::vector;

namespace MathRuntimeEvaluator
{
	// A vector of the string representations of operators
	const char *operators[] = {
		"+", "-", "*", "/", "sin", "cos", "tan", "abs", "log10", "pow", "mod",
		"ln", "~", "sqrt", "log2", "log", "sum", "avg", "rand", "stddev"
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

	// Returns a string describing the usage of the inputed operator
	string& GetUsage(string identifier)
	{
		if (identifier == "+")
			return *(new string(
"x + y     Addition \n \
\n \
x: the first parameter \n \
y: the second parameter \n \
returns the sum of x and y \n"));
		else if (identifier == "/")
			return *(new string(
"x / y     Division \n \
\n \
x: the first parameter \n \
y: the second parameter \n \
returns the result of x divided by y \n"));
		else if (identifier == "*")
			return *(new string(
"x * y     Multiplication \n \
\n \
x: the first parameter \n \
y: the second parameter \n \
returns the product of x and y \n"));
		else if (identifier == "-")
			return *(new string(
"x - y     Subtraction \n \
\n \
x: the first parameter \n \
y: the second parameter \n \
returns the result of x minus y \n \
\n \
-x         Negation \n \
\n \
x: the only parameter \n \
returns the negation of x \n"));
		else if (identifier == "pow")
			return *(new string(
"pow(x,y)  Exponentiation \n \
\n \
x: the first parameter \n \
y: the second parameter \n \
returns x raised to the y power \n"));
		else if (identifier == "sin")
			return *(new string(
"sin(x)    Sine function \n \
\n \
x: the angle in radians \n \
returns the sine of an angle \n"));
		else if (identifier == "cos")
			return *(new string(
"cos(x)    Cosine function \n \
\n \
x: the angle in radians \n \
returns the cosine of an angle \n"));
		else if (identifier == "tan")
			return *(new string(
"tan(x)    Tangent function \n \
\n \
x: the angle in radians \n \
returns the tangent of an angle \n"));
		else if (identifier == "sqrt")
			return *(new string(
"sqrt(x)   Square root\n \
\n \
x: the only parameter \n \
returns the square root of x \n \
Notes: \n \
    - Does not support negative inputs. \n"));
		else if (identifier == "abs")
			return *(new string(
"abs(x)    Absolute value \n \
\n \
x: the only parameter \n \
returns the absolute value \n"));
		else if (identifier == "ln")
			return *(new string(
"ln(x)     Natural Logarithm \n \
\n \
x: the only parameter \n \
returns the natural logarithm of x \n"));
		else if (identifier == "log2")
			return *(new string(
"log2(x)   Binary Logarithm \n \
\n \
x: the only parameter \n \
returns the binary logarithm of x \n"));
		else if (identifier == "log10")
			return *(new string(
"log10(x)  Base 10 Logarithm \n \
\n \
x: the only parameter \n \
returns the base 10 logarithm of x \n"));
		else if (identifier == "log")
			return *(new string(
"log(x,y)  Generic Logarithm \n \
\n \
x: the base of the logarithm \n \
y: the input \n \
returns the base x logarithm of y \n"));
		else if (identifier == "mod")
			return *(new string(
"mod(x,y)  Modular Division \n \
\n \
x: the numerator\n \
y: the denomenator \n \
returns the remainder of x divided by y \n"));
		else if (identifier == "sum")
			return *(new string(
"sum(...)  Sum \n \
\n \
Any number of parameters \n \
\n \
returns the sum of all parameters \n"));
		else if (identifier == "avg")
			return *(new string(
"avg(...)  Average \n \
\n \
Any number of parameters \n \
\n \
returns the average of all parameters \n"));
		else if (identifier == "stddev")
			return *(new string(
"avg(...)  Standard Deviation \n \
\n \
Any number of parameters \n \
\n \
returns the standard deviation of all parameters \n"));
		else
		{
			return *(new string(
"There does not exist documentation for this operation."));
		}
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