#ifndef _MATH_LIB_H
#define _MATH_LIB_H
#include <cmath>

class Math
{
public: 
    /**
     * @brief Funkce scita 2 cisla typu double
     * @param a prvni scitanec
     * @param b druhy scitanec
     * @return soucet parametru a+b
     */ 
    double Sum(double a, double b);

    /**
     * @brief Funkce odcita 2 cisla typu double
     * @param a mensenec
     * @param b mensitel 
     * @return rozdil parametru a-b
     */ 
    double Subtract(double a, double b);

    /**
     * @brief Funkce deli 2 cisla typu double
     * @param a delenec 
     * @param b delitel 
     * @return podil parametru a/b
     */
    double Divide(double a, double b);

    /**
     * @brief Funkce nasobi 2 cisla typu double
     * @param a prvni cinitel
     * @param b druhy cinitel
     * @return soucin parametru a*b
     */
    double Multiply(double a, double b);

    /**
     * @brief Funkce pocita faktorial cisla
     * @param a cislo, ze ktereho chceme faktorial
     * @return faktorial zadaneho cisla "a!"
     */
    int Factor(int a);

    /**
     * @brief Funkce pocita druhou odmocninu z cisla typu double
     * @param radicand odmocnenec (zaklad odmocniny)
     * @param index kolikata odmocnina je pozadovana
     * @return index-ta odmocnina z cisla radicand
     */
    double Sqrt(double index, double radicand);

    /**
     * @brief Funkce umocnuje cislo
     * @param base zaklad mocniny
     * @param exp exponent 
     * @return mocnina base^exp
     */
    double Pow(double base, double exp);

    /**
     * @brief Funkce zjisti logaritmus o zakladu 10 z cisla
     * @param num cislo k zlogaritmovani
     * @return logaritmus z num o zakladu 10
     */
    double Log10(double num);
};

#endif
