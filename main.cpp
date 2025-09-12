#include <iostream>
#include <cmath>

#define eps 1E-12

double function_1(double x){
    return 2 * x - log10(x) - 7;
}

double function(double x){
    return 0.5 * (log10(x) + 7);
}

double Bisection_method(double a , double b , double epsilon){
    double x_avg = 0;
    double x_1 = 0;
    double x_2 = 0;

    x_avg = (a + b) / 2;

    do {
        if(fabs(function_1(x_avg)) == 0){
            return x_avg;
        }
        else if(function_1(x_avg) * function_1(a) < 0 and function_1(x_avg) * function_1(b) > 0){
            a = a;
            b = x_avg;

        }
        else if(function_1(x_avg)* function_1(b) and function_1(x_avg) * function_1(a) > 0){
            a = x_avg;
            b = b;
        }
        x_1 = x_avg;
        x_avg = (a + b)/2;
    } while (std::fabs(x_1 - x_2) >= epsilon);

    return x_avg;

}



double Simple_Iteration_Method(double a , double b , double epsilon , double x_0){
    double x_b = 0;
    do{
        x_b = x_0;
        x_0 = function(x_0);

    }while(std::fabs(x_b - x_0) >= epsilon);

    return x_0;
}


double Aikten_Acceleration_Formula(double x_0 , double x_1 , double x_2 ){
    return x_0 - std::pow(x_1 - x_0 , 2) / (x_2 - 2 * x_1 + x_0);
}


double Aitken_Method(double x_0, double epsilon){

    double x_1 = 0;
    double x_2 = 0;

    double x_2_old = 0;

    x_1 = function(x_0);
    x_2 = function(x_1);

    while(std::fabs(x_1 - x_0) >= epsilon){
        x_2_old = x_2;
        x_2 = Aikten_Acceleration_Formula(x_0 , x_1 , x_2);
        x_0 = x_1;
        x_1 = x_2_old;
    }

    return x_2;
}


double Steffensen_Acceleration_Formula(double x_0){
    return x_0 - (std::pow(function(x_0) - x_0 , 2)) / (function(function(x_0)) - 2 * function(x_0) + x_0);
}

double Steffensen_Method(double x_0 , double epsilon){
    double x_1 = 0;

    while (std::fabs(x_1 - x_0) >= epsilon){
        x_1 = Steffensen_Acceleration_Formula(x_0);
        x_0 = x_1;
    }

    return x_1;
}




int main() {

/*           二分法、简单迭代法及其加速法求解非线性方程             */

    double a = 0;
    double b = 0;
    double epsilon = 0;
    double x_0 = 0;

    std::cout << "请输入隔根区间：" << std::endl;
    std::cin >> a >> b;

    std::cout << "请输入绝对误差限：" << std::endl;
    std::cin >> epsilon;

    std::cout << "请输入初值x_0：" << std::endl;
    std:: cin >> x_0;

    std::cout << "二分法求解结果" << Bisection_method(a , b , epsilon) << std::endl;
    std::cout << "简单迭代法求解结果：" << Simple_Iteration_Method(a , b , epsilon , x_0) << std::endl;
    std::cout << "Aitken加速法求解结果：" << Aitken_Method(x_0 , epsilon) << std::endl;
    std::cout << "Steffensen加速法求解结果：" << Steffensen_Method(x_0 , epsilon) << std::endl;

    return 0;
}

