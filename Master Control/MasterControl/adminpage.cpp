#include "adminpage.h"
#include "ui_adminpage.h"

AdminPage::AdminPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);
    //signals and slots
    connect(ui->calculatorButton,SIGNAL (released()),this, SLOT(goToCalc()));
    connect(ui->notepadButton,SIGNAL (released()),this, SLOT(goToNotepad()));
    connect(ui->AddNewUser,SIGNAL (released()),this, SLOT(goToNewUser()));
}
//goes to other programs depending on button pressed.
void AdminPage::goToCalc(){
    auto calc = new Calculator();
    calc->show();
}
void AdminPage::goToNotepad(){
    auto window = new Notepad();
    window->show();
}
void AdminPage::goToNewUser(){
    auto adduser = new AddNewUser();
    adduser->show();
}
AdminPage::~AdminPage()
{
    delete ui;
}

void AdminPage::on_AdminPage_finished(int result)
{
    this->close();
}

