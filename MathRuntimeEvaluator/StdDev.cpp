#include "StdDev.h"

using std::shared_ptr;
using std::list;
using std::vector;
using std::string;

namespace MathRuntimeEvaluator
{
	// Performs this operation
	shared_ptr<Expression> StdDev::Evaluate(
			const WorkingMemory& workingMemory,
			vector<double>& values)
	{
		double sum = 0;
		for (int i = 0; i < values.size(); i++)
		{
			sum += values[i];
		}
		double avg = sum / values.size();

		double stddev = 0;
		for (int i = 0; i < values.size(); i++)
		{
			double temp = (values[i] - avg);
			stddev += temp * temp;
		}

		stddev = sqrt(stddev / values.size());

		return shared_ptr<Expression>(
			new Constant(stddev)
		);
	}

	// Gets a string representation of this operation
	string& StdDev::GetStringRepresentation()
	{
		return *(new string("sum"));
	}
}