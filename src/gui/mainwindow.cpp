#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <QDebug>	// this library can be removed in the final version

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // inicializace vychozich hodnot
    result = 0.0;
    currText = "0";
    operation = Operation::NONE_O;
    signalMapper = new QSignalMapper(this);

    // nastaveni signalu pro numsAndBasicOpsTable
    for (int i = 0; i < ui->numsAndBasicOpsTable->count(); i++) {
        connect(ui->numsAndBasicOpsTable->itemAt(i)->widget(), SIGNAL(clicked()), signalMapper, SLOT(map()));
    }
    // nastaveni signalu pro advanceOperationTable
    for (int i = 0; i < ui->advancedOperationsTable->count(); i++) {
        connect(ui->advancedOperationsTable->itemAt(i)->widget(), SIGNAL(clicked()), signalMapper, SLOT(map()));
    }
    // namapovani signalu
    MapSignal();
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(Action(int)));
}

void MainWindow::MapSignal() {
    // cisla a tecka
    signalMapper -> setMapping(ui->zeroButton  		 , Button::ZERO );
    signalMapper -> setMapping(ui->oneButton   		 , Button::ONE  );
    signalMapper -> setMapping(ui->twoButton   		 , Button::TWO );
    signalMapper -> setMapping(ui->threeButton 		 , Button::THREE);
    signalMapper -> setMapping(ui->fourButton  		 , Button::FOUR );
    signalMapper -> setMapping(ui->fiveButton  		 , Button::FIVE );
    signalMapper -> setMapping(ui->sixButton   		 , Button::SIX  );
    signalMapper -> setMapping(ui->sevenButton 		 , Button::SEVEN);
    signalMapper -> setMapping(ui->eightButton 		 , Button::EIGHT);
    signalMapper -> setMapping(ui->nineButton  		 , Button::NINE );
    signalMapper -> setMapping(ui->decimalPointButton, Button::POINT);

    // zakladni mat. operace
    signalMapper -> setMapping(ui->addButton   		 , Button::ADD  );
    signalMapper -> setMapping(ui->subButton   		 , Button::SUB );
    signalMapper -> setMapping(ui->mulButton 		 , Button::MUL  );
    signalMapper -> setMapping(ui->divideButton		 , Button::DIV  );

    // rozsirene mat. operace
    signalMapper -> setMapping(ui->logButton   		 , Button::LOG  );
    signalMapper -> setMapping(ui->powerButton 		 , Button::POW  );
    signalMapper -> setMapping(ui->rootButton 		 , Button::SQRT );
    signalMapper -> setMapping(ui->factorButton		 , Button::FACT );

    // ostatni
    signalMapper -> setMapping(ui->equalSignButton 	 , Button::EQL  );
    signalMapper -> setMapping(ui->helpButton  		 , Button::HELP );
    signalMapper -> setMapping(ui->deleteButton		 , Button::DEL  );

    // FIXME: additional features that can be removed in the final version
    signalMapper -> setMapping(ui->bracketLeftButton , Button::BRACKET_L);
    signalMapper -> setMapping(ui->bracketRightButton, Button::BRACKET_R);
}

void MainWindow::Action(int id) {
    switch(id) {
        case Button::ZERO:
        case Button::ONE:
        case Button::TWO:
        case Button::THREE:
        case Button::FOUR:
        case Button::FIVE:
        case Button::SIX:
        case Button::SEVEN:
        case Button::EIGHT:
        case Button::NINE:
        case Button::POINT:
            PrintNumber(id);
            break;
        case Button::ADD:
        case Button::SUB:
        case Button::MUL:
        case Button::DIV:
            BasicOperation(id);
            break;
        case Button::LOG:
        case Button::POW:
        case Button::SQRT:
        case Button::FACT:
            AdvanceOperation(id);
            break;
        case Button::EQL:
            OutputResult();
            break;
        case Button::HELP:
            DisplayHelp();
            break;
        case Button::DEL:
            DeleteDigit();
            break;
        case Button::BRACKET_L:
        case Button::BRACKET_R:
            BracketOperation(id);	//< this feature can be removed in the final version
            break;
        default:
            qDebug() << "Nedefinovana akce!\n";
            break;
    }

    // displej update
    ui->textLabel->display(currText);
}

void MainWindow::PrintNumber(int id) {
    // TODO:
    qDebug() << "Tlacitko: " << id;
}

void MainWindow::BasicOperation(int id) {
    // TODO:
    qDebug() << "Tlacitko: " << id;
}

void MainWindow::AdvanceOperation(int id) {
    // TODO:
    qDebug() << "Tlacitko: " << id;
}

void MainWindow::OutputResult() {
    // TODO:
    qDebug() << "Tlacitko: " << Button::EQL;
}

void MainWindow::DisplayHelp() {
    // TODO:
    qDebug() << "Tlacitko: " << Button::HELP;
}

void MainWindow::DeleteDigit() {
    // TODO:
    qDebug() << "Tlacitko: " << Button::DEL;
}

void MainWindow::BracketOperation(int id) {
    // TODO: this feature can be removed in the final version
    qDebug() << "Tlacitko: " << id;
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
    // TODO:
}

MainWindow::~MainWindow() {
    if (signalMapper != NULL) 	{ delete signalMapper; }
    if (ui			 != NULL)	{ delete ui; }
}

