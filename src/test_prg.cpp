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
        double values[9] = {1, 5, 456123456, 25846185, 0, -60, -30, 0.65, -0.8};
        const int arr_size = 9;
        virtual void SetUp() {};
        virtual void TearDown() {};
};

// testovani funkce Sum (scitani)
TEST_F(BasicOperation, Sum) {
    EXPECT_FALSE(m.Sum(values[0], values[1]) != 95);
    EXPECT_TRUE(m.Sum(0, values[7]) == 0.5);
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
    EXPECT_ANY_THROW(m.Divide(10, 0));
    EXPECT_FALSE(m.Divide(85, 10) != 8.5);
    EXPECT_TRUE(m.Divide(456123456, -0.8) == -570154320);
    EXPECT_EQ(m.Divide(-60, 0.5), -120);
    EXPECT_EQ(m.Divide(0, 25846185), 0);
}

// testovani funkce Multiply (nasobeni)
TEST_F(BasicOperation, Multiply) {
    EXPECT_FALSE(m.Multiply(85, -30) != -2550);
    EXPECT_TRUE(m.Multiply(456123456, 25846185) == 11789051226615360);
    EXPECT_EQ(m.Multiply(-60, 0), 0);
    EXPECT_EQ(m.Multiply(1, 25846185), 25846185);
}

// testovani funkce Divide (deleni)
TEST_F(AdvanceOperation, Factor) {
    EXPECT_ANY_THROW(m.Factor(0.65));
    EXPECT_ANY_THROW(m.Factor(-30));
    EXPECT_FALSE(m.Factor(10) != 3628800);
    EXPECT_TRUE(m.Factor(5) == 120);
    EXPECT_EQ(m.Factor(5), 120);
    EXPECT_EQ(m.Divide(0, 25846185), 0);
}