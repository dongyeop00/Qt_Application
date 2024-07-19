#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QDialog>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class Notepad;
}

class Notepad : public QDialog
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = nullptr);
    ~Notepad();

private:
    Ui::Notepad *ui;
    QMenuBar *menuBar;
    QMenu *menu;

private slots:
    void openFile();
    void saveFile();
    void newFile();
};

#endif // NOTEPAD_H
