#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>
#include "calculator.h"
#include "notepad.h"
#include "addnewuser.h"

namespace Ui {
class AdminPage;
}

class AdminPage : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPage(QWidget *parent = nullptr);
    ~AdminPage();

private:
    Ui::AdminPage *ui;

private slots:
    void goToCalc();
    void goToNotepad();
    void goToNewUser();
    void on_AdminPage_finished(int result);
};

#endif // ADMINPAGE_H
