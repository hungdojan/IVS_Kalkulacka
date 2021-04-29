/**
 * @brief Deklarace funkcí matematické knihovny
 *
 * @authors Hung Do, David Kedra, Petr Kolařík
 *
 * @version 1.0.0
 * @date 30.04.2021
 * @copyright GNU Public License v3.0
 */
#include <iostream>
#include "math_lib.h"

double Math::Sum(double a, double b){
    return a+b;
}
double Math::Subtract(double a, double b){ 
    return a-b;
}
double Math::Divide(double a, double b){
    if(b == 0)   
        throw std::invalid_argument("Chyba: Nelze delit 0!");
    return a/b;
}
double Math::Multiply(double a, double b){
    return a*b;
}

double Math::Factor(double a){
    //Factor pocita pouze s celymi cisly, ale testuje vstup double
    if(floor(a) != a)
        throw std::invalid_argument("Chyba: Nelze vypocitat faktorial desetinneho cisla!");

    //vysledek, kam se postupne pricita faktorial
    double result = 1;
    //snizujici se cislo, ze ktereho pocitame faktorial
    double fact = a;

    //faktorial ze zaporneho cisla nelze, vyhodi vyjimku
    if(fact < 0)
        throw std::invalid_argument("Chyba: Neplatna hodnota faktorialu!");
    //0! = 1
    else if (fact == 0)
        return 1;

    //vysledny faktorial result se nasobi, dokud neni factor 1
    while(fact != 1){
        result *= fact;
        fact--;
    }
    return result;
}

double Math::Sqrt(double index, double radicand){
    //odmocninu lze vykonat pouze z kladneho cisla
    if((radicand < 0) && ((int)index % 2 == 0)){
		throw std::invalid_argument("Chyba: Nelze vypocitat odmocninu ze zaporneho cisla!");
    }
	else if(index == 0)
        throw std::invalid_argument("Chyba: Nulta odmocnina neni definovana!");   

	//obecna odmocnina implementovana jako mocnina na zlomek
	if(radicand >= 0)
		return pow(radicand, 1.0/index);
	//odmocnina ze zaporneho cisla, je rovna -1 * odm. z kladneho
	else
		return -1 *pow(-1*radicand, 1.0/index);
}

double Math::Pow(double base, double exp){
    //overeni, zda je exponent prirozene cislo
    if(floor(exp) != exp)
        throw std::invalid_argument("Chyba: Kalkulacka nepocita s desetinnym exponentem!");
    else if(exp < 0)
        throw std::invalid_argument("Chyba: Kalkulacka nepocita se zapornym exponentem!");
    
    return pow(base, exp);
}

double Math::Log10(double num){
    //logaritmus <= 0 neni definovan
    if(num <= 0)
        throw std::invalid_argument("Chyba: Logaritmus 0 neni definovan!");
    return log10(num);
}
/* math_lib.cpp */
