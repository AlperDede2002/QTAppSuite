/********************************************************************************
** Form generated from reading UI file 'mastercontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASTERCONTROL_H
#define UI_MASTERCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MasterControl
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *Username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *Password;
    QPushButton *loginButton;
    QPushButton *refreshButton;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MasterControl)
    {
        if (MasterControl->objectName().isEmpty())
            MasterControl->setObjectName(QString::fromUtf8("MasterControl"));
        MasterControl->resize(510, 297);
        centralwidget = new QWidget(MasterControl);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 511, 271));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        Username = new QLineEdit(groupBox);
        Username->setObjectName(QString::fromUtf8("Username"));

        horizontalLayout->addWidget(Username);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        Password = new QLineEdit(groupBox);
        Password->setObjectName(QString::fromUtf8("Password"));

        horizontalLayout_2->addWidget(Password);


        verticalLayout->addLayout(horizontalLayout_2);

        loginButton = new QPushButton(groupBox);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        verticalLayout->addWidget(loginButton);

        refreshButton = new QPushButton(groupBox);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));

        verticalLayout->addWidget(refreshButton);

        MasterControl->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MasterControl);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 510, 25));
        MasterControl->setMenuBar(menubar);

        retranslateUi(MasterControl);

        QMetaObject::connectSlotsByName(MasterControl);
    } // setupUi

    void retranslateUi(QMainWindow *MasterControl)
    {
        MasterControl->setWindowTitle(QCoreApplication::translate("MasterControl", "MasterControl", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MasterControl", "MasterControl V0.1 Pre-SQL", nullptr));
        label->setText(QCoreApplication::translate("MasterControl", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("MasterControl", "Password  ", nullptr));
        Password->setPlaceholderText(QString());
        loginButton->setText(QCoreApplication::translate("MasterControl", "Login", nullptr));
        refreshButton->setText(QCoreApplication::translate("MasterControl", "Refresh Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MasterControl: public Ui_MasterControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASTERCONTROL_H
