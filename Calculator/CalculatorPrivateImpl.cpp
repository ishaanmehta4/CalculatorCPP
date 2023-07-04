#include "CalculatorPrivateImpl.hpp"

// ******************** ARITHEMATIC FUNCTIONS ********************
int CalculatorPrivateImpl::sum(int num1, int num2)
{
    return num1 + num2;
}

int CalculatorPrivateImpl::difference(int num1, int num2)
{
    return num1 - num2;
}

int CalculatorPrivateImpl::product(int num1, int num2)
{
    return num1 * num2;
}

float CalculatorPrivateImpl::quotient(int num1Int, int num2Int)
{
    float num1 = num1Int, num2 = num2Int;

    if (num2 == 0)
    {
        throw std::runtime_error("Divide by zero not allowed.");
    }
    else
    {
        return num1 / num2;
    }
}

float CalculatorPrivateImpl::power(int exponent, float pow) {
    if (exponent == 0 && pow < 0) {
        throw std::runtime_error("Zero can not be raised to negative powers.");
    }
    if (exponent < 0 && pow < 1) {
        throw std::runtime_error("Negative numbers can not be raised to fractional powers.");
    }

    return std::pow(exponent, pow);
}



// ******************** HELPER FUNCTIONS ********************
bool CalculatorPrivateImpl::isDigit(char c)
{
    return c >= '0' && c <= '9';
}

void CalculatorPrivateImpl::validateAllArguments(std::string num1, std::string num2, std::string op) {
    if (num1 == "") throw std::runtime_error("First operand not found in the given input.");
    if (num2 == "") throw std::runtime_error("Second operand not found in the given input.");
    if (op == "") throw std::runtime_error("Operator not found in the given input.");
}

bool CalculatorPrivateImpl::isValidOperation(char op)
{
    const std::string VALID_OPERATIONS = "+-*x/^e";

    for (auto o : VALID_OPERATIONS)
    {
        if (o == op)
            return true; // found
    }

    return false;
}