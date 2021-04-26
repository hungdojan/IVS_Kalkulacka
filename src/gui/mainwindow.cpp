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
    toClear = false;
    adv_operation = Operation::NONE_O;
    adv_result = 0.0;
    memory = 0.0;
    signalMapper = new QSignalMapper(this);

    // nastaveni signalu pro numsAndBasicOpsTable
    for (int i = 0; i < ui->numsAndBasicOpsTable->count(); i++) {
        connect(ui->numsAndBasicOpsTable->itemAt(i)->widget(), SIGNAL(clicked()), signalMapper, SLOT(map()));
    }
    // nastaveni signalu pro advanceOperationsTable
    for (int i = 0; i < ui->advancedOperationsTable->count(); i++) {
        connect(ui->advancedOperationsTable->itemAt(i)->widget(), SIGNAL(clicked()), signalMapper, SLOT(map()));
    }
    // nastaveni signalu pro basicOperationsTable
    for (int i = 0; i < ui->basicOperationsTable->count(); i++) {
        connect(ui->basicOperationsTable->itemAt(i)->widget(), SIGNAL(clicked()), signalMapper, SLOT(map()));
    }
    // namapovani signalu
    MapSignal();
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(Action(int)));
}

void MainWindow::MapSignal() {
    // cisla a tecka
    signalMapper -> setMapping(ui->zeroButton  		 , Button::ZERO  );
    signalMapper -> setMapping(ui->oneButton   		 , Button::ONE   );
    signalMapper -> setMapping(ui->twoButton   		 , Button::TWO   );
    signalMapper -> setMapping(ui->threeButton 		 , Button::THREE );
    signalMapper -> setMapping(ui->fourButton  		 , Button::FOUR  );
    signalMapper -> setMapping(ui->fiveButton  		 , Button::FIVE  );
    signalMapper -> setMapping(ui->sixButton   		 , Button::SIX   );
    signalMapper -> setMapping(ui->sevenButton 		 , Button::SEVEN );
    signalMapper -> setMapping(ui->eightButton 		 , Button::EIGHT );
    signalMapper -> setMapping(ui->nineButton  		 , Button::NINE  );
    signalMapper -> setMapping(ui->decimalPointButton, Button::POINT );

    // zakladni mat. operace
    signalMapper -> setMapping(ui->addButton   		 , Button::ADD   );
    signalMapper -> setMapping(ui->subButton   		 , Button::SUB	 );
    signalMapper -> setMapping(ui->mulButton 		 , Button::MUL   );
    signalMapper -> setMapping(ui->divideButton		 , Button::DIV   );

    // rozsirene mat. operace
    signalMapper -> setMapping(ui->logButton   		 , Button::LOG   );
    signalMapper -> setMapping(ui->powerButton 		 , Button::POW   );
    signalMapper -> setMapping(ui->rootButton 		 , Button::SQRT  );
    signalMapper -> setMapping(ui->factorButton		 , Button::FACT  );

    // ostatni
    signalMapper -> setMapping(ui->equalSignButton 	 , Button::EQL   );
    signalMapper -> setMapping(ui->helpButton  		 , Button::HELP  );
    signalMapper -> setMapping(ui->deleteButton		 , Button::DEL   );
    signalMapper -> setMapping(ui->clearButton		 , Button::CLR	 );

    // FIXME: additional features that can be removed in the final version
    signalMapper -> setMapping(ui->memoryOutButton	 , Button::MEMOUT);
    signalMapper -> setMapping(ui->memoryInButton 	 , Button::MEMIN );
    signalMapper -> setMapping(ui->invertButton	  	 , Button::INV   );
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
        case Button::INV:
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
        case Button::CLR:
            ClearData();
            break;
        case Button::MEMOUT:
        case Button::MEMIN:
            MemoryOperation(id);	//< this feature can be removed in the final version
            break;
        default:
            qDebug() << "Nedefinovana akce!\n";
            break;
    }

    // displej update
    ui->textLabel->setText(currText);
}

void MainWindow::PrintNumber(int id) {
    qDebug() << "Tlacitko: " << id;
    //ma-li byt premazan aktualni text na displayi, vymaze se
    if(toClear){
        currText = "";
        toClear = false;
    }
    //je-li zmacknuto tlacitko k invertovani znamenka, dojde jen k jeho zmene
    if(id == Button::INV){
        //cislo 0 nemuze byt zapsano jako -0
        if(currText.size()==0 || currText == "0")
            currText = "0";
        else if(currText[0] != '-')
            currText.prepend("-");
        else
            currText.remove(0,1);
        return;
    }

    //tecka musi pridat ".", ne svoje id
    if(id == Button::POINT){
        if(currText.contains('.') == true)
            return;
        else if(currText.size() == 0)
            currText = "0";
        currText.append(".");
    }
    else{
        //aby nebyla prvni 0, musi se kdyztak vymazat
        if(currText.size() == 1 && currText[0] == '0')
                currText = "";
        else if(currText == "-0")
            currText.chop(1);
        currText.append(QString::number(id));
    }
}

void MainWindow::ResetVals(){
    adv_result = 0.0;
    adv_operation = Operation::NONE_O;
    operation = Operation::NONE_O;
    toClear = true;
}

void MainWindow::BasicOperation(int id) {
    qDebug() << "Tlacitko: " << id << " op: " << operation;
    //aby basicOperace aplikovala pripadny vysledek advance (chova se jako =)
    if(adv_operation != Operation::NONE_O && id != Button::EQL){
        //dojde ke zmene adv.operace na basic napr. 2,^,+,3 = 5
        if(toClear == true){
            adv_operation = NONE_O;
            currText = QString::number(adv_result, 'g', MAX_DIGITS);
            adv_result = 0;
        }
        //ziska se vysledek adv.operace: napr. 2,^,3,-,3 = 5
        else{
            //zavolana AdvanceOperation, aby se ziskal vysledek
            if(adv_operation == Operation::POW_O)
                AdvanceOperation(Button::POW);
            else if(adv_operation == Operation::SQRT_O)
                AdvanceOperation(Button::SQRT);

            currText = QString::number(result, 'g', MAX_DIGITS);
        }
    }

    //zjisteni, co bylo za stav predchozi operace

    //byla-li uz nejaka operace nastavena, dojde k vypoctu
    if(operation != Operation::NONE_O && toClear == false){
        switch (operation) {
            case Operation::ADD_O:
                result = m.Sum(result, currText.toDouble());
                break;
            case Operation::SUB_O:
                result = m.Subtract(result, currText.toDouble());
                break;
            case Operation::MUL_O:
                result = m.Multiply(result, currText.toDouble());
                break;
            case Operation::DIV_O:
                try {
                    result = m.Divide(result, currText.toDouble());
                } catch (std::exception e) {
                    //error deleni nulou a reset hodnot
                    currText = "Error div 0";
                    ResetVals();
                    return;
                }
                break;
        }
        //zobrazeni vysledku result na display
        currText = QString::number(result, 'g', MAX_DIGITS);
    }
    //pokud zadna operace nebyla ulozena, pouze se nastavi nova a text jde do result
    if(operation == Operation::NONE_O)
        result = currText.toDouble();

    //nastaveni prislusne nasledujici operace do stavu
    switch (id) {
        case Button::ADD:
            operation = Operation::ADD_O;
            break;
        case Button::SUB:
            operation = Operation::SUB_O;
            break;
        case Button::MUL:
            operation = Operation::MUL_O;
            break;
        case Button::DIV:
            operation = Operation::DIV_O;
            break;
        //volani "rovna se" z vlastni funkce resetuje operaci
        case Button::EQL:
            operation = Operation::NONE_O;
            break;
    }
    //text se ma smazat po stisku dalsich cisel
    toClear = true;
}

void MainWindow::AdvanceOperation(int id) {
    qDebug() << "Tlacitko: " << id;

    //pokud doslo ke zmene operace bez zadani operandu, zrusi se
    //napr. 5,-,^,2 = 25
    if(operation != Operation::NONE_O && toClear == true){
        operation = NONE_O;
    }

    //vyber konkretni operace podle stisknuteho tlacitka
    //operace LOG a FACT primo zobrazi vysledek, jine potrebuji pockat na dalsi operand a stisknuti '='
    switch (id) {
        case Button::LOG:
            try {
                currText = QString::number(m.Log10(currText.toDouble()), 'g', MAX_DIGITS);
            } catch (std::exception e) {
                //error log (<= 0) a reset hodnot
                currText = "Error log";
                ResetVals();
                return;
            }
            OutputResult();
            break;

        case Button::POW:
            //pokud bylo tlacitko poprve zmacknuto, nastavi se adv_operatio
            //bazove cislo jde do adv_result (a tedy predchozi operand a operace jsou zachovany)
            if(adv_operation != Operation::POW_O){
                adv_result = currText.toDouble();
                adv_operation = Operation::POW_O;
            }
            //bylo zmacknuto "=", dopocte se mocnina do/z adv_result a ulozi jakoby na displej, jenze
            //se jeste provede predchozi basic operace (napr. se cela mocnina pricte k predchozimu vysledku)
            else if(toClear == false){ //bez podminky vicenasobne zmacknuti stale operuje aktualni currText
                try {
                    adv_result = m.Pow(adv_result, currText.toDouble());
                } catch (std::exception e) {
                    //error mocniny, musi byt jen prirozena
                    currText = "Error pow";
                    ResetVals();
                    return;
                }
                currText = QString::number(adv_result, 'g', MAX_DIGITS);
                //zavola se funkce jakoby bylo kliknuto "rovna se"
                BasicOperation(Button::EQL);

                //restart advance hodnot
                adv_result = 0.0;
                adv_operation = Operation::NONE_O;
            }
            //vzdy ma dojit ke smazani displaye pri dalsim operandu
            toClear = true;
            break;

        case Button::SQRT:
            if(adv_operation != Operation::SQRT_O){
                adv_result = currText.toDouble();
                adv_operation = Operation::SQRT_O;
            }
            //bylo zmacknuto "=", dopocte se mocnina do/z adv_result a ulozi jakoby na displej, jenze
            //se jeste provede predchozi basic operace (napr. se cela mocnina pricte k predchozimu vysledku)
            else if(toClear == false){ //bez podminky vicenasobne zmacknuti stale operuje aktualni currText
                try {
                    adv_result = m.Sqrt(adv_result, currText.toDouble());
                } catch (std::exception e) {
                    //error Nulta odmocnina, odm. z  -X... a reset hodnot
                    currText = "Error sqrt";
                    ResetVals();
                    return;
                }
                currText = QString::number(adv_result, 'g', MAX_DIGITS);
                BasicOperation(Button::EQL);

                //restart advance hodnot
                adv_result = 0.0;
                adv_operation = Operation::NONE_O;
            }
            //vzdy ma dojit ke smazani displaye pri dalsim operandu
            toClear = true;
            break;

        case Button::FACT:
            //primo i ukaze vysledek
            try {
                currText = QString::number(m.Factor(currText.toDouble()), 'g', MAX_DIGITS);
            } catch (std::exception e) {
                //error (<0)! a reset hodnot
                currText = "Error fact";
                ResetVals();
                return;
            }
            OutputResult();
            break;
    }
}

void MainWindow::OutputResult() {
    qDebug() << "Tlacitko: " << Button::EQL;

    //pro 2-operandovou funkci je zpetne zavolana AdvanceOperation
    if(adv_operation == Operation::POW_O)
        AdvanceOperation(Button::POW);
    else if(adv_operation == Operation::SQRT_O)
        AdvanceOperation(Button::SQRT);

    //nasledujici operace bude vynulovana a zobrazi se result
    else
        BasicOperation(Button::EQL);

    //jeli ve vypisu i text nejake chyby, nesmi se premazat
    bool isNum = currText.toDouble(&isNum);
    if(isNum)
        currText = QString::number(result, 'g', MAX_DIGITS);
    else{
        toClear = true;
        result = 0;
        adv_result = 0;
    }
}

void MainWindow::DisplayHelp() {
    helpWindow.show();
    qDebug() << "Tlacitko: " << Button::HELP;
}

void MainWindow::DeleteDigit() {
    qDebug() << "Tlacitko: " << Button::DEL;

    //useknuti posledni cislice/tecky
    currText.chop(1);
    //byla-li posleni cislice, zobrazi se 0, nebo je stav zobrazeni vysledku
    if(currText.size() == 0 || toClear == true)
        currText = "0";
}

void MainWindow::ClearData() {
    currText = "0";
    ResetVals();
}

void MainWindow::MemoryOperation(int id) {
    qDebug() << "Tlacitko: " << id;

    //MEM+ tlacitko pridani do pameti
    if(id == Button::MEMIN){
        memory = currText.toDouble();
    }
    //MEM vlozeni z pameti
    else if(id == Button::MEMOUT){
        currText = QString::number(memory, 'g', MAX_DIGITS);
        toClear = false;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
    switch(e->key()) {
        case Qt::Key_0:
        case Qt::Key_1:
        case Qt::Key_2:
        case Qt::Key_3:
        case Qt::Key_4:
        case Qt::Key_5:
        case Qt::Key_6:
        case Qt::Key_7:
        case Qt::Key_8:
        case Qt::Key_9:
            emit Action(e->key() - Qt::Key_0);
            break;

        case Qt::Key_Plus:		 { emit Action(Button::ADD);	   break; }
        case Qt::Key_Minus:		 { emit Action(Button::SUB);   	   break; }
        case Qt::Key_Asterisk:	 { emit Action(Button::MUL);   	   break; }
        case Qt::Key_Slash:		 { emit Action(Button::DIV);   	   break; }

        case Qt::Key_Return:	// nwm na co je nabindovane
        case Qt::Key_Equal:
        case Qt::Key_Enter:		 { emit Action(Button::EQL);   	   break; }
        case Qt::Key_Period:	 { emit Action(Button::POINT); 	   break; }

        case Qt::Key_Delete:	 { emit Action(Button::CLR);	   break; }
        case Qt::Key_Backspace:	 { emit Action(Button::DEL);   	   break; }
        case Qt::Key_F1:		 { emit Action(Button::HELP);  	   break; }
    }
}

MainWindow::~MainWindow() {
    if (signalMapper != NULL) 	{ delete signalMapper; }
    if (ui			 != NULL)	{ delete ui; }
}

