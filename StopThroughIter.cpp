#include "StopThroughIter.h"

bool StopThroughIter::ShouldStop()
{
	return CurrentIterationCount == MaxIterationCount;
}