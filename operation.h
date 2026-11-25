#ifndef OPERATION_H
#define OPERATION_H

#include <QString>

class Operation
{
public:
    virtual double exec(double a, double b) = 0;
    virtual QString getSymbol() const = 0;
    virtual ~Operation() {}
};

class Addition : public Operation
{
public:
    double exec(double a, double b) override;
    QString getSymbol() const override;
};


class Substraction : public Operation
{
public:
    double exec(double a, double b) override;
    QString getSymbol() const override;
};

class Multiplication : public Operation
{
public:
    double exec(double a, double b) override;
    QString getSymbol() const override;
};

class Division : public Operation
{
public:
    double exec(double a, double b) override;
    QString getSymbol() const override;
};

class Factorial : public Operation
{
public:
    double exec(double a, double b) override;
    QString getSymbol() const override;
};

class Equal : public Operation
{
public:
    double exec(double a, double b) override;
    QString getSymbol() const override;
};

#endif