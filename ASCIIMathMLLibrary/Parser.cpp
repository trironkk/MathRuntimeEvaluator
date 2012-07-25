#include "Parser.h"

using std::istringstream;
using std::stringstream;
using std::istream;
using std::string;
using std::list;
using std::stack;
using std::back_insert_iterator;
using std::fixed;

namespace ASCIIMathMLLibrary
{
	namespace Parser
	{
		using ASCIIMathMLLibrary::ILLEGAL_CHARACTERS;
		using ASCIIMathMLLibrary::IsOperator;

		// Parse a line of input
		CompoundExpression& ParseString(string str)
		{
			return ParseString(istringstream(str));
		}

		CompoundExpression& ParseString(istream& stream)
		{
			CompoundExpression* result = new CompoundExpression();
			list<string> identifiers = InternalParse(stream);
			for (list<string>::iterator iter = identifiers.begin();
				iter != identifiers.end();
				iter++)
			{
				(*result).PushBack(*iter);
			}
			
			return *result;
		}

		// Internal parsing method - necessary to clean up parenthetical recursive
		// calls. This is an implementation of the shunting yard algorithm for
		// converting the infix string expression into a postfix
		// CompoundExpression object.
		list<string> InternalParse(istream& stream,
			bool expectingClose,
			bool expectingComma)
		{
			// The list of identifiers we're going to return.
			list<string> result;

			// The previous token - this is necessary for discerning subtraction
			// from negation.
			string previousToken;

			// The current token
			string token;

			// A stack of operators
			stack<string> operators;

			while (true)
			{
				// Record the current token as the previous token and read in the
				// next token.
				previousToken = string(token);
				token = ReadNextToken(stream);

				// If the token is an operator, check its rank.
				if (IsOperator(token))
				{
					// If the token is an arithmetic operator, we follow the
					// shunting yard algorithm.
					if (IsArithmeticOperator(token))
					{
						// If the token is a "-" symbol, we need to decide whether
						// it's negation or subtraction. If it's negation, we
						// convert it to a "~" symbol, for our internal use.
						// Otherwise, leave it alone.
						if (token == "-")
							// To determine if it's negation, we do what a wise
							// man suggested here:
							// http://stackoverflow.com/a/5240781/391618
							if (IsOperator(previousToken) || previousToken == "")
								token = "~";

						// While the rank of the current token is less than the
						// rank of the top of the operators stack, push the top of
						// the operators stack to the back of the result list.
						while (operators.size() > 0 &&
							GetOperatorRank(token) < GetOperatorRank(operators.top()))
						{
							result.push_back(operators.top());
							operators.pop();
						}
						operators.push(token);
						continue;
					}

					// If the token is not an arithmetic operator, it must be a
					// function. Recursively call this method for each of the
					// parameter.

					// Construct a temporary Operator object just to determine the
					// number of parameters
					Operator* temporaryOperator = NewOperator(token); // leak?
					int parameterCount = (*temporaryOperator).GetParameterCount();
					delete temporaryOperator;

					// Assert that the next token is an open parentheses
					if (ReadNextToken(stream) != "(")
					{
						throw ASCIIMathMLException(
"Function calls must be followed by a parentheses."
							);
					}

					// Handle the case of an indefinite number of parameters.
					// Recursively call this method with both the expectingClose
					// and expectingComma flags flipped.
					if (parameterCount == -1)
					{
						// Our terminating condition is when a ")" is encountered.
						string previousDelimiter;
						list<string> tempResults;
						parameterCount = 0;
						do
						{
							// Get and record the results.
							tempResults = InternalParse(stream, true, true);
							copy(tempResults.begin(),
								tempResults.end(),
								back_insert_iterator<list<string> >(
									result));

							// Each time we pull another term, we increment the
							// parameterCount to track the number of parameters
							// we're recording. But if we didn't get anything from
							// the recursive call, it's because there wasn't a
							// term parameters. In that case, we don't want to
							// increment the parameter count.
							if (tempResults.size() > 0)
								parameterCount++;

							// Update the previous delimiter
							stream.seekg(-1, std::ios::cur);
							previousDelimiter = ReadNextToken(stream);
						} while (previousDelimiter != ")");
						
						// Convert the parameterCount to a string and record it in
						// the result list. We'll use this in CompoundExpression
						// when we need to know how many of the parameters
						// preceeding this operator belong to it. It comes after
						// all the parameters, but since the expressions are
						// push onto a stack, it's the first one to get popped
						// off.
						stringstream convert;
						convert << parameterCount;
						string tempParameterCountString;
						convert >> tempParameterCountString;
						result.push_back(tempParameterCountString);
					}
					else
					{
						// This is the standard case - a definite number of
						// parameters. Treat the results of each recursive call as
						// one expression, and copy them to the result list.
						for (int i = 0; i < parameterCount; i++)
						{
							list<string> tempResults;
							// Every parameter except for the last one will be
							// delimited by a comma.
							if (i < parameterCount - 1)
								tempResults = InternalParse(stream, false, true);
							else
								tempResults = InternalParse(stream, true, false);

							copy(tempResults.begin(),
								tempResults.end(),
								back_insert_iterator<list<string> >(result));
						}
					}
					// Since an operator with its parameters can be considered an
					// expression, we append the operator to the result list.
					result.push_back(token);
					continue;
				}

				// If the token is an open parentheses, recursively call this
				// method, run it to completion, and then copy the contents of the
				// list to the end of the result list.
				if (token == "(")
				{
					list<string> tempResults = InternalParse(stream, true);
					copy(tempResults.begin(),
						tempResults.end(),
						back_insert_iterator<list<string> >(result));
					continue;
				}

				// If the token is a close parentheses, assert that this method
				// was called recursively and then break out of this loop.
				if (token == ")")
				{
					if (expectingClose == false)
					{
						stringstream errorStream;
						errorStream << 
"Unmatched close parentheses encountered at position ";
						errorStream << stream.tellg();
						errorStream << ".";
						throw ASCIIMathMLException(errorStream.str());
					}

					// We set the parenthetical flag to false to signify that a
					// matching close parentheses has been encountered.
					expectingClose = false;

					// For the case of an indefinite number of parameters, both
					// the expectingClose and expectingComma flags will be set.
					// In this case, if we find an ")", we should flip the
					// expectingComma to false, as well.
					expectingComma = false;
					break;
				}

				// If the token is a comma, assert that this method was called
				// recursively from a function, and then break out of this loop.
				if (token == ",")
				{
					if (expectingComma == false)
					{
						stringstream errorStream;
						errorStream << 
"Unexpected comma encountered at position ";
						errorStream << stream.tellg();
						errorStream << ".";
						throw ASCIIMathMLException(errorStream.str());
					}

					// We set the expectingComma flag to false to signify that a
					// comma has been encountered.
					expectingComma = false;

					// For the case of an indefinite number of parameters, both
					// the expectingClose and expectingComma flags will be set.
					// In this case, if we find an ",", we should flip the
					// expectingClose to false, as well.
					expectingClose = false;
					break;
				}

				// If it's a newline character, break out of this loop.
				if (token == "\n" || token == "")
					break;

				// If it's not any of the above, it must be a constant or a
				// variable. For both cases, just push it to the back of the
				// results.
				result.push_back(token);
			}

			// If we were expecting a close parentheses, but never encountered
			// one, throw an exception
			if (expectingClose)
			{
				throw ASCIIMathMLException(
					"Unmatched open parentheses encountered."
				);
			}

			// If we were expecting a comma, but never encountered one, throw an
			// exception
			if (expectingComma)
			{
				throw ASCIIMathMLException(
					"Too few parameters."
				);
			}

			// Pop out the rest of the operators.
			while (operators.size() > 0)
			{
				result.push_back(operators.top());
				operators.pop();
			}

			// Return the result.
			return result;
		}

		// Return the next token, and adjust the stringstream accordingly
		string ReadNextToken(istream& stream)
		{
			string result;
			// Strip out all leading whitespaces.
			char c;
			do {
				// If there isn't a non-whitespace character, return an empty
				// string.
				if(!stream.get(c))
				{
					return result;
				}
			} while (c != '\n' && isspace(c));

			// If the first character is a newline, just return it.
			if (c == '\n')
			{
				result += c;
				return result;
			}

			// If the first character is a decimal or a number, read out a number.
			if (isdigit(c) || c == '.')
			{
				double temporary_double;
				stream.putback(c);
				stream >> temporary_double;
				stringstream convert;
				convert << fixed;
				convert << temporary_double;
				result += convert.str();
				return result;
			}

			// If the first character is a character of the alphabet, the next
			// token is either a variable name or an operator. In either case, we
			// read it and then return it.
			if (isalpha(c))
			{
				// Read in characters until whitespace or an illegal character is
				// encountered.
				stringstream temporary_stream;
				stream.putback(c);
				while (true)
				{
					// If there's nothing left to pull, stop.
					if (!stream.get(c))
						break;

					// If we pull a space or an illegal character, put it back and
					// stop.
					if (isspace(c) || strchr(ILLEGAL_CHARACTERS, c) != NULL)
					{
						stream.putback(c);
						break;
					}

					// Append the character to the back of the result.
					result += c;
				}
				return result;
			}

			// If the first character is not alpha-numeric, it must be an
			// operator. Just return it.
			result += c;
			return result;
		}
	}
}