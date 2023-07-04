#include "Calculator.hpp"

// ******************** DRIVER FUNCTIONS ********************
float Calculator::calculate(std::string input)
{
    std::string n1s = "", n2s = "", ops = "";

    for (auto c : input)
    {
        if (calculator_impl->isDigit(c))
        {
            if (ops == "")
                n1s = n1s + c;
            else
                n2s = n2s + c;
        }
        else
        {
            ops = c;
            if (!calculator_impl->isValidOperation(c))
            {
                throw std::runtime_error("Invalid operation: " + ops);
            }
        }
    }

    calculator_impl->validateAllArguments(n1s, n2s, ops);
    return this->calculate(stoi(n1s), stoi(n2s), ops);
}

float Calculator::calculate(int num1, std::string op, int num2) {
    return this->calculate(num1, num2, op);
}

float Calculator::calculate(int num1, int num2, std::string op)
{
    if (op == "+")
        return calculator_impl->sum(num1, num2);
    else if (op == "-")
        return calculator_impl->difference(num1, num2);
    else if (op == "*" || op == "x")
        return calculator_impl->product(num1, num2);
    else if (op == "/")
        return calculator_impl->quotient(num1, num2);
    else if (op == "^" || op == "e")
        return calculator_impl->power(num1, num2);

    return 0;
}

Calculator::Calculator()
{
}
