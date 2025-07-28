#include "mastercontrol.h"
#include "ui_mastercontrol.h"
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QList>
#include <QMessageBox>

//lists for information pulled from file
QStringList userNameList;
QStringList passwordList;
QVector<int> accessList;

//ancient way to check for login info
//!!!!!! THIS IS DUMB! CHANGE THIS LATER TO ERROR CHECKS!
int errorcheck = 1;

//constructor
MasterControl::MasterControl(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MasterControl)
{
    ui->setupUi(this);
    // Signals and Slots
    connect(ui->loginButton,SIGNAL (released()),this, SLOT(loginButtonClicked()));
    connect(ui->refreshButton,SIGNAL (released()),this, SLOT(refreshButtonClicked()));
    // Open file and import information
    ///this will change to SQL later, not familiar enough for now so .txt
    QFile file("C:\\loginInfo.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error opening file.";
        exit(1);
    }
    // Read the file line by line
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(" ", QString::SkipEmptyParts);

        // Check if the line has at least three parts
        if (parts.size() >= 3)
        {
            QString userName = parts[0];
            QString password = parts[1];
            int access = parts[2].toInt();

            userNameList.append(userName);
            passwordList.append(password);
            accessList.append(access);
        }
    }

    // Close the file
    file.close();

    // debug print for convenience
    for (int i = 0; i < userNameList.size(); ++i)
    {
        qDebug() << "Username:" << userNameList.at(i)
                 << "Password:" << passwordList.at(i)
                 << "Access:" << accessList.at(i);
    }


}

//refresh button, mainly copied from constructor
void MasterControl::refreshButtonClicked(){

    //emptying the lists for new input
    userNameList.clear();
    passwordList.clear();
    accessList.clear();

    // Open file and import information
    ///this will change to SQL later, not familiar enough for now so .txt
    QFile file("C:\\loginInfo.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"Warning","File is not open." );
        exit(1);
    }


    // Read the file line by line
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(" ", QString::SkipEmptyParts);

        // Check if the line has at least three parts
        if (parts.size() >= 3)
        {
            QString userName = parts[0];
            QString password = parts[1];
            int access = parts[2].toInt();

            userNameList.append(userName);
            passwordList.append(password);
            accessList.append(access);
        }
    }

    // Close the file
    file.close();
    QMessageBox::information(this,"Info","Refresh completed." );
    // Print the arrays for demonstration
    for (int i = 0; i < userNameList.size(); ++i)
    {
        // debug print for convenience
        qDebug() << "Username:" << userNameList.at(i)
                 << "Password:" << passwordList.at(i)
                 << "Access:" << accessList.at(i);
    }
}
//main code; login button
void MasterControl::loginButtonClicked(){
    //debug to check if the list carried over
    qDebug() << "Size" << userNameList.size();
    //for loop to check line by line
    for (int i = 0; i < userNameList.size(); ++i)
    {
        //inputting username and password from UI.
        QString username = ui->Username->text();
        QString password = ui->Password->text();
        ////debug print to check if inputted correctly
        //qDebug() << "UsernameList:" << userNameList.at(i) << "PasswordList:" << passwordList.at(i) << "Username:" << username << "Password:" << password;
        //checking if username and password is correct
        if(username == userNameList.at(i) && password == passwordList.at(i)){
            //checking access level, switch case doesn't work for some reason. Launching apps according to access level.
            if(accessList.at(i) == 0){
                QMessageBox::information(this,"Login","Access Level 0: Opening Notepad..." );
                this->hide();
                auto window = new Notepad();
                window->show();
                errorcheck = 0;
            }
            else if(accessList.at(i) == 1){
                QMessageBox::information(this,"Login","Access Level 1: Opening Calculator..." );
                this->hide();
                auto calc = new Calculator();
                calc->show();
                errorcheck = 0;
            }
            else if(accessList.at(i) == 2){
                QMessageBox::information(this,"Login","Access Level 2: Welcome, Admin..." );
                auto admin = new AdminPage();
                admin->show();
                errorcheck = 0;
            }
            //if unexpected input in access field.
            else{
                QMessageBox::critical(this,"Warning","Access not granted! Contact admin!" );
            }
        }
    }
    //if incorrect password or username
    if(errorcheck>0){
        QMessageBox::warning(this,"Warning","Username or Password not correct.");}
}

//destructor
MasterControl::~MasterControl()
{
    delete ui;
}

