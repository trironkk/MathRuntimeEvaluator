#include "Operations.h"

#include <iostream>

using namespace std;
using namespace MathRuntimeEvaluator;

int main()
{
	cout << Operations::GetUsage("+") << endl;
	cout << Operations::GetParameterCount("-") << endl;
	cout << Operations::IsFunction("/") << endl;
	cout << Operations::GetUsage("+") << endl;
	
	cin.get();
}