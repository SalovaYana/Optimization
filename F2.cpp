#include "F2.h"
#include <vector>
#include <cmath>
#include <string>


int F2::GetFuncDim() const
{
	return 3;
}

std::string F2::GetFunc() const
{
	return "x^2 + y^2 + z^2 + 2*x + 4*y - 6*z";
}

double F2::GetFuncValue(std::vector<double> x)
{
	return x[0] * x[0] + x[1] * x[1] + x[2] * x[2] + 2 * x[0] + 4 * x[1] - 6 * x[2];
}

std::vector<double> F2::GetFuncGrad(std::vector<double> x) const
{
	std::vector<double> gradient;
	gradient.push_back(2 * x[0] + 2); 
	gradient.push_back(2 * x[1] + 4); 
	gradient.push_back(2 * x[2] - 6); 
	return gradient;
}

