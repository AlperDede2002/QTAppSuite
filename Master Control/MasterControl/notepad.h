#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

namespace Ui {
class Notepad;
}

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = nullptr);
    ~Notepad();

private slots:
    void NewFile();
    void OpenFile();
    void SaveFile();
    void SaveAs();
    void CutText();
    void CopyText();
    void PasteText();
    void RedoText();
    void UndoText();
    void Information();

private:
    Ui::Notepad *ui;
    QString file_path;

};

#endif // NOTEPAD_H
