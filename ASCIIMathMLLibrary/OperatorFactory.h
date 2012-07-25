#ifndef OPERATOR_FACTORY
#define OPERATOR_FACTORY

#include <string>

#include "Operator.h"

#include "Add.h"
#include "Divide.h"
#include "Multiply.h"
#include "Subtract.h"
#include "Negate.h"

#include "Pow.h"
#include "Sin.h"
#include "Cos.h"
#include "Tan.h"
#include "Sqrt.h"
#include "Abs.h"
#include "Log.h"
#include "Ln.h"
#include "Mod.h"

namespace ASCIIMathMLLibrary
{
	class Operator;

	Operator* NewOperator(const std::string& identifier);
}

#endif