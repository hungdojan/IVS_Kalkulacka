/**
 * @brief Výpočet směrodatné odchylky
 *
 * @authors Hung Do, David Kedra, Petr Kolařík
 *
 * @version 1.0.0
 * @date 30.04.2021
 * @copyright GNU Public License v3.0
 */
#include <iostream>
#include <vector>
#include "math_lib.h"

using namespace std;

/**
 * Program provadi vypocet smerodatne odchylky z N zadanych hodnot na standardnim vstupu
 * oddelenych bilymi znaky. Cyklycky vypocet je vykonan pomoci matematickych funkci ze 
 * tridy Math, ktere mohou byt dale sledovany nastroji k optimalizaci jejich implementaci
 */
int main(){
    //matematicke funkce
    Math m;
    //vektor k ulozeni jednotlivych hodnot potrebnych k postupnym vypoctum
    vector<double> values(0, 0);

    unsigned int quantity = 0;  //pocet nactenych hodnot
    double sum = 0;             //soucet vsech hodnot
    double middle = 0;          //prumerna hodnota

    /**
     * nacitani vstupnich hodnot do cisla num, ktere je vzdy ulozeno do vektoru hodnot
     * pole hodnot je postupne zvetsovano, cimz reaguje na predem neznamy pocet prvku
     */
    double num;
    while(cin >> num){
        //zvetsuje vektor po insertnuti kazde hodnoty
        values.insert(values.begin()+quantity, num);

        quantity++;
		//pripocteni cisla do celkove sumy
		sum = m.Sum(sum, num);
    }  
    /**
     * pokud nebylo precteno cislo, ale zaroven nejsme na konci souboru (eof)
     * doslo k nacteni neplatne hodnoty (napr. string misto cisla) a program konci
     */
    if(!cin && !cin.eof()){
        cout << "Chyba pri nacteni neplatne vstupni hodnoty!" << endl;
        return 1;
    }    

    //vypocet prumerne hodnoty ze vsech prvku
	try{
		middle = m.Divide(sum, quantity);
	}
	catch(exception e){
		cout << "Chyba: pocet vstupnich hodnot je 0!" << endl;
	}

    double innerCalc = 0;   //vnitrni mezivypocet vzorce
    double deviation = 0;   //samotna vysledna odchylka

    /**
     * iterativni vnitrni vypocet (suma hodnot^2 - quantity*middle^2)
     * mezivysledek ulozen do innerCalc a dale zpracovavan
     */
    for(int i = 0; i < quantity; i++){
        //innerCalc += pow(values[i],2);
        innerCalc = m.Sum(innerCalc, m.Pow(values[i], 2));
    }
    //innerCalc -= quantity * pow(middle, 2);
    innerCalc = m.Subtract(innerCalc, m.Multiply(quantity, m.Pow(middle, 2)));
    
    /**
     * finalni vypocet s testovanim nenuloveho jmenovatele, ktery muze nastat
     * pri malem nebo jinak specifickem mnozstvi vstupnich dat
     */
    try{
        //deviation = sqrt((1/(quantity-1)) * innerCalc);
        deviation = m.Sqrt(2, m.Multiply(m.Divide(1, m.Subtract(quantity, 1)), innerCalc));
    }
    //zachyceni vyjimky z deleni 0
    catch(exception e){
        deviation = 0;
    }

    //vypis vysledne hodnoty odchylky
    cout << deviation << endl;

    return 0;
}
/* profiling.cpp */      
