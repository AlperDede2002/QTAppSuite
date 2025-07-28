#ifndef Calculator_H
#define Calculator_H

#include <QDialog>

namespace Ui {
class Calculator;
}

class Calculator : public QDialog
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButton();
    void ACButton();
    void MemPlus();
    void MemClear();
    void MemCall();
    void PlusMinus();

};

#endif // Calculator_H
