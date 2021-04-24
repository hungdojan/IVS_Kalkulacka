/**
 * @class HelpWindow helpWindow.h "./gui/helpWindow.h"
 * @brief Okno s uživatelskou nápovědou
 *
 * @details Tato třída zobrazuje uživatelskou nápovědu k užití aplikace.
 *
 * @authors Hung Do, David Kedra, Petr Kolařík
 *
 * @version 1.0.0
 * @date 30.04.2021
 * @copyright GNU Public Licence v3.0
 */
#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QWidget>

namespace Ui {
class HelpWindow;
}

class HelpWindow : public QWidget
{
    Q_OBJECT

public:
    /// Konstruktor třídy HelpWindow
    HelpWindow(QWidget *parent = nullptr);
    /// Destruktor třídy HelpWindow
    ~HelpWindow();

private:
    Ui::HelpWindow *ui;     /**< Seznam objektů v okně HelpWindow */
};

#endif // HELPWINDOW_H
