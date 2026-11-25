#include "Operation.h"

double Addition::exec(double a, double b)
{
    return a + b;
}

double Subtraction::exec(double a, double b)
{
    return a - b;
}

double Multiplication::exec(double a, double b)
{
    return a * b;
}

double Division::exec(double a, double b)
{
    return a / b;
}

double Factorial::exec(double a, double b)
{
    double result = 1;

    for (int i = 1; i <= a; i++)
    {
        result *= i;
    }

    return result;
}



