#include <gtest/gtest.h>
#include "math_lib.h"

class BasicOperation : public ::testing::Test {
    protected:
        Math m;
        virtual void SetUp() {
            double values[] = { 10, 85, 456123456, 25846185, 0, -60, -30, 0.5, 0.65, -0.8};
        }
};

// testovani funkce Sum (scitani)
TEST_F(BasicOperation, Sum) {
    EXPECT_FALSE(m.Sum(10, 85) != 95);
    EXPECT_TRUE(m.Sum(0, -0.8) == -0.8);
    EXPECT_TRUE(m.Sum(456123456, 25846185) == 481969641);
    EXPECT_EQ(m.Sum(25846185, -0.8), 25846184.2);
    
}

// testovani funkce Sub (scitani)
TEST_F(BasicOperation, Sub) {
    EXPECT_FALSE(m.Subtrac(10, 85) != -75);
    EXPECT_TRUE(m.Subtrac(0.5, -0.8) == 1.3);
    EXPECT_EQ(m.Subtrac(-60, 25846185), 25846125);
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