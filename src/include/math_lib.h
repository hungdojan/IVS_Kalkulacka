/**
 * @class Math main_lib.h "./include/main_lib.h"
 * @brief Matematická knihovna
 *
 * @details Tato třída obsahuje prototypy funkci matematické knihovny.
 *
 * @authors Hung Do, David Kedra, Petr Kolařík
 *
 * @version 1.0.0
 * @date 30.04.2021
 * @copyright GNU Public Licence v3.0
 */
#ifndef _MATH_LIB_H
#define _MATH_LIB_H
#include <cmath>

class Math
{
public: 
    /**
     * @brief Operace sčítání
     * @details Funkce sčítá 2 čísla typu double
     * @param[in] a První sčítanec
     * @param[in] b Druhý sčítanec
     * @return Součet parametrů a+b
     */ 
    double Sum(double a, double b);

    /**
     * @brief Operace odčítání
     * @details Funkce odčítá 2 cisla typu double
     * @param[in] a Menšenec
     * @param[in] b Menšitel 
     * @return Rozdíl parametrů a-b
     */ 
    double Subtract(double a, double b);

    /**
     * @brief Operace dělení
     * @details Funkce dělí 2 čísla typu double
     * @throw std::invalid_argument Dělení nulou
     * @param[in] a Dělenec 
     * @param[in] b Dělitel 
     * @return Podíl parametrů a/b
     */
    double Divide(double a, double b);

    /**
     * @brief Operace násobení
     * @details Funkce násobí 2 čísla typu double
     * @param[in] a První činitel
     * @param[in] b Druhý činitel
     * @return Součin parametrů a*b
     */
    double Multiply(double a, double b);

    /**
     * @brief Operace faktoriál
     * @details Funkce počítá faktoriál čísla
     * @throw std::invalid_argument Parametr a není přirozené číslo
     * @param[in] a Číslo, ze kterého chceme faktoriíl
     * @return Faktoriál zadaného čísla "a!"
     */
    double Factor(double a);

    /**
     * @brief Operace obecné odmocniny
     * @details Funkce počítá odmocninu z čísla typu double
     * @throw std::invalid_argument Odmocnění záporného čísla ze sudého indexu; 
     *  hodnota indexu je nula
     * @param[in] radicand Odmocnenec (základ odmocniny)
     * @param[in] index Kolikátá odmocnina je požadována
     * @return Index-tá odmocnina z čísla radicand
     */
    double Sqrt(double index, double radicand);

    /**
     * @brief Operace mocniny
     * @details Funkce umocňuje číslo na přirozený exponent
     * @throw std::invalid_argument Exponent není přirozené číslo
     * @param[in] base Základ mocniny
     * @param[in] exp Exponent 
     * @return Mocnina base^exp
     */
    double Pow(double base, double exp);

    /**
     * @brief Operace logaritmu 
     * @details Funkce zjistí logaritmus o základu 10 z čísla
     * @throw std::invalid_argument Čislo není kladné
     * @param[in] num Čislo ke zlogaritmování
     * @return Logaritmus z num o základu 10
     */
    double Log10(double num);
};

#endif
/* math_lib.h */
