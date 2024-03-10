#include "StopByPoint.h"

bool StopByPoint::ShouldStop()
{
    std::vector<double> difference(CurrentPoint.size());

    for (size_t i = 0; i < CurrentPoint.size(); ++i) 
    {
        difference[i] = CurrentPoint[i] - PreviousPoint[i];
    }
    return norma(difference) < Epsilon;
}