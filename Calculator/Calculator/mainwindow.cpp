#include "mainwindow.h"
#include "ui_mainwindow.h"

double calcVal = 0.0;
QString memory = "0.0";
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcVal));
    QPushButton *numButtons[10];
    for(int i=0;i<10;++i){
        QString butName = "Button" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(numButtons[i],SIGNAL (released()),this, SLOT(NumPressed()));
    }
    connect(ui->ButtonAdd,SIGNAL (released()),this, SLOT(MathButtonPressed()));
    connect(ui->ButtonDivide,SIGNAL (released()),this, SLOT(MathButtonPressed()));
    connect(ui->ButtonMult,SIGNAL (released()),this, SLOT(MathButtonPressed()));
    connect(ui->ButtonSubstract,SIGNAL (released()),this, SLOT(MathButtonPressed()));
    connect(ui->ButtonEquals,SIGNAL (released()),this, SLOT(EqualButton()));
    connect(ui->ButtonAC,SIGNAL (released()),this, SLOT(ACButton()));
    connect(ui->ButtonMem,SIGNAL (released()),this, SLOT(MemCall()));
    connect(ui->ButtonMemAdd,SIGNAL (released()),this, SLOT(MemPlus()));
    connect(ui->ButtonMemClear,SIGNAL (released()),this, SLOT(MemClear()));


}
MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::NumPressed()
{
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();
    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)){
        ui->Display->setText(butVal);
    }
    else {
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal, 'g',16));
    }


}
void MainWindow::MathButtonPressed(){
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
    QString displayVal = ui->Display->text();
    calcVal = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    if(QString::compare(butVal, "/",Qt::CaseInsensitive) == 0){
        divTrigger = true;
    }
    else if(QString::compare(butVal, "*",Qt::CaseInsensitive) == 0){
        multTrigger = true;
        }
    else if(QString::compare(butVal, "-",Qt::CaseInsensitive) == 0){
        subTrigger= true;
    }
    else{
        addTrigger = true;
    }
    ui->Display->setText("");
}
void MainWindow::EqualButton(){
    double solution = 0.0;
    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();
    if(addTrigger || subTrigger || multTrigger || divTrigger){
        if(addTrigger)
            solution = calcVal + dblDisplayVal;
        else if(subTrigger)
            solution = calcVal - dblDisplayVal;
        else if(multTrigger)
            solution = calcVal * dblDisplayVal;
        else
            solution = calcVal / dblDisplayVal;

    }
    ui->Display->setText(QString::number(solution));
}
void MainWindow::ChangeNumberSign(){
    QString displayVal = ui->Display->text();
    QRegExp reg("[-]?[0-9.]*");
    if(reg.exactMatch(displayVal)){
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplayValSign = -1 * dblDisplayVal;
        ui->Display->setText(QString::number(dblDisplayValSign));
    }
}
void MainWindow::ACButton(){
    ui->Display->setText("0.0");
}
void MainWindow::MemCall(){
    if(memory != "0" && memory!= "0.0")
        ui->Display->setText(memory);
}
void MainWindow::MemClear(){
    memory = "0.0";
}
void MainWindow::MemPlus(){
    memory = ui->Display->text();
}
