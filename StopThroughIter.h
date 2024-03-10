#pragma once
#include "AbstrStopCriteria.h"

/**
 * @brief Implements a stopping criterion based on the number of iterations.
 *
 * This class extends `AbstrStopCriteria` to provide a stopping criterion for optimization
 * algorithms based on the number of iterations. It allows the optimization process to be
 * terminated after a predefined number of iterations, ensuring the process does not continue
 * indefinitely.
 */
class StopThroughIter : public AbstrStopCriteria
{
public:
    /**
     * @brief Determines whether the optimization process should stop based on iteration count.
     *
     * Overrides the `ShouldStop` method to implement the logic for terminating the optimization
     * process once a certain number of iterations have been executed. The method checks if the
     * current iteration count meets or exceeds a predefined limit and returns true if so, indicating
     * that the optimization process should be terminated.
     *
     * @return true if the current iteration count meets or exceeds the predefined limit; false otherwise.
     */
    bool ShouldStop() override;
};
