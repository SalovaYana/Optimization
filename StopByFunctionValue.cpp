#include "StopByFunctionValue.h"

bool StopByFunctionValue::ShouldStop()
{
    return std::abs(CurrentIterationCount - PreviousFunctionValue) < Epsilon;
}
