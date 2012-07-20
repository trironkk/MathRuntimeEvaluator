#ifndef OPERATOR_FACTORY
#define OPERATOR_FACTORY

#include <string>

#include "Operator.h"
#include "Add.h"
#include "Divide.h"
#include "Multiply.h"
#include "Subtract.h"
#include "Sin.h"
#include "Cos.h"
#include "Tan.h"
#include "AbsoluteValue.h"
#include "CommonLogarithm.h"
#include "Exponentiate.h"
#include "Modulo.h"
#include "NaturalLogarithm.h"
#include "Negate.h"
#include "SquareRoot.h"

namespace ASCIIMathMLLibrary
{
	Operator& NewOperator(const std::string& identifier);
}

#endif