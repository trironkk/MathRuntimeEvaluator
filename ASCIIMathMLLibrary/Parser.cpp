#include "Parser.h"

using std::istringstream;
using std::stringstream;
using std::string;
using std::list;
using std::stack;

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

		CompoundExpression& ParseString(istringstream& stream)
		{
			CompoundExpression result;
			list<string> identifiers = InternalParse(stream);
			for (list<string>::iterator iter = identifiers.begin();
				iter != identifiers.end();
				iter++)
			{
				result.PushBack(*iter);
			}
			return result;
		}

		// Internal parsing method - necessary to clean up parenthetical recursive
		// calls.
		list<string> InternalParse(istringstream& stream)
		{
			list<string> result;
			string token;
			stack<string> operators;
			list<string> parameters;

			token = ReadNextToken(stream);
			while (token != "\n")
			{
				// If the token is an operator, check its rank.
				if (IsOperator(token))
				{
					// If the token is a "-" symbol, we need to decide whether
					// it's negation or subtraction. If it's negation, we convert
					// it to a "~" symbol, for our internal use. Otherwise, leave
					// it alone.
				}
				std::cout << token << ' ' << IsOperator(token) << std::endl;
				result.push_back(string(token));

				// Read in the next token.
				token = ReadNextToken(stream);
			}
			return result;
		}

		// Return the next token, and adjust the stringstream accordingly
		string ReadNextToken(istringstream& stream)
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
				stringstream temporary_stream();
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