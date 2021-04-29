/**
 * @class BasicOperation AdvanceOperation
 * @brief Test matematické knihovny
 *
 * @details Tento soubor testuje vlastně napsanou matematickou knihovnu math_lib.
 *
 * @authors Hung Do, David Kedra, Petr Kolařík
 *
 * @version 1.0.0
 * @date 30.04.2021
 */
#include <gtest/gtest.h>
#include "math_lib.h"

/**
 * @brief Test základních operací
 */ 
class BasicOperation : public ::testing::Test {
    protected:
        /// Instance s matematickými operacemi
        Math m;
        /// Pole náhodně vybraných hodnot
        double values[10] = {10, 85, 456123456, 25846185, 0, -60, -30, 0.5, 0.65, -0.8};
        /// Velikost pole
        const int arr_size = 10;
        /**
         * @brief Konstruktor testu
         */
        virtual void SetUp() {};
        /**
         * @brief Destruktor testu
         */
        virtual void TearDown() {};
};

/**
 * @brief Test pokročilých operací
 */ 
class AdvanceOperation : public ::testing::Test {
    protected:
        /// Instance s matematickými operacemi
        Math m;
        /// Pole náhodně vybraných hodnot
        double values[10] = {1, 5, 456123456, 25846185, 0, -60, -30, 0.65, -0.8, 10};
        /// Velikost pole
        const int arr_size = 10;
        /**
         * @brief Konstruktor testu
         */
        virtual void SetUp() {};
        /**
         * @brief Destruktor testu
         */
        virtual void TearDown() {};
};

/**
 * @brief Testování funkce Sum (sčítání)
 */
TEST_F(BasicOperation, Sum) {
    EXPECT_FALSE(m.Sum(values[0], values[1]) != 95);
    EXPECT_TRUE(m.Sum(0, values[7]) == values[7]);
    EXPECT_EQ(m.Sum(values[2], values[3]), 481969641);
    EXPECT_EQ(m.Sum(values[3], -values[3]), 0);
    EXPECT_FLOAT_EQ(m.Sum(0.3, values[8]), 0.95);
    EXPECT_FLOAT_EQ(m.Sum(values[9], values[8]), -0.15);
    double result = values[0];
    for (int i = 0; i < 3; i++) {
        result = m.Sum(result, values[i+1]);
    }
    EXPECT_EQ(result, 481969736);

	EXPECT_EQ(m.Sum(5, 10), m.Sum(10, 5));
	EXPECT_EQ(m.Sum(m.Sum(10, 20), 30),
			  m.Sum(10, m.Sum(20, 30)));
}

/** 
 * @brief Testování funkce Subtract (odčítání)
 */
TEST_F(BasicOperation, Subtract) {
    EXPECT_FALSE(m.Subtract(values[0], values[1]) != -75);
    EXPECT_FLOAT_EQ(m.Subtract(values[7], values[9]), 1.3);
    EXPECT_EQ(m.Subtract(values[5], values[3]), -25846245);
    EXPECT_EQ(m.Subtract(values[3], values[3]), 0);
    EXPECT_FLOAT_EQ(m.Subtract(0.3, values[8]), -0.35);
    EXPECT_FLOAT_EQ(m.Subtract(values[9], 0.2), -1);
	EXPECT_FLOAT_EQ(m.Subtract(0.5, 0.5), 0);
	EXPECT_FLOAT_EQ(m.Subtract(-1.3, -1.3), 0);
    double result = values[0];
    for (int i = 0; i < arr_size-1; i++) {
        result = m.Subtract(result, values[i+1]);
    }
    EXPECT_FLOAT_EQ(result, -481969626.35);

	EXPECT_NE(m.Subtract(30, 40), m.Subtract(40, 30));
	EXPECT_NE(m.Subtract(m.Subtract(10, 20), 30),
			  m.Subtract(10, m.Subtract(20, 30)));
}

/** 
 * @brief Testování funkce Divide (dělení)
 */
TEST_F(BasicOperation, Divide) {
    EXPECT_ANY_THROW(m.Divide(values[5], 0));// test spadne, pokud se deli nulou
    EXPECT_FALSE(m.Divide(values[1], values[0]) != 8.5);
    EXPECT_TRUE(m.Divide(values[2], values[9]) == -570154320);
    EXPECT_EQ(m.Divide(values[5], values[7]), -120);
    EXPECT_FLOAT_EQ(m.Divide(values[8], values[7]), 1.3);
    EXPECT_EQ(m.Divide(0, values[8]), 0);
    EXPECT_FLOAT_EQ(m.Divide(27.43, -values[8]), -42.2);
    EXPECT_FLOAT_EQ(m.Divide(values[8], 9.5), 0.06842105263157894736842105263158);
	EXPECT_FLOAT_EQ(m.Divide(-1, 8), -0.125);
	double res = 64;
	for (int i = 0; i < 8; i++)
		EXPECT_NO_THROW(res = m.Divide(res, 2));
	EXPECT_FLOAT_EQ(res, 0.25);
}

/** 
 * @brief Testování funkce Multiply (násobení)
 */
