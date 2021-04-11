#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSignalMapper>
#include <QKeyEvent>
#include "math_lib.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Vycet tlacitek v aplikaci
 */
enum Button {
    ZERO=0, ONE, TWO, THREE, FOUR,
    FIVE, SIX, SEVEN, EIGHT, NINE, POINT, 
    ADD, SUB, MUL, DIV,
    LOG, POW, SQRT, FACT,
    EQL, HELP, DEL,
    // additional features
    BRACKET_L, BRACKET_R
};

/**
 * @brief Vycet moznych matematickych operaci v knihovne
 */
enum Operation {
    ADD_O, SUB_O, MUL_O, DIV_O,
    LOG_O, POW_O, SQRT_O, FACT_O,
    NONE_O
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Operation operation;			/**< Znamenko operace	*/
    double result;					/**< Prubezny vysledek 	*/
    QString currText;				/**< Obsah lcd displeje */
    QSignalMapper *signalMapper;	/**< Pridelovac akci 	*/
    Math m;							/**< Mat. knihovna		*/

    /**
     * @brief Mapovani akci
     * Namapuje signal tlacitek na slot akci
     */
    void MapSignal();

    /**
     * @brief Pridani znaku na displej
     * 	Reaguje na tlacitka 0-9 a point
     * 	Zapise hodnotu odpovidajici id do currentText
     * 	Osetri hranicni argumenty (napr. pokud obsah currText=="0")
     * @param id ID tlacitka (podle enum Button)
     */
    void PrintNumber(int id);

    /**
     * @brief Zakladni mat. operace
     * 	Provede zakladni operace nad cisly (+,-,*,/)
     * 	Pohlida nedefinovane hodnoty
     * @param id ID tlacitka (podle enum Button)
     */
    void BasicOperation(int id);

    /**
     * @brief Rozsirene mat. operace
     * 	Provede rozsirene matematicke operace nad cisly (log, pow, sqrt, fact)
     * 	Pohlida nedefinovane hodnoty
     * @param id ID tlacitka (podle enum Button)
     */
    void AdvanceOperation(int id);

    /**
     * @brief Vypocet vysledku
     * 	Spocita vysledek a ulozi ho do promenne result
     * 	Pohlida nedefinovane hodnoty
     */
    void OutputResult();

    /**
     * @brief Vypis napovedy
     * 	Objevi se nove okno s napovedou pro uzivatele
     */
    void DisplayHelp();

    /**
     * @brief Mazani znaku
     * 	Smaze posledni znak z retezce
     */
    void DeleteDigit();

    /**
     * @brief Operace se zavorkami
     * 	TODO: this feature can be removed in the final version
     * @param id ID tlacitka (podle enum Button)
     */
    void BracketOperation(int id);

    /**
     * @brief Klavesove udalosti
     * 	Pridani klavesovych udalosti
     * @param e Ukazatel na QKeyEvent
     */
    void keyPressEvent(QKeyEvent *e) override;

private slots:
    /**
     * @brief Akce
     * 	Provede akci na zaklade ID tlacitka
     * @param id ID tlacitka (podle enum Button)
     */
    void Action(int id);

};
#endif // MAINWINDOW_H
