#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QDialog>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>

namespace Ui {
class Notepad;
}

class Notepad : public QDialog
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = nullptr);
    ~Notepad();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::Notepad *ui;
    QMenuBar *menuBar;
    QMenu *menu;
    void getFileName(QString filename);

private slots:
    void openFile();
    void saveFile();
    void newFile();

};

#endif // NOTEPAD_H
