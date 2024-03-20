#include "StochasticOptimizer.h"

unsigned seed = 0;
std::mt19937 generator(seed);

void StochasticOptimizer::optimise(std::vector<double>& start_point,
                                   AbstrFunction* function, 
                                   AbstrStopCriteria* stop_criteria, 
                                   RectArea& area) 
{
    int CurrentIterationCount = 0;
    std::uniform_real_distribution<> decision(0.0, 1.0); 
    std::vector<double> current_point = start_point;
    std::vector<double> previous_point = start_point;
    double PreviousFunctionValue;
    std::vector<double> model(current_point.size());

    do
    {
        PreviousFunctionValue = function->GetFuncValue(previous_point);
        for (size_t i = 0; i < current_point.size(); ++i) 
        {
            std::uniform_real_distribution<double> disGlobal(area.GetLower()[i], area.GetUpper()[i]);
           
            std::uniform_real_distribution<double> disLocal(current_point[i]-delta[i], current_point[i]+delta[i]);

            if (decision(generator) <= p)
            {
                model[i] = disLocal(generator);
            }
            else
            {
                model[i] = disGlobal(generator);
            }
        }

        double CurrentFunctionValue = function->GetFuncValue(model);

        if (CurrentFunctionValue < PreviousFunctionValue) 
        {
            previous_point = current_point;
            current_point = model;
            PreviousFunctionValue = CurrentFunctionValue;
            for(int i=0; i<delta.size(); ++i)
              delta[i] *= alpha;
        }

        ++CurrentIterationCount;
        stop_criteria->SetCurrentIteration(CurrentIterationCount);
        stop_criteria->SetCurrentFunctionValue(CurrentFunctionValue);
        stop_criteria->SetCurrentPoint(current_point);
        stop_criteria->SetPreviousFunctionValue(PreviousFunctionValue);
        stop_criteria->SetPreviousPoint(previous_point);
    }     
    while (!(stop_criteria->ShouldStop()));

    stop_criteria->SetCurrentPoint(current_point);
}