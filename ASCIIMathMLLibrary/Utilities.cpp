#include "Utilities.h"

using std::string;
using std::istringstream;

namespace ASCIIMathMLLibrary
{
	bool isDouble(const string& str)
	{
		if (str.empty()) return false;
		bool containsDecimal = false;
		string::const_iterator it = str.begin();
		while (it != str.end())
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

	double toDouble(const string& str)
	{
		istringstream i(str);
		double x;
		if (!(i >> x))
			return 0;
		return x;
	}
}