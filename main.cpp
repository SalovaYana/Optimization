
#include <iostream>
#include <cmath>
#include <locale.h>

#include "AbstrFunction.h"
#include "AbstrOptimization.h"
#include "AbstrStopCriteria.h"
#include "F1.h"
#include "F2.h"
#include "F3.h"
#include "GradientDescentOptimizer.h"
#include "RectArea.h"
#include "StochasticOptimizer.h"
#include "StopByFunctionValue.h"
#include "StopByGradVal.h"
#include "StopByPoint.h"
#include "StopThroughIter.h"




int main()
{
	int FunctionToChoose;
    int AreaToChoose;
    int StopCriteriaToChoose;
    int MethodToChoose;
    double Epsilon;
    int MaxIterationCount;
    double p;
    double alpha;

    std::vector<double> delta({ -1, -1 });
    std::vector<double> lower_point{ -1, -1 };
    std::vector<double> upper_point{ 1, 1 };
    std::vector<double> init_point{ 0.5, 0.5 };


    RectArea area(2, lower_point, upper_point);
    AbstrFunction* function = nullptr;
    AbstrOptimization* optimization = nullptr;
    AbstrStopCriteria* Stop = nullptr;

    bool RightChoice = true;
    int answer = 1;

    while (answer) 
    {

        while (RightChoice) 
        {
            std::cout << "Select function." << std::endl <<
                "Press 1 - for the 2D function (x+2y-7)^2+(2x+y-5)^2." << std::endl <<
                "Press 2 - for the 3D function x^2 + y^2 + z^2 + 2x + 4y - 6z." << std::endl <<
                "Press 3 - for the 4D function (x-3)^2+(y+2)^2+(z-1)^2+(p-4)^2+5." << std::endl;
            std::cin >> FunctionToChoose;


            if (FunctionToChoose == 1 || FunctionToChoose == 2 || FunctionToChoose == 3) 
                RightChoice = false;
            else 
                std::cout << "You press the wrong number." << std::endl;
        }

        RightChoice = true;
        if (FunctionToChoose == 1) 
        {
            function = new F1();
        }
        else if (FunctionToChoose == 2) 
        {
            function = new F2();
        }
        else if (FunctionToChoose == 3) 
        {
            function = new F3();
        }


        while (RightChoice) 
        {
            std::cout << "Do you want to enter the coordinates of the parallelepiped or enter predefined ones." << std::endl <<
                "Press 1 - to enter coordinates." << std::endl <<
                "Press 2 - for preset coordinates." << std::endl <<
                "For a two-dimensional function, the region suggested is (-10, -10) x (10, 10)." << std::endl <<
                "For a 3D function, the region suggested is (-4, -4, -4) x (4, 4, 4)." << std::endl <<
                "For a four-dimensional function, the region suggested is (-7, -7, -7, -7) x (6, 6, 6, 6)." << std::endl;
            std::cin >> AreaToChoose;

            if (AreaToChoose == 1 || AreaToChoose == 2) 
                RightChoice = false;
            else 
                std::cout << "You have selected a non-existent mode." << std::endl;
        }

        RightChoice = true;

        lower_point.resize(function->GetFuncDim());
        upper_point.resize(function->GetFuncDim());
       
        if (AreaToChoose == 1) 
        {
            while (RightChoice)
            {
                std::cout << "Enter the coordinates of the parallelepiped, according to " << function->GetFuncDim() << " things in each line, first the minimum, then the maximum." << std::endl;
                for (int i = 0; i < function->GetFuncDim(); ++i)
                {
                    std::cin >> lower_point[i];
                }
                for (int i = 0; i < function->GetFuncDim(); ++i)
                {
                    std::cin >> upper_point[i];
                }

                area.SetArea(function->GetFuncDim(), lower_point, upper_point);


                RightChoice = false;
                for (int i = 0; i < lower_point.size(); ++i) 
                {
                    if (lower_point[i] > upper_point[i]) 
                    {
                        std::cout << "You enter wrong data. Lower point greater than upper point." << std::endl;
                        RightChoice = true;
                        break;
                    }
                }
            }
        }
        else 
        {
            switch (function->GetFuncDim())
            {
            case 2:
            {
                std::vector<double> lower({ -10,-10 });
                std::vector<double> upper({ 10,10 });
                area.SetArea(function->GetFuncDim(), lower, upper);
                break;
            }
            case 3:
            {
                std::vector<double> lower({ -4,-4,-4 });
                std::vector<double> upper({ 4,4,4 });
                area.SetArea(function->GetFuncDim(), lower, upper);
                break;

            }
            case 4:
            {
                std::vector<double> lower({ -7,-7,-7,-7 });
                std::vector<double> upper({ 6,6,6,6 });
                area.SetArea(function->GetFuncDim(), lower, upper);
                break;
            }
            }

        }

        RightChoice = true;

        while (RightChoice) 
        {
            std::cout << "Select stopping method" << std::endl <<
                "Press 1 - gradient stop (gradient descent)." << std::endl <<
                "Press 2 - stop at two closest points (gradient descent)." << std::endl <<
                "Press 3 - stop by number of iterations (gradient descent or random search)." << std::endl <<
                "Press 4 - stop at the two closest values of the function (gradient descent)." << std::endl;
            
            std::cin >> StopCriteriaToChoose;

            if (StopCriteriaToChoose == 1 || StopCriteriaToChoose == 2 || StopCriteriaToChoose == 3 || StopCriteriaToChoose == 4) 
                RightChoice = false;
            else 
                std::cout << "You press the wrong number." << std::endl;
        }
        switch (StopCriteriaToChoose)
        {
        case 1:
        {
            Stop = new StopByGradVal();
            break;
        }
        case 2: 
        {
            Stop = new StopByPoint();
            break;
        }
        case 3:
        {
            Stop = new StopThroughIter();
            break;
        }

        case 4: 
        {
            
            Stop = new StopByFunctionValue();
            break;
        }
        }


        RightChoice = true;
        while (RightChoice) 
        {
            std::cout << "Enter the epsilon at which the stop will be made." << std::endl;
            std::cin >> Epsilon;
            std::cout << "Enter the maximum number of iterations." << std::endl;
            std::cin >> MaxIterationCount;

            Stop->SetMaximumIterations(MaxIterationCount);
            Stop->SetEpsilon(Epsilon);

            if (MaxIterationCount > 0 && Epsilon > 0) 
                RightChoice = false;
            if (MaxIterationCount < 0) 
                std::cout << "MaxIterationCount must be > 0" << std::endl;
            if (Epsilon < 0) 
                std::cout << "Epsilon must be > 0" << std::endl;
        }
        

        RightChoice = true;
        while (RightChoice) 
        {
            std::cout << "Select a minimum search method." << std::endl <<
                "Press 1 - gradient descent" << std::endl <<
                "Press 2 - random search" << std::endl;
            std::cin >> MethodToChoose;
            if ((MethodToChoose == 1 && (StopCriteriaToChoose == 1 || StopCriteriaToChoose == 2 || StopCriteriaToChoose == 3 || StopCriteriaToChoose == 4)) || (MethodToChoose == 2 && (StopCriteriaToChoose == 3 || StopCriteriaToChoose == 4))) 
                RightChoice = false;
            else 
                std::wcout << "You have chosen a method that is not suitable for the stopping method you chose earlier." << std::endl;
        }

        RightChoice = true;
        while (RightChoice)
        {
            std::cout << "Enter starting point." << std::endl;
            init_point.resize(function->GetFuncDim());

            RightChoice = false;
            for (int i = 0; i < init_point.size(); ++i) 
            {
                std::cin >> init_point[i];
                if (init_point[i] > area.GetUpper()[i] || init_point[i] < area.GetLower()[i])
                {
                    std::cout << "Initial point must be in parallelepiped" << std::endl;
                    RightChoice = true;
                    break;
                }
            }
            
        }

        if (MethodToChoose == 1)
        {
            optimization = new GradientDescentOptimizer();
        }
        else 
        {
            RightChoice = true;
            while (RightChoice) 
            {
                std::cout << "Enter alpha." << std::endl;
                std::cin >> alpha;
                std::cout << "Enter p" << std::endl;
                std::cin >> p;
                delta.resize(function->GetFuncDim());
                double Delta;
                std::cout << "Enter delta" << std::endl;
                std::cin >> Delta;
                for (int i = 0; i < delta.size(); ++i) 
                {
                    delta[i] = Delta;
                }
                if ((Delta > 0) && (p >  0 && p < 1) && (alpha > 0 && alpha < 1)) RightChoice = false;
                if (Delta < 0) std::cout << "Delta must be > 0" << std::endl;
                if (p < 0 || p > 1) std::cout <<"p must be 0 < p < 1" << std::endl;
                if (alpha < 0 || alpha > 1) std::cout << "alpha must be 0 < alpha < 1" << std::endl;
            }
            optimization = new StochasticOptimizer(alpha, p, delta);
        }



        optimization->optimise(init_point, function, Stop, area);
        std::vector<double> find_point(Stop->GetCurrentLocation());
        std::cout << "Minimum point: ";
        for (auto i : find_point) 
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        std::cout << "Value at minimum: ";
        std::cout << function->GetFuncValue(find_point);
        std::cout << std::endl;
        std::cout << "Number of iterations: ";
        std::cout << Stop->GetCurrentIteration();
        answer = 0;
        
    }
    delete Stop;
    delete function;
    delete optimization;
    return 0;
}







