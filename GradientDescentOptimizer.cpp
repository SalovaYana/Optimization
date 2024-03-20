#include "GradientDescentOptimizer.h"
#include "VectorOperations.h"
#include <algorithm>

void GradientDescentOptimizer::optimise
                                        (std::vector<double>& InitialPoint,
                                         AbstrFunction* ObjectiveFunction,
                                         AbstrStopCriteria* StopCriteria,
                                         RectArea& SearchSpace)
{
    std::vector<double> PreviousPoint(InitialPoint);
    double PreviousFunctionValue = ObjectiveFunction->GetFuncValue(PreviousPoint);
    std::vector<double> Gradient = ObjectiveFunction->GetFuncGrad(InitialPoint);
    int CurrentIteration = 0; 
    double CurrentFunctionValue;
    double b;
    double alpha;

     do
     {
        b = FoundRightBound(InitialPoint, Gradient, SearchSpace);
        alpha = FindOptimalStep(InitialPoint, Gradient, ObjectiveFunction, 0, b, 0.001);

        for (size_t i = 0; i < InitialPoint.size(); ++i)
        {
            PreviousPoint[i] = InitialPoint[i];
            InitialPoint[i]  = InitialPoint[i] - alpha * Gradient[i];
        }

        PreviousFunctionValue = ObjectiveFunction->GetFuncValue(PreviousPoint);
        CurrentFunctionValue = ObjectiveFunction->GetFuncValue(InitialPoint);
        Gradient = ObjectiveFunction->GetFuncGrad(InitialPoint);
        ++CurrentIteration;

     
        StopCriteria->SetCurrentIteration(CurrentIteration);
        StopCriteria->SetCurrentFunctionValue(CurrentFunctionValue);
        StopCriteria->SetCurrentPoint(InitialPoint);
        StopCriteria->SetPreviousFunctionValue(PreviousFunctionValue);
        StopCriteria->SetPreviousPoint(PreviousPoint);
        StopCriteria->SetGradient(Gradient);

     } while (!(StopCriteria->ShouldStop()) && CurrentIteration < StopCriteria->GetMaxIterations()
         && CurrentFunctionValue > 1e-16);
}

double GradientDescentOptimizer::FindOptimalStep
                                                (const std::vector<double>& point, 
                                                 const std::vector<double>& direction, 
                                                 AbstrFunction* Func, 
                                                 double a, 
                                                 double b, 
                                                 double epsilon) 
{
    double l = a, r = b, temp_l, temp_r;

    while (r - l > epsilon) 
{
        temp_l = (2 * l + r) / 3;
        temp_r = (l + 2 * r) / 3;
        if (Func->GetFuncValue(point - direction * temp_l) < Func->GetFuncValue(point - direction * temp_r))
        {
            r = temp_r;
        }
        else 
        {
            l = temp_l;
        }
    }
    return (l + r) / 2;
}


double GradientDescentOptimizer::FoundRightBound(std::vector<double>point, 
                                                 std::vector<double> gradient, 
                                                 RectArea& Shape)
{
    std::vector<double> steps;

    for (size_t i = 0; i < point.size(); ++i)
    {
        double stepPos = std::numeric_limits<double>::max();
        double stepNeg = std::numeric_limits<double>::max();
        
        if (std::abs(gradient[i]) > 1e-16)
        {
            if (gradient[i] < 0)
            { 
                stepPos = (Shape.GetUpper()[i] - point[i]) / (-gradient[i]);
            }
            else if (gradient[i] > 0)
            { 
                stepNeg = (point[i] - Shape.GetLower()[i]) / gradient[i];
            }
        
            double step = std::min(stepPos, stepNeg);
            if (step != std::numeric_limits<double>::max())
            {
                steps.push_back(step);
            }
        }
    }

    return *std::min_element(steps.begin(), steps.end());
}