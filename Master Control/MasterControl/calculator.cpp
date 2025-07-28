#include "Calculator.h"
#include "ui_Calculator.h"
//initialization of various variables needed through the code

double calcVal = 0.0;   //for calculations
QString memory = "0.0";   //for the memory button

//for calculation checks
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

//constructor
Calculator::Calculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);      //initializes the display in the beginning. Pre-prepared for save function
    ui->Display->setText(QString::number(calcVal));

    //better looking and more efficient way to assign signals to number slots
    QPushButton *numButtons[10];
    for(int i=0;i<10;++i){
        QString butName = "Button" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(butName);
        connect(numButtons[i],SIGNAL (released()),this, SLOT(NumPressed()));
    }
    //signals to slots
    connect(ui->ButtonAdd,SIGNAL (released()),this, SLOT(MathButtonPressed()));
    connect(ui->ButtonDivide,SIGNAL (released()),this, SLOT(MathButtonPressed()));
    connect(ui->ButtonMult,SIGNAL (released()),this, SLOT(MathButtonPressed()));
    connect(ui->ButtonSubstract,SIGNAL (released()),this, SLOT(MathButtonPressed()));
    connect(ui->ButtonEquals,SIGNAL (released()),this, SLOT(EqualButton()));
    connect(ui->ButtonAC,SIGNAL (released()),this, SLOT(ACButton()));
    connect(ui->ButtonMem,SIGNAL (released()),this, SLOT(MemCall()));
    connect(ui->ButtonMemAdd,SIGNAL (released()),this, SLOT(MemPlus()));
    connect(ui->ButtonMemClear,SIGNAL (released()),this, SLOT(MemClear()));
    connect(ui->ButtonPlusMinus,SIGNAL (released()),this, SLOT(PlusMinus()));

}

Calculator::~Calculator()
{
    delete ui;
}

//Code for
void Calculator::NumPressed()
{
    QPushButton *button = (QPushButton *)sender();      //creates a button pointer which is the button that sends the signal (e.g. the '0' button)
    QString butVal = button->text();        //copies the text on the pressed button.
    QString displayVal = ui->Display->text();      //copies the text on the display to prepend to the clicked button.

    //checks if the display shows a 0, or a number was already written. if the display is 0,
    //the screen will be replaced by the clicked button, otherwise the value will be appended to the previous value.
    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)){
        ui->Display->setText(butVal);
    }
    else {
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal, 'g',16));
    }


}
//for all calculations
void Calculator::MathButtonPressed(){
    //resets all triggers.
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
    QString displayVal = ui->Display->text();   //copies the display
    calcVal = displayVal.toDouble();    //conversion to double for calculations
    QPushButton *button = (QPushButton *)sender();  ///creates a button pointer which is the button that sends the signal (e.g. the '0' button)
    QString butVal = button->text();       ///copies the text on the pressed button. (same process as above)
    //change the trigger depending on what button pressed.
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
    //deletes the display
    ui->Display->setText("0.0");
}
void Calculator::EqualButton(){
    double solution = 0.0;
    QString displayVal = ui->Display->text();   //copies the display
    double dblDisplayVal = displayVal.toDouble();   //converts the value to double.
    //according to trigger calculates the copied value with the display.
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
    ui->Display->setText(QString::number(solution)); //converts the solution into string and sends to display.
}
//deletes the display
void Calculator::ACButton(){
    ui->Display->setText("0.0");
}
//calls the memory
void Calculator::MemCall(){
    if(memory != "0" && memory!= "0.0")
        ui->Display->setText(memory);
}
//deletes the memory
void Calculator::MemClear(){
    memory = "0.0";
}
//copies the display to the memory
void Calculator::MemPlus(){
    memory = ui->Display->text();
}
//changes the display to -, by converting the display to double, and multiplying the display by -1.
void Calculator::PlusMinus(){
    QString displayVal = ui->Display->text();
    double tempval = displayVal.toDouble();
    tempval = tempval * -1;
    ui->Display->setText(QString::number(tempval));
}
