#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <cmath>

/**
 * @brief Abstract class for representing functions.
 *
 * This class provides an interface for mathematical functions, including
 * methods to retrieve the function's value, its gradient, and a string
 * representation of the function.
 */
class AbstrFunction
{
protected:
    std::vector<double> x; ///< Vector of function arguments.

public:
    /**
     * @brief Gets the string representation of the function.
     *
     * @return A string representing the mathematical function.
     */
    virtual std::string GetFunc() const = 0;

    /**
     * @brief Gets the dimensionality of the function.
     *
     * @return The dimension of the function as an integer.
     */
    virtual int GetFuncDim() const = 0;

    /**
     * @brief Calculates the value of the function for a given vector of inputs.
     *
     * @param x A vector of doubles representing the inputs to the function.
     * @return The calculated value of the function as a double.
     */
    virtual double GetFuncValue(std::vector<double> x) = 0;

    /**
     * @brief Calculates the gradient of the function for a given vector of inputs.
     *
     * @param x A vector of doubles representing the inputs to the function.
     * @return A vector of doubles representing the gradient of the function.
     */
    virtual std::vector<double> GetFuncGrad(std::vector<double> x) const = 0;
};

