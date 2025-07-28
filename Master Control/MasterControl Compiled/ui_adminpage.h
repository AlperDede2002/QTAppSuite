/********************************************************************************
** Form generated from reading UI file 'adminpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPAGE_H
#define UI_ADMINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AdminPage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *notepadButton;
    QPushButton *calculatorButton;
    QPushButton *AddNewUser;

    void setupUi(QDialog *AdminPage)
    {
        if (AdminPage->objectName().isEmpty())
            AdminPage->setObjectName(QString::fromUtf8("AdminPage"));
        AdminPage->resize(391, 286);
        verticalLayout = new QVBoxLayout(AdminPage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(AdminPage);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(22);
        label->setFont(font);

        verticalLayout->addWidget(label);

        notepadButton = new QPushButton(AdminPage);
        notepadButton->setObjectName(QString::fromUtf8("notepadButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(notepadButton->sizePolicy().hasHeightForWidth());
        notepadButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(notepadButton);

        calculatorButton = new QPushButton(AdminPage);
        calculatorButton->setObjectName(QString::fromUtf8("calculatorButton"));
        sizePolicy.setHeightForWidth(calculatorButton->sizePolicy().hasHeightForWidth());
        calculatorButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(calculatorButton);

        AddNewUser = new QPushButton(AdminPage);
        AddNewUser->setObjectName(QString::fromUtf8("AddNewUser"));
        sizePolicy.setHeightForWidth(AddNewUser->sizePolicy().hasHeightForWidth());
        AddNewUser->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(AddNewUser);


        retranslateUi(AdminPage);

        QMetaObject::connectSlotsByName(AdminPage);
    } // setupUi

    void retranslateUi(QDialog *AdminPage)
    {
        AdminPage->setWindowTitle(QCoreApplication::translate("AdminPage", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AdminPage", "Welcome, Admin!", nullptr));
        notepadButton->setText(QCoreApplication::translate("AdminPage", "Notepad", nullptr));
        calculatorButton->setText(QCoreApplication::translate("AdminPage", "Calculator", nullptr));
        AddNewUser->setText(QCoreApplication::translate("AdminPage", "Add New User", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminPage: public Ui_AdminPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPAGE_H
