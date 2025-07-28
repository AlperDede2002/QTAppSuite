#ifndef ADDNEWUSER_H
#define ADDNEWUSER_H

#include <QDialog>

namespace Ui {
class AddNewUser;
}

class AddNewUser : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewUser(QWidget *parent = nullptr);
    ~AddNewUser();

private slots:
    void confirmNewUser();

    void on_AddNewUser_finished(int result);

private:
    Ui::AddNewUser *ui;
};

#endif // ADDNEWUSER_H
