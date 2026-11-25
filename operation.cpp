#include "Operation.h"

double Addition::exec(double a, double b)
{
    return a + b;
}

QString Addition::getSymbol() const{
    return "+";
}

double Substraction::exec(double a, double b)
{
    return a - b;
}

QString Substraction::getSymbol() const{
    return "-";
}

double Multiplication::exec(double a, double b)
{
    return a * b;
}

QString Multiplication::getSymbol() const{
    return "*";
}

double Division::exec(double a, double b)
{
    return a / b;
}

QString Division::getSymbol() const{
    return ":";
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

QString Factorial::getSymbol() const{
    return "!";
}

double Equal::exec(double a, double b){
    return a;
}

QString Equal::getSymbol() const{
    return "=";
}



