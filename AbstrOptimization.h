#pragma once
#include<vector>
#include "AbstrFunction.h"
#include "RectArea.h"
#include "AbstrStopCriteria.h"

/**
 * @brief Abstract class for representing optimization algorithms.
 *
 * This class serves as a base for different optimization algorithms, providing
 * a common interface for the optimization process. It is designed to work with
 * mathematical functions, stop criteria, and search areas.
 */
class AbstrOptimization
{
protected:

public:
    /**
     * @brief Default constructor for the AbstrOptimization class.
     */
    AbstrOptimization() {};

    /**
     * @brief Destructor for the AbstrOptimization class.
     */
    ~AbstrOptimization() {}

    /**
     * @brief Pure virtual function to perform the optimization process.
     *
     * This method must be implemented by derived classes to perform the
     * optimization using specific algorithms. It modifies the given point
     * to approach an optimum of the provided function within the specified
     * search area, stopping according to the given criteria.
     *
     * @param Point Reference to a vector of doubles representing the starting
     * point or current best estimate of the optimum.
     * @param Func Pointer to an AbstrFunction object representing the function
     * to be optimized.
     * @param Stop Pointer to an AbstrStopCriteria object representing the
     * criteria to stop the optimization process.
     * @param Shape Reference to a RectArea object representing the search area
     * within which the optimization is to be performed.
     */
    virtual void optimise(std::vector<double>& Point,
        AbstrFunction* Func,
        AbstrStopCriteria* Stop,
        RectArea& Shape) = 0;
};




