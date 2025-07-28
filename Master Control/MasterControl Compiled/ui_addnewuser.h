/********************************************************************************
** Form generated from reading UI file 'addnewuser.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWUSER_H
#define UI_ADDNEWUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddNewUser
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *Username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *Password;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *AccessLevel;
    QPushButton *confirmButton;

    void setupUi(QDialog *AddNewUser)
    {
        if (AddNewUser->objectName().isEmpty())
            AddNewUser->setObjectName(QString::fromUtf8("AddNewUser"));
        AddNewUser->resize(530, 283);
        groupBox = new QGroupBox(AddNewUser);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 531, 281));
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

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        AccessLevel = new QLineEdit(groupBox);
        AccessLevel->setObjectName(QString::fromUtf8("AccessLevel"));

        horizontalLayout_3->addWidget(AccessLevel);


        verticalLayout->addLayout(horizontalLayout_3);

        confirmButton = new QPushButton(groupBox);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));

        verticalLayout->addWidget(confirmButton);


        retranslateUi(AddNewUser);

        QMetaObject::connectSlotsByName(AddNewUser);
    } // setupUi

    void retranslateUi(QDialog *AddNewUser)
    {
        AddNewUser->setWindowTitle(QCoreApplication::translate("AddNewUser", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AddNewUser", "MasterControl Admin V0.1 Pre-SQL", nullptr));
        label->setText(QCoreApplication::translate("AddNewUser", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("AddNewUser", "Password  ", nullptr));
        label_3->setText(QCoreApplication::translate("AddNewUser", "Access level: (0,1,2)", nullptr));
        confirmButton->setText(QCoreApplication::translate("AddNewUser", "Add New User", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddNewUser: public Ui_AddNewUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWUSER_H
