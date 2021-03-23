#include "mainwindow.h"
#include "math_lib.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	Math m;
	double b = m.Sum(1, 2);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

