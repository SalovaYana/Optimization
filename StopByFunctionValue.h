#pragma once
#include "AbstrStopCriteria.h"

/**
 * @brief Implements a stopping criterion based on the function value.
 *
 * This class extends AbstrStopCriteria to provide a specific stopping criterion for
 * optimization algorithms. The criterion is based on the function value, typically
 * stopping the optimization process when the change in function value between iterations
 * falls below a predefined threshold.
 */
class StopByFunctionValue : public AbstrStopCriteria
{
public:
    /**
     * @brief Determines whether the optimization process should stop based on the function value.
     *
     * This method overrides the pure virtual method from AbstrStopCriteria. It implements
     * the logic to decide if the optimization process should be terminated by comparing the
     * current function value with a target value or threshold, which could involve checking
     * if the change in function value is sufficiently small, indicating convergence to a minimum.
     *
     * @return true if the stopping condition based on the function value is met, false otherwise.
     */
    bool ShouldStop() override;
};
