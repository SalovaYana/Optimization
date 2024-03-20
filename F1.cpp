#include "F1.h"

int F1::GetFuncDim() const
{
	return 2;
}

std::string F1::GetFunc() const
{ 
	return "(1-x)^2 + 100(y-x^2)^2";
}

double F1::GetFuncValue(std::vector<double> x)
{
    return (1 - x[0]) * (1 - x[0]) + 100 * (x[1] - x[0]*x[0]) * (x[1] - x[0] * x[0]);
}

std::vector<double> F1::GetFuncGrad(std::vector<double> x) const
{
    std::vector<double> gradient;

    gradient.push_back(-2 * (1 - x[0]) - 400 * x[0] * (x[1] - x[0] * x[0]));
    gradient.push_back(200 * (x[1] - x[0] * x[0]));

    return gradient;
}