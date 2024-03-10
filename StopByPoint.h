#pragma once
#include "AbstrStopCriteria.h"

/**
 * @brief Implements a stopping criterion based on the proximity of successive points.
 *
 * This class extends `AbstrStopCriteria` to define a stopping criterion for optimization
 * algorithms based on the distance between two consecutive points in the search space. The
 * optimization process is stopped when the distance between successive points is less than a
 * specified threshold, indicating that the algorithm is making minimal progress and is
 * potentially close to a local minimum.
 */
class StopByPoint : public AbstrStopCriteria
{
public:
    /**
     * @brief Determines whether the optimization process should stop based on the distance between successive points.
     *
     * Overrides the `ShouldStop` method to implement logic that evaluates the distance between
     * the current point and the previous point in the optimization process. If this distance is
     * below a certain threshold, the function returns true, indicating that the optimization process
     * should be terminated due to the proximity of the points suggesting convergence.
     *
     * @return true if the distance between two consecutive points is below a predefined threshold; false otherwise.
     */
    bool ShouldStop() override;
};
