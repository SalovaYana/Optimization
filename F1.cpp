#include "F1.h"

int F1::GetFuncDim() const
{
	return 2;
}

std::string F1::GetFunc() const
{
	return "(x+2y-7)^2+(2x+y-5)^2";
}

double F1::GetFuncValue(std::vector<double> x)
{
    return (x[0] + 2 * x[1] - 7) * (x[0] + 2 * x[1] - 7) + (2 * x[0] + x[1] - 5) * (2 * x[0] + x[1] - 5);
}

std::vector<double> F1::GetFuncGrad(std::vector<double> x) const
{
    std::vector<double> gradient;

    gradient.push_back(2 * (x[0] + 2 * x[1] - 7) + 4 * (2 * x[0] + x[1] - 5));
    gradient.push_back(4 * (x[0] + 2 * x[1] - 7) + 2 * (2 * x[0] + x[1] - 5));

    return gradient;
}