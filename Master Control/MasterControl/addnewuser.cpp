#include "addnewuser.h"
#include "ui_addnewuser.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QList>
#include <QMessageBox>

AddNewUser::AddNewUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewUser)
{
    ui->setupUi(this);
    //signals and slots
    connect(ui->confirmButton,SIGNAL (released()),this, SLOT(confirmNewUser()));
}
void AddNewUser::confirmNewUser(){
    QString filePath = "C:\\loginInfo.txt";
    QFile file(filePath);       //opens the file

    // Check if the file exists and is writable
    if (!QFile::exists(filePath)){
        QMessageBox::critical(nullptr, "File Error", "The file does not exist.");
        return;
    }

    if (!QFile::permissions(filePath).testFlag(QFile::WriteUser)){
        QMessageBox::critical(nullptr, "File Error", "Permission denied. Cannot write to the file.");
        return;
    }
    //inputs the username, password and access level.
    QString username = ui->Username->text();
    QString password = ui->Password->text();
    QString access = ui->AccessLevel->text();

    //makes the text into the right format for input
    QString text = "\n" + username + " " + password + " " + access;
    //appends the new user at the end of the file.
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << text;
        file.close();
    }
    QMessageBox::information(nullptr, "Success", ("New user added to the file.")); //opens success window.
}

AddNewUser::~AddNewUser()
{
    delete ui;
}

void AddNewUser::on_AddNewUser_finished(int result)
{
    this->close();
}

