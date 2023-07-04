#include <iostream>
#include <string>
#include <vector>
#include <math.h>


class CalculatorPrivateImpl
{
public:
    /* data */
    /* methods */
    // arithematic methods
    int sum(int num1, int num2);
    int difference(int num1, int num2);
    int product(int num1, int num2);
    float quotient(int num1, int num2);
    float power(int exponent, float pow);

    // helper methods
    bool isDigit(char c);
    void validateAllArguments(std::string num1, std::string num2, std::string op);
    bool isValidOperation(char op);
};
