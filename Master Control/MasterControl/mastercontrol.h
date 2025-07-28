#ifndef MASTERCONTROL_H
#define MASTERCONTROL_H

#include <QMainWindow>
#include "calculator.h"
#include "notepad.h"
#include "adminpage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MasterControl; }
QT_END_NAMESPACE

class MasterControl : public QMainWindow
{
    Q_OBJECT

public:
    MasterControl(QWidget *parent = nullptr);
    ~MasterControl();

private:
    Ui::MasterControl *ui;

private slots:
    void loginButtonClicked();
    void refreshButtonClicked();

};
#endif // MASTERCONTROL_H
