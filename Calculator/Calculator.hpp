#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "CalculatorPrivateImpl.hpp"

class CalculatorPrivateImpl;

class Calculator
{
private:
    CalculatorPrivateImpl *calculator_impl;

public:
    Calculator();

    // driver methods
    float calculate(std::string input);
    float calculate(int num1, std::string op, int num2);
    float calculate(int num1, int num2, std::string op);
};
