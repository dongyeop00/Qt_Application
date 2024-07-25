#include "paingboard.h"
#include "ui_paingboard.h"

Paingboard::Paingboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Paingboard)
{
    ui->setupUi(this);
}

Paingboard::~Paingboard()
{
    delete ui;
}