TEST_F(BasicOperation, Multiply) {
    EXPECT_FALSE(m.Multiply(values[1], values[6]) != -2550);
    EXPECT_TRUE(m.Multiply(values[2], values[3]) == 11789051226615360);
    EXPECT_EQ(m.Multiply(values[7], 0), 0);
    EXPECT_EQ(m.Multiply(1, values[6]), values[6]);
    EXPECT_FLOAT_EQ(m.Multiply(0.23, values[9]), -0.184);
    double result = values[0];
    for (int i = 0; i < 6; i++) {
        result = m.Multiply(result, values[i+1]);
    }
    EXPECT_EQ(result, 0);

	EXPECT_EQ(m.Multiply(5, 10), m.Multiply(10, 5));
	EXPECT_EQ(m.Multiply(m.Multiply(10, 20), 30),
			  m.Multiply(10, m.Multiply(20, 30)));
}

/** 
 * @brief Testování funkce Factor (faktoriál)
 */
TEST_F(AdvanceOperation, Factor) {
    EXPECT_ANY_THROW(m.Factor(values[7]));// test spadne, pokud je faktorial desetinne cislo
    EXPECT_ANY_THROW(m.Factor(values[6]));// test spadne, pokud je faktorial zaporne cislo
    EXPECT_FALSE(m.Factor(values[9]) != 3628800);
    EXPECT_TRUE(m.Factor(values[1]) == 120);
    EXPECT_EQ(m.Factor(values[4]), 1);
    EXPECT_EQ(m.Factor(values[0]), 1);
}

/** 
 * @brief Testování funkce Pow (umocnění)
 */
TEST_F(AdvanceOperation, Pow) {
    EXPECT_ANY_THROW(m.Pow(values[1], values[7]));// test spadne, pokud je exponent desetinne cislo
    EXPECT_ANY_THROW(m.Pow(values[1], values[6]));// test spadne, pokud je exponent zaporne cislo
    EXPECT_TRUE(m.Pow(values[9], values[1]) == 100000);
    EXPECT_FLOAT_EQ(m.Pow(0.6, values[1]), 0.07776);
    EXPECT_EQ(m.Pow(values[1], 1), values[1]);
    EXPECT_EQ(m.Pow(values[1], 0), 1);
    double result = values[0];
    for (int i = 0; i < 3; i++) {
        result = m.Pow(result, values[i+1]);
    }
    EXPECT_FLOAT_EQ(result, 1);
}

/** 
 * @brief Testování funkce Sqrt (odmocnění)
 */
TEST_F(AdvanceOperation, Sqrt) {
    EXPECT_ANY_THROW(m.Sqrt(2, values[6]));// test spadne, pokud se odmocnuje zaporne cislo
    EXPECT_ANY_THROW(m.Sqrt(0, values[1]));// test spadne, pokud je odmocnitel nulovy
    EXPECT_NE(m.Sqrt(3, -27), 9);
    EXPECT_FLOAT_EQ(m.Sqrt(-2, values[2]), 0.00004682295);
    EXPECT_FLOAT_EQ(m.Sqrt(-0.6, 0.65), 2.050270072);
    EXPECT_EQ(m.Sqrt(1, values[1]), values[1]);
	EXPECT_FLOAT_EQ(m.Sqrt(6, 15625), 5);
    double result = values[0];
    for (int i = 0; i < 2; i++) {
        result = m.Sqrt(result, values[i+1]);
    }
    EXPECT_FLOAT_EQ(result, 53.9282691);
}

/** 
 * @brief Testování funkce Log10 (logaritmus o základu 10)
 */
TEST_F(AdvanceOperation, Log10) {
    EXPECT_ANY_THROW(m.Log10(0));// test spadne, pokud logaritmujeme nulu
    EXPECT_ANY_THROW(m.Log10(-5));// test spadne, pokud logaritmujeme zapornym cislem
    EXPECT_FLOAT_EQ(m.Log10(50), 1.698970004);
    EXPECT_FLOAT_EQ(m.Log10(values[2]), 8.659082406);
    EXPECT_FLOAT_EQ(m.Log10(35.4), 1.549003262);
    EXPECT_EQ(m.Log10(1), 0);
	EXPECT_FLOAT_EQ(m.Log10(0.01), -2.0);
    EXPECT_FLOAT_EQ(m.Log10(69), 1.838849091);
    double result = values[0];
    for (int i = 0; i < 2; i++) {
        result = m.Log10(values[0]);
        values[0] = values[i+1];
    }
    EXPECT_FLOAT_EQ(result, 0.6989700043);
}

/** 
 * @brief Testování Pythogorovy věty
 */
TEST(CombinedOperation, Pythogoras) {
	Math m;
	double a=3, b=4;
	double res = 0;

	EXPECT_NO_THROW(res = m.Sqrt(2, m.Sum(m.Pow(a, 2), m.Pow(b, 2))));
	EXPECT_FLOAT_EQ(res, 5);

	a=5, b=12;
	EXPECT_NO_THROW(res = m.Sqrt(2, m.Sum(m.Pow(a, 2), m.Pow(b, 2))));
	EXPECT_FLOAT_EQ(res, 13);
}

/**
 * @brief Testování výpočtu obsahu kruhu
 */
TEST(CombinedOperation, CircleArea) {
	Math m;
	double radius = 12;
	double pi = 3.14;
	EXPECT_FLOAT_EQ(m.Multiply(pi, m.Pow(radius, 2)), 452.16);
}
/* test_lib.cpp */
