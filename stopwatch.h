#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QWidget>

namespace Ui {
class Stopwatch;
}

class Stopwatch : public QWidget
{
    Q_OBJECT

public:
    explicit Stopwatch(QWidget *parent = nullptr);
    ~Stopwatch();

private:
    Ui::Stopwatch *ui;
};

#endif // STOPWATCH_H
