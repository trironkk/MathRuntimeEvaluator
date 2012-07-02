#ifndef OPERATION_H
#define OPERATION_H

#include <memory>

#include "Constants.h"

namespace ASCIIMathMLLibrary
{
	ExpressionSharedPointer Add(
		ExpressionSharedPointer l,
		ExpressionSharedPointer r
	);
}

#endif