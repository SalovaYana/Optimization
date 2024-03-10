#include "StopByGradVal.h"

bool StopByGradVal::ShouldStop()
{
    return norma(GradientValue) < Epsilon;
}
