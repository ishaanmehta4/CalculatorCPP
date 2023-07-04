#include "Calculator/Calculator.hpp"

int main()
{
    std::string input;

    Calculator calculator;

    while (true)
    {
        std::cout << ">> ";
        std::cin >> input;
        try
        {
            std::cout << input << " = " << calculator.calculate(input) << std::endl;
        }
        catch (const std::exception &error)
        {
            std::cout << "ERROR: " + std::string(error.what()) << std::endl;
        }
        std::cout << "______________________________________\n";
    }

    return 0;
}