#include "VectorOperations.h"

std::vector<double> operator-(std::vector<double> v1, std::vector<double> v2)
{

    for (int i = 0; i < v1.size(); ++i) 
    {
        v1[i] -= v2[i];
    }
    return v1;

}
std::vector<double> operator+(std::vector<double> v1, std::vector<double> v2)
{
    for (int i = 0; i < v1.size(); ++i) 
    {
        v1[i] += v2[i];
    }
    return v1;
}
std::vector<double> operator/(std::vector<double> v1, std::vector<double> v2) 
{

    for (int i = 0; i < v1.size(); ++i)
    {
        v1[i] /= v2[i];
    }
    return v1;
}
std::vector<double> operator*(std::vector<double> v1, double a)
{
    for (int i = 0; i < v1.size(); ++i)
    {
        v1[i] *= a;
    }
    return v1;
}