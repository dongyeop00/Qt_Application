#include "notepad.h"
#include "ui_notepad.h"



Notepad::Notepad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);

    menuBar = new QMenuBar(this);

    menu = new QMenu("File");
    QAction *newAction = new QAction("New", this);
    QAction *openAction = new QAction("Open", this);
    QAction *saveAction = new QAction("Save", this);

    menu->addAction(newAction);
    menu->addAction(openAction);
    menu->addAction(saveAction);

    menuBar->addMenu(menu);

    connect(openAction, SIGNAL(triggered(bool)), this, SLOT(openFile()));
    connect(saveAction, SIGNAL(triggered(bool)), this, SLOT(saveFile()));
    connect(newAction, SIGNAL(triggered(bool)), this, SLOT(newFile()));
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::openFile(){
    QString currentText = ui->textEdit->toPlainText();
    if(!currentText.isEmpty()){
        QMessageBox::StandardButton reply = QMessageBox::warning(this, tr("Warning"), tr("텍스트가 존재합니다.\n그래도 새로운 파일을 여시겠습니까?"), QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes){
            QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), tr("/home/dps_debug/Dongyeop/"), tr("Text Files (*.txt);;All Files (*)"));

            if (!fileName.isEmpty()){
                getFileName(fileName);
            }
        }
    }else{
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), tr("/home/dps_debug/Dongyeop/"), tr("Text Files (*.txt);;All Files (*)"));

        if (!fileName.isEmpty()){
            getFileName(fileName);
        }
    }
}

void Notepad::saveFile(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));
    qDebug() << fileName;

    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Error"), tr("Cannot save file: ") + file.errorString());
            return;
        }

        QTextStream out(&file);
        out << ui->textEdit->toPlainText();  // QTextEdit의 텍스트 가져오기
        file.close();
    }
}

void Notepad::newFile(){
    QString text = ui->textEdit->toPlainText();
    if(!text.isEmpty()){
        QMessageBox::StandardButton reply = QMessageBox::warning(this, tr("warning"), tr("really?"), QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes){
            ui->textEdit->setText("");
        }
    }else{
        ui->textEdit->setText("");
    }
}

void Notepad::getFileName(QString filename){
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, tr("Error"), tr("Cannot open file: ") + file.errorString());
        return;
    }

    QTextStream in(&file);
    QString fileContent = in.readAll();

    ui->textEdit->setPlainText(fileContent);
    file.close();
}
