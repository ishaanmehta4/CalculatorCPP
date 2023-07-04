#pragma once
#include "pch.h"

TEST(tCalculator_misc, testUnknownOperator) {
    Calculator calc;

    try {
        float ans = calc.calculate("3]5");
    }
    catch (const std::exception& error) {
        std::string expectedError = "Invalid operation: ]";
        std::string actualError = std::string(error.what());
        EXPECT_EQ(actualError, expectedError);
    }
}

TEST(tCalculator_misc, testMissingOperands) {
    Calculator calc;

    try {
        float ans = calc.calculate("+1");
    }
    catch (const std::exception& error) {
        std::string expectedError = "First operand not found in the given input.";
        std::string actualError = std::string(error.what());
        EXPECT_EQ(actualError, expectedError);
    }

    try {
        float ans = calc.calculate("1+");
    }
    catch (const std::exception& error) {
        std::string expectedError = "Second operand not found in the given input.";
        std::string actualError = std::string(error.what());
        EXPECT_EQ(actualError, expectedError);
    }
}