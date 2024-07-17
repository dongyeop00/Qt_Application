#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QDialog>
#include <QTimer>
#include <QTime>

namespace Ui {
class Stopwatch;
}

class Stopwatch : public QDialog
{
    Q_OBJECT

public:
    explicit Stopwatch(QWidget *parent = nullptr);
    ~Stopwatch();

private:
    Ui::Stopwatch *ui;
    QTimer *timer;
    int elapsedTime;
    QTime startTime;

private slots:
    void btn_start();
    void btn_stop();
    void btn_reset();
    void btn_lap();
    void update_display();
};

#endif // STOPWATCH_H
