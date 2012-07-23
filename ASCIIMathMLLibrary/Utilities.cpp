#include "Utilities.h"

using std::string;
using std::istringstream;

namespace ASCIIMathMLLibrary
{
	bool IsDouble(const string& str)
	{
		if (str.empty()) return false;
		bool containsDecimal = false;
		for (string::const_iterator it = str.begin();
			it != str.end();
			it++)
		{
			if (isdigit(*it) == false)
			{
				if ((*it) == '.')
				{
					if (containsDecimal) { return false; }
					else { containsDecimal = true; }
				}
				else
				{
					return false;
				}
			}
		}
		return true;
	}

	double ToDouble(const string& str)
	{
		istringstream i(str);
		double x;
		if (!(i >> x))
			return 0;
		return x;
	}
}