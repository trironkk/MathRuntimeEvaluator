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

		// Parse a line of input
		CompoundExpression& ParseString(istringstream& stream);
		CompoundExpression& ParseString(string str);

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