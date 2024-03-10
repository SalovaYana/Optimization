#include "F3.h"
#include <vector>
#include <cmath>
#include <string>


int F3::GetFuncDim() const
{
	return 4;
}

std::string F3::GetFunc() const
{
	return "(x-3)^2+(y+2)^2+(z-1)^2+(p-4)^2+5";
}

double F3::GetFuncValue(std::vector<double> x)
{
	return (x[0]-3)*(x[0]-3) + (x[1]+2) * (x[1]+2) + (x[2]-1) * (x[2]-1) + (x[3]-4) * (x[3]-4)+5;
}

std::vector<double> F3::GetFuncGrad(std::vector<double> x) const
{
	std::vector<double> gradient;
	gradient.push_back(2 * (x[0]-3)); 
	gradient.push_back(2 * (x[1]+2)); 
	gradient.push_back(2 * (x[2]-1));
	gradient.push_back(2 * (x[3]-4));
	return gradient;
}

