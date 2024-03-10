#pragma once
#include "AbstrFunction.h"
/**
 * @brief Class representing a specific two-dimensional quadratic function.
 *
 * This class inherits from AbstrFunction and implements the functionality for
 * a two-dimensional function.
 */
class F1: public AbstrFunction
{
private:
    std::vector<double> x;
public:
    std::string GetFunc() const override;
    int GetFuncDim() const override;
    double GetFuncValue(std::vector<double> x) override;
    std::vector<double> GetFuncGrad(std::vector<double> x) const override;

};

