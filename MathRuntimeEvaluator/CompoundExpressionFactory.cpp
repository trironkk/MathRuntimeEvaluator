#include "CompoundExpressionFactory.h"

using std::string;
using std::list;

namespace MathRuntimeEvaluator
{
	CompoundExpression& NewCompoundExpression(const list<string>& identifiers)
	{
		CompoundExpression& result = *(new CompoundExpression());

		for (list<string>::const_iterator iter = identifiers.begin();
			iter != identifiers.end();
			iter++)
		{
			result.PushBack(*iter);
		}

		return result;
	}
}