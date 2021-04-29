/**
 * @class MainWindow mainwindow.h "./gui/mainwindow.h"
 * @brief Hlavní okno aplikace Kalkulacka
 *
 * @details Tato třída obsahuje všechny operace a proměnné potřebné k realizaci 
 *  kalkulačky s grafickým uživatelským prostředím. 
 *
 * @authors Hung Do, David Kedra, Petr Kolařík
 *
 * @version 1.0.0
 * @date 30.04.2021
 * @copyright GNU Public License v3.0
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSignalMapper>
#include <QKeyEvent>
#include "math_lib.h"
#include "helpwindow.h"

#define MAX_DIGITS 13 /**< maximalni pocet cifer na displeji */

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    /// Konstruktor třídy MainWindow
    MainWindow(QWidget *parent = nullptr);
    /// Destruktor třídy MainWindow
    ~MainWindow();

    /**
     * @brief Výčet tlačítek v aplikaci
     */
    enum Button {
        ZERO=0, ///< Číslo 0
        ONE,    ///< Číslo 1 
        TWO,    ///< Číslo 2
        THREE,  ///< Číslo 3
        FOUR,   ///< Číslo 4
        FIVE,   ///< Číslo 5
        SIX,    ///< Číslo 6
        SEVEN,  ///< Číslo 7
        EIGHT,  ///< Číslo 8
        NINE,   ///< Číslo 9
        POINT,  ///< Desetinná čárka
        INV,    ///< Inverze čísla
        ADD,    ///< Sčítání
        SUB,    ///< Odčítání
        MUL,    ///< Násobení
        DIV,    ///< Dělení
        LOG,    ///< Logaritmus
        POW,    ///< Mocnina
        SQRT,   ///< Obecná odmocnina
        FACT,   ///< Faktoriál
        EQL,    ///< Rovná se
        HELP,   ///< Nápověda
        DEL,    ///< Mazání znaku
        CLR,    ///< Vynulování
        MEMOUT, ///< Výpis paměti
        MEMIN   ///< Zápis paměti
    };

    /**
     * @brief Výčet možných matematických operací v knihovně
     */
    enum Operation {
        ADD_O,  ///< Operace sčítání 
        SUB_O,  ///< Operace odčítání
        MUL_O,  ///< Operace násobení 
        DIV_O,  ///< Operace dělení
        LOG_O,  ///< Operace logaritmus
        POW_O,  ///< Operace mocnina
        SQRT_O, ///< Operace obecná odmocnina
        FACT_O, ///< Operace faktoriál
        NONE_O  ///< Žádná operace
    };

private:
    Ui::MainWindow *ui;             /**< Seznam objektů v okně MainWindow   */
    HelpWindow helpWindow;			/**< Okno, které vypisuje nápovědu		*/
    Math m;							/**< Matematickí knihovna               */

    QString currText;				/**< Obsah textu na displeji            */
    double result;					/**< Průběžný výsledek                  */
    double adv_result;              /**< 1. operand advance oper. pow,sqrt  */
    double memory;                  /**< Paměť pro uložení currText (op. M+)*/
    Operation operation;			/**< Znaménko operace                   */
    Operation adv_operation;        /**< Advance operace, k zachovaní basic */
    QSignalMapper *signalMapper;	/**< Objekt přidělovače akcí            */
    bool toClear;                   /**< Smazat před novým operandem        */

    /**
     * @brief Mapování akcí
     * @details Namapuje signal tlačítek na slot akcí podle ID tlačítka
     */
    void MapSignal();

    /**
     * @brief Přidání znaku na displej
     * @details Reaguje na tlačítka 0-9, znaku desetinné čárky a invertující tlačítko; 
     * 	podle hodnoty ID tlačítka změní řetězec MainWindow::currText. 
     * 	Ošetří hraniční stavy (např. pokud obsah currText=="0")
     * @param[in] id ID tlačítka (podle enum Button)
     */
    void PrintNumber(const int id);

    /**
     * @brief Resetování hodnot, nastavení a operací
     * @details Nastaví hodnoty proměnných do výchozího nastaveni 
     *  po chýbě nebo po vyčištění kalkulačky (např. tlačítkem CLEAR);
     *  ponechává hodnotu paměti
     */
    void ResetVals();

    /**
     * @brief Základní matematické operace
     * @details	Provede základní operace nad čísly (+,-,*,/) a pokryje nedefinované stavy
     * @param[in] id ID tlačítka (podle enum Button)
     */
    void BasicOperation(const int id);

    /**
     * @brief Rozšířené matematické operace
     * @details	Provede rozšířené matematické operace nad čísly (log, pow, sqrt, fact) a
     * 	pokryje nedefinované stavy
     * @param[in] id ID tlačítka (podle enum Button)
     */
    void AdvanceOperation(const int id);

    /**
     * @brief Výpočet výsledku
     * @details Spočítá výsledek a uloží ho do proměnné MainWindow::result; 
     * 	pokryje nedefinované stavy
     */
    void OutputResult();

    /**
     * @brief Výpis nápovědy
     * @details Objeví se nové okno s nápovědou pro uživatele
     */
    void DisplayHelp();

    /**
     * @brief Mazani znaku
     * @details Pokud není obsah MainWindow::currText prázdný, 
     *  odstraní poslední znak z 
     */
    void DeleteDigit();

    /**
     * @brief Vynuluje kalkulačku
     * @details Vynuluje všechny výsledky i mezivýsledky; ponechává hodnotu paměti
     */
    void ClearData();

    /**
     * @brief Operace s pamětí
     * @details Ukládá, nebo tiskne uloženou hodnotu v paměti. 
     *  Hodnota se uchovává do dalšího přepisu nebo do ukončení aplikace. 
     *  Výchozí hodnota paměti po zapnutí aplikace je 0.0
     * @param[in] id ID tlačítka (podle enum Button)
     */
    void MemoryOperation(const int id);

    /**
     * @brief Klavesove udalosti
     * @details Přidání klávesových událostí, které odpovídají tlačítkám v aplikaci 
     *  Namapovaná tlačítka: čísla, desetinná tečka, základní mat. operace, mazání znaků a výpočet výsledku
     * @param[in] e Ukazatel na QKeyEvent
     */
    void keyPressEvent(QKeyEvent *e) override;

private slots:
    /**
     * @brief Dělič akcí
     * @details Na základě ID tlačítka zavolá příslušnou funkci k provedení akce.
     *  Nakonec aktualizuje obsah displeje
     * @param[in] id ID tlačítka (podle enum Button)
     */
    void Action(const int id);

};
#endif // MAINWINDOW_H
