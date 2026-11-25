#ifndef OPERATION_H
#define OPERATION_H

class Operation
{
public:
    virtual double exec(double a, double b) = 0;
    virtual ~Operation() {}
};

class Addition : public Operation
{
public:
    double exec(double a, double b) override;
};

class Subtraction : public Operation
{
public:
    double exec(double a, double b) override;
};

class Multiplication : public Operation
{
public:
    double exec(double a, double b) override;
};

class Division : public Operation
{
public:
    double exec(double a, double b) override;
};

class Factorial : public Operation
{
public:
    double exec(double a, double b) override;
};

#endif