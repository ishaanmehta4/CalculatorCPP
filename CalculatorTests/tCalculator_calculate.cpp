#pragma once
#include "pch.h"

TEST(tCalculator_calculate, SumTest) {
    Calculator calc;
    EXPECT_EQ(4, calc.calculate("2+2"));
}

TEST(tCalculator_calculate, DifferenceTest) {
    Calculator calc;
    EXPECT_EQ(8, calc.calculate("10-2"));
    EXPECT_EQ(0, calc.calculate("10-10"));
    EXPECT_EQ(-2, calc.calculate("10-12"));
}

TEST(tCalculator_calculate, ProductTest) {
    Calculator calc;
    EXPECT_EQ(12, calc.calculate("4*3"));
    EXPECT_EQ(21, calc.calculate("3x7"));
    EXPECT_EQ(0, calc.calculate("3x0"));
}

TEST(tCalculator_calculate, QuotientTest) {
    Calculator calc;
    EXPECT_EQ(1, calc.calculate("4/4"));
    EXPECT_EQ(0.5, calc.calculate("2/4"));
    EXPECT_EQ(std::ceil((1.00 / 3) * 100), std::ceil(calc.calculate("1/3") * 100));

    try {
        float ans = calc.calculate("1/0");
    }
    catch (const std::exception& error) {
        std::string expectedError = "Divide by zero not allowed.";
        std::string actualError = std::string(error.what());
        EXPECT_EQ(actualError, expectedError);
    }
}

TEST(tCalculator_calculate, PowerTest) {
    Calculator calc;
    EXPECT_EQ(16, calc.calculate("4^2"));
    EXPECT_EQ(625, calc.calculate("5e4"));
    EXPECT_EQ(0, calc.calculate("0e4"));
}