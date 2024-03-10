#pragma once
#include "AbstrOptimization.h"
#include <random>
#include <vector>

extern std::mt19937 generator;

/**
 * @brief Implements a Random Search optimization algorithm.
 *
 * This class specializes in performing Random Search optimization, a stochastic
 * algorithm that searches for the optimum of a function by randomly sampling points
 * within the search space. It utilizes a fixed step size (alpha) for exploration,
 * and a perturbation vector (delta) to adjust the search direction. The search process
 * continues until a specified stopping criteria is met.
 */
class StochasticOptimizer : public AbstrOptimization
{
public:
    /**
     * @brief Initializes a new instance of the StochasticOptimizer with specified parameters.
     *
     * @param _alpha The step size parameter that controls the scale of the search step.
     * @param _p The probability threshold, used to decide whether to accept a new point based on
     * a certain criterion (not directly applicable in the basic Random Search but reserved for extensions).
     * @param _delta A vector specifying the maximum perturbation applied to each dimension when generating a new point.
     */
    StochasticOptimizer(double _alpha, double _p, std::vector<double>& _delta) :
                                                                                alpha(_alpha),
                                                                                p(_p),
                                                                                delta(_delta) {}

    /**
     * @brief Executes the Random Search optimization process.
     *
     * Takes a starting point and performs random searches within the bounds specified by the RectArea object,
     * adjusting according to the delta values, until the stopping criteria are met.
     *
     * @param point A reference to a vector representing the starting point for optimization.
     * @param function A pointer to an AbstrFunction object representing the function to be optimized.
     * @param stopCriteria A pointer to an AbstrStopCriteria object determining when the search should stop.
     * @param area A RectArea object defining the bounds within which the search is performed.
     */
    void optimise(std::vector<double>& start_point,
                  AbstrFunction* function,
                  AbstrStopCriteria* stop_criteria,
                  RectArea& area)  override;

    double alpha; ///< The step size parameter, controlling the search step magnitude.
    double p;     ///< Probability threshold for decision making (reserved for extended strategies).
    std::vector<double> delta; ///< Perturbation vector for adjusting the search direction.
};
