#pragma once
#include <vector>
#include <numeric>
#include <cmath>

/**
 * @brief Abstract class for defining stopping criteria for optimization algorithms.
 *
 * This class provides an interface and implementations for common functionalities
 * used by stopping criteria, such as tracking the current and previous function
 * values, iteration counts, and points in the optimization process. Derived classes
 * must implement the ShouldStop method to define specific stopping conditions.
 */
class AbstrStopCriteria
{
protected:
    double Epsilon; ///< Tolerance for stopping criterion.
    int MaxIterationCount; ///< Maximum number of iterations.
    int CurrentIterationCount; ///< Current iteration count.
    double PreviousFunctionValue; ///< Function value at the previous point.
    double CurrentFunctionValue; ///< Function value at the current point.
    std::vector<double> PreviousPoint; ///< Previous point in the optimization process.
    std::vector<double> CurrentPoint; ///< Current point in the optimization process.
    std::vector<double> GradientValue; ///< Current gradient value.

public:
    /**
     * @brief Pure virtual function to determine whether the optimization process should stop.
     *
     * @return true if the stopping condition is met, false otherwise.
     */
    virtual bool ShouldStop() = 0;

    // Setter methods
    void SetCurrentPoint(std::vector<double>& currentPoint) { CurrentPoint = currentPoint; }
    void SetPreviousPoint(std::vector<double>& previousPoint) { PreviousPoint = previousPoint; }
    void SetGradient(std::vector<double>& gradient) { GradientValue = gradient; }
    void SetCurrentFunctionValue(double currentValue) { CurrentFunctionValue = currentValue; }
    void SetPreviousFunctionValue(double prevValue) { PreviousFunctionValue = prevValue; }
    void SetMaximumIterations(int maxIterations) { MaxIterationCount = maxIterations; }
    void SetCurrentIteration(int currentIter) { CurrentIterationCount = currentIter; }
    void SetEpsilon(double epsilonValue) { Epsilon = epsilonValue; }

    // Getter methods
    std::vector<double>& GetCurrentLocation() { return CurrentPoint; }
    int GetCurrentIteration() { return CurrentIterationCount; }
    int GetMaxIterations() { return MaxIterationCount; }
    /**
     * @brief Sets various parameters relevant to the stopping criteria.
     *
     * This function allows setting multiple parameters at once, simplifying the process
     * of updating the state of the stopping criteria.
     *
     * @param gradient The current gradient.
     * @param previousPoint The previous point in the optimization process.
     * @param currentPoint The current point in the optimization process.
     * @param prevFunctionValue The function value at the previous point.
     * @param currentFunctionValue The function value at the current point.
     * @param currentIteration The current iteration count.
     */
    void SetParameters(std::vector<double>& gradient,
        std::vector<double>& previousPoint,
        std::vector<double>& currentPoint,
        double prevFunctionValue,
        double currentFunctionValue,
        int currentIteration)
    {
        SetCurrentPoint(currentPoint);
        SetPreviousPoint(previousPoint);
        SetGradient(gradient);
        SetCurrentFunctionValue(currentFunctionValue);
        SetPreviousFunctionValue(prevFunctionValue);
        SetCurrentIteration(currentIteration);
    }
    /**
     * @brief Calculates the norm of a vector.
     *
     * @param f The vector for which to calculate the norm.
     * @return The Euclidean (L2) norm of the vector.
     */
    double norma(const std::vector<double>& f)
    {
        return std::sqrt(std::inner_product(f.begin(), f.end(), f.begin(), 0.0));
    }

    /**
     * @brief Destructor for the AbstrStopCriteria class.
     */
    ~AbstrStopCriteria() {}
};

