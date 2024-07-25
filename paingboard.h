#ifndef PAINGBOARD_H
#define PAINGBOARD_H

#include <QDialog>

namespace Ui {
class Paingboard;
}

class Paingboard : public QDialog
{
    Q_OBJECT

public:
    explicit Paingboard(QWidget *parent = nullptr);
    ~Paingboard();

private:
    Ui::Paingboard *ui;
};

#endif // PAINGBOARD_H
