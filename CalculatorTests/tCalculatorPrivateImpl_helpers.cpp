#pragma once
#include "pch.h"

TEST(tCalculatorPrivateImpl_helpers, IsDigitTest) {
    CalculatorPrivateImpl calc;
    EXPECT_EQ(false, calc.isDigit('q'));
    EXPECT_EQ(false, calc.isDigit('Q'));
    EXPECT_EQ(false, calc.isDigit('['));
    EXPECT_EQ(true, calc.isDigit('0'));
    EXPECT_EQ(true, calc.isDigit('1'));
    EXPECT_EQ(true, calc.isDigit('9'));
}

TEST(tCalculatorPrivateImpl_helpers, validateAllArgumentsTest) {
    CalculatorPrivateImpl calc;
    
    try {
        calc.validateAllArguments("", "2", "+");
    }
    catch (const std::exception& error) {
        std::string expectedError = "First operand not found in the given input.";
        std::string actualError = std::string(error.what());
        EXPECT_EQ(actualError, expectedError);
    }

    try {
        calc.validateAllArguments("2", "", "+");
    }
    catch (const std::exception& error) {
        std::string expectedError = "Second operand not found in the given input.";
        std::string actualError = std::string(error.what());
        EXPECT_EQ(actualError, expectedError);
    }

    try {
        calc.validateAllArguments("2", "2", "");
    }
    catch (const std::exception& error) {
        std::string expectedError = "Operator not found in the given input.";
        std::string actualError = std::string(error.what());
        EXPECT_EQ(actualError, expectedError);
    }
}

TEST(tCalculatorPrivateImpl_helpers, isValidOperationTest) {
    CalculatorPrivateImpl calc;
    EXPECT_EQ(true, calc.isValidOperation('+'));
    EXPECT_EQ(true, calc.isValidOperation('*'));
    EXPECT_EQ(true, calc.isValidOperation('e'));
    EXPECT_EQ(true, calc.isValidOperation('x'));
    
    EXPECT_EQ(false, calc.isValidOperation('['));
    EXPECT_EQ(false, calc.isValidOperation('c'));
}
