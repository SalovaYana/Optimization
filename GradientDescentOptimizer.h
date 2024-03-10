#pragma once
#include "AbstrOptimization.h"

/**
 * @brief Implements the Gradient Descent optimization algorithm.
 *
 * This class extends AbstrOptimization to provide an implementation of the
 * Gradient Descent optimization algorithm. It includes methods for optimizing a given
 * function by iteratively moving in the direction of the steepest descent, as defined
 * by the negative gradient of the function.
 */
class GradientDescentOptimizer : public AbstrOptimization
{
public:
    /**
     * @brief Performs optimization using the Gradient Descent method.
     *
     * Overrides the optimise method to apply the Gradient Descent optimization process on
     * the given function, using a specified stop criteria and within a defined search area.
     *
     * @param point Reference to a vector representing the starting point for optimization.
     * @param Function Pointer to an AbstrFunction object representing the function to be optimized.
     * @param S Pointer to an AbstrStopCriteria object specifying when the optimization should stop.
     * @param Shape RectArea object defining the search bounds within which the optimization takes place.
     */
    void optimise(std::vector<double>& point,
                  AbstrFunction* Function,
                  AbstrStopCriteria* S,
                  RectArea& Shape) override;

    double FindOptimalStep(const std::vector<double>& point,
                           const std::vector<double>& direction,
                           AbstrFunction* Func,
                           double a,
                           double b,
                           double epsilon);

    double FoundRightBound(std::vector<double>point,
                           std::vector<double> gradient,
                           RectArea& Shape);
 

};


