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
    EXPECT_TRUE(m.Sum(0.5, -0.8) == -0.3);
    EXPECT_TRUE(m.Sum(456123456, 25846185) == 481969641);
    EXPECT_EQ(m.Sum(25846185, -0.8), 25846184.2);
    
}

// testovani funkce Sub (scitani)
TEST_F(BasicOperation, Sub) {
    EXPECT_FALSE(m.Subtrac(10, 85) != -75);
    EXPECT_TRUE(m.Subtrac(0.5, -0.8) == 1.3);
    EXPECT_EQ(m.Subtrac(-60, 25846185), 25846125);
}