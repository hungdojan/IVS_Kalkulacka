#include <gtest/gtest.h>
#include "math_lib.h"

class BasicOperation : public ::testing::Test {
    protected:
        Math m;
        double values[10] = {10, 85, 456123456, 25846185, 0, -60, -30, 0.5, 0.65, -0.8};
        const int arr_size = 10;
        virtual void SetUp() {};
        virtual void TearDown() {};
};

class AdvanceOperation : public ::testing::Test {
    protected:
        Math m;
        double values[10] = {1, 5, 456123456, 25846185, 0, -60, -30, 0.65, -0.8, 10};
        const int arr_size = 10;
        virtual void SetUp() {};
        virtual void TearDown() {};
};

// testovani funkce Sum (scitani)
TEST_F(BasicOperation, Sum) {
    EXPECT_FALSE(m.Sum(values[0], values[1]) != 95);
    EXPECT_TRUE(m.Sum(0, values[7]) == values[7]);
    EXPECT_EQ(m.Sum(values[2], values[3]), 481969641);
    EXPECT_EQ(m.Sum(values[3], -values[3]), 0);
    double result = values[1];
    for (int i = 0; i < 3; i++) {
        result = m.Sum(result, values[i+1]);
    }
    EXPECT_EQ(result, 481969736);
}

// testovani funkce Sub (scitani)
TEST_F(BasicOperation, Sub) {
    EXPECT_FALSE(m.Subtrac(values[0], values[1]) != -75);
    EXPECT_TRUE(m.Subtrac(values[7], values[9]) == 1.3);
    EXPECT_EQ(m.Subtrac(values[5], values[3]), -25846245);
    EXPECT_EQ(m.Subtrac(values[3], values[3]), 0);
    double result = values[1];
    for (int i = 0; i < arr_size-1; i++) {
        result = m.Subtrac(result, values[i+1]);
    }
    EXPECT_EQ(result, -481969626.35);
}

// testovani funkce Divide (deleni)
TEST_F(BasicOperation, Divide) {
    EXPECT_ANY_THROW(m.Divide(values[5], 0));
    EXPECT_FALSE(m.Divide(values[1], values[0]) != 8.5);
    EXPECT_TRUE(m.Divide(values[2], values[9]) == -570154320);
    EXPECT_EQ(m.Divide(values[5], values[7]), -120);
    EXPECT_EQ(m.Divide(0, values[8]), 0);
    double result = values[1];
    for (int i = 0; i < 3; i++) {
        result = m.Divide(result, values[i+1]);
    }
    EXPECT_EQ(result, 387704937600);
}

// testovani funkce Multiply (nasobeni)
TEST_F(BasicOperation, Multiply) {
    EXPECT_FALSE(m.Multiply(values[1], values[6]) != -2550);
    EXPECT_TRUE(m.Multiply(values[2], values[3]) == 11789051226615360);
    EXPECT_EQ(m.Multiply(values[7], 0), 0);
    EXPECT_EQ(m.Multiply(1, values[6]), values[6]);
    double result = values[1];
    for (int i = 0; i < 6; i++) {
        result = m.Multiply(result, values[i+1]);
    }
    EXPECT_EQ(result, 0);
}

// testovani funkce Factor (faktorial)
TEST_F(AdvanceOperation, Factor) {
    EXPECT_ANY_THROW(m.Factor(values[7]));
    EXPECT_ANY_THROW(m.Factor(values[6]));
    EXPECT_FALSE(m.Factor(values[9]) != 3628800);
    EXPECT_TRUE(m.Factor(values[1]) == 120);
    EXPECT_EQ(m.Factor(values[4]), 1);
    EXPECT_EQ(m.Factor(values[0]), 1);
}