#include "notepad.h"
#include "ui_notepad.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
    //because mainwindow
    this->setAttribute(::Qt::WA_DeleteOnClose);
    //signals and slots
    connect(ui->actionNew,SIGNAL (triggered()),this, SLOT(NewFile()));
    connect(ui->actionOpen,SIGNAL (triggered()),this, SLOT(OpenFile()));
    connect(ui->actionSave,SIGNAL (triggered()),this, SLOT(SaveFile()));
    connect(ui->actionSaveAs,SIGNAL (triggered()),this, SLOT(SaveAs()));
    connect(ui->actionCut,SIGNAL (triggered()),this, SLOT(CutText()));
    connect(ui->actionCopy,SIGNAL (triggered()),this, SLOT(CopyText()));
    connect(ui->actionPaste,SIGNAL (triggered()),this, SLOT(PasteText()));
    connect(ui->actionRedo,SIGNAL (triggered()),this, SLOT(RedoText()));
    connect(ui->actionUndo,SIGNAL (triggered()),this, SLOT(UndoText()));
    connect(ui->actionInfo,SIGNAL (triggered()),this, SLOT(Information()));
}
//resets file_path and the display
void Notepad::NewFile(){
    file_path = "";
    ui->textBox->setText("");
}

void Notepad::OpenFile(){
    //opens selection window
    QString file_path = QFileDialog::getOpenFileName(this, "Open The File");
    QFile file(file_path);
    //checks if file is Opened, or ReadOnly.
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "..","file not open");
        return;
    }
    QTextStream in(&file);
    //copies the entire file
    QString text = in.readAll();
    //replaces the display
    ui->textBox->setText(text);
    file.close();
}
void Notepad::SaveFile(){
    //pulls the opened file
    QFile file(file_path);
    //calls the SaveAs function if a file has not been opened yet
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        SaveAs();
    }
    //copies the display into a file
    QTextStream out(&file);
    QString text = ui->textBox->toPlainText();
    out << text;
    file.flush();
    file.close();
}
void Notepad::SaveAs(){
    //open a window to select the file type and location where the file will be saved.
    QString file_path = QFileDialog::getSaveFileName(this, "Open The File");
    QFile file(file_path);
    //Check if place and name was selected.
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "..","Selection wasn't made!");
        return;
    }
    //copy the display into the file.
    QTextStream out(&file);
    QString text = ui->textBox->toPlainText();
    out << text;
    file.flush();
    file.close();
}

//generic actions built in.
void Notepad::CutText(){
    ui->textBox->cut();
}
void Notepad::CopyText(){
    ui->textBox->copy();
}
void Notepad::PasteText(){
    ui->textBox->paste();
}
void Notepad::RedoText(){
    ui->textBox->redo();
}
void Notepad::UndoText(){
    ui->textBox->undo();
}

//opens a window with text
void Notepad::Information(){
    QString aboutText = "Notepad is a generic text editor included with all versions of Microsoft Windows that lets you create, open, and read plaintext files with a .txt file extension. If the file contains special formatting or is not a plaintext file, it cannot be read in Notepad. The image shown here is a small example of what the Notepad may look like while running.";
    QMessageBox::about(this,"About Notepad", aboutText);
}

Notepad::~Notepad()
{
    delete ui;
}


