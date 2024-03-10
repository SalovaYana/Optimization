#pragma once
#include "AbstrStopCriteria.h"

/**
 * @brief Implements a stopping criterion based on the gradient value.
 *
 * This class is derived from AbstrStopCriteria and specifies a stopping criterion for
 * optimization processes based on the magnitude of the gradient. The optimization process
 * is typically stopped when the norm of the gradient is sufficiently small, indicating
 * that a local minimum has been reached or that further improvements will be marginal.
 */
class StopByGradVal : public AbstrStopCriteria
{
public:
    /**
     * @brief Determines whether the optimization process should stop based on the gradient value.
     *
     * Overrides the ShouldStop method to implement logic for stopping the optimization
     * process. The criterion involves evaluating the norm of the gradient vector at the
     * current point in the optimization process. If the norm is below a specified threshold,
     * this indicates proximity to a local minimum, and the method returns true to stop
     * the optimization process.
     *
     * @return true if the norm of the gradient is below a predefined threshold, indicating
     * that the optimization process should be terminated; false otherwise.
     */
    bool ShouldStop() override;
};


