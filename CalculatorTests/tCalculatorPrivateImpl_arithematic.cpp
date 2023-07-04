#pragma once
#include "pch.h"

TEST(tCalculatorPrivateImpl_arithematic, SumTest) {
    CalculatorPrivateImpl calc;
    EXPECT_EQ(4, calc.sum(2,2));
    EXPECT_EQ(-6, calc.sum(2, -8));
}

TEST(tCalculatorPrivateImpl_arithematic, DifferenceTest) {
    CalculatorPrivateImpl calc;
    EXPECT_EQ(4, calc.difference(6, 2));
    EXPECT_EQ(10, calc.difference(2, -8));
}

TEST(tCalculatorPrivateImpl_arithematic, ProductTest) {
    CalculatorPrivateImpl calc;
    EXPECT_EQ(4, calc.product(2, 2));
    EXPECT_EQ(-16, calc.product(2, -8));
    EXPECT_EQ(0, calc.product(0, 8));
}

TEST(tCalculatorPrivateImpl_arithematic, QuotientTest) {
    CalculatorPrivateImpl calc;
    EXPECT_EQ(1, calc.quotient(2, 2));
    EXPECT_EQ(0.25, calc.quotient(2, 8));
    EXPECT_EQ(-0.25, calc.quotient(2, -8));
    EXPECT_EQ(-0.25, calc.quotient(-2, 8));
    EXPECT_EQ(std::ceil((1.00 / 3) * 100), std::ceil(calc.quotient(1,3) * 100));

    try {
        float ans = calc.quotient(1,0);
    }
    catch (const std::exception& error) {
        std::string expectedError = "Divide by zero not allowed.";
        std::string actualError = std::string(error.what());
        EXPECT_EQ(actualError, expectedError);
    }
}

TEST(tCalculatorPrivateImpl_arithematic, PowerTest) {
    CalculatorPrivateImpl calc;
    EXPECT_EQ(4, calc.power(2, 2));
    EXPECT_EQ(625, calc.power(5, 4));
    EXPECT_EQ(0, calc.power(0, 4));
    EXPECT_EQ(8, calc.power(64, 0.5));

    try {
        float ans = calc.power(0, -2);
    }
    catch (const std::exception& error) {
        std::string expectedError = "Zero can not be raised to negative powers.";
        std::string actualError = std::string(error.what());
        EXPECT_EQ(actualError, expectedError);
    }

    try {
        float ans = calc.power(-20, 0.5);
    }
    catch (const std::exception& error) {
        std::string expectedError = "Negative numbers can not be raised to fractional powers.";
        std::string actualError = std::string(error.what());
        EXPECT_EQ(actualError, expectedError);
    }
}