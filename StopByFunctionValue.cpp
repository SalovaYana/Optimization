#include "StopByFunctionValue.h"

bool StopByFunctionValue::ShouldStop()
{
    return abs(CurrentIterationCount - PreviousFunctionValue) < Epsilon;
}
