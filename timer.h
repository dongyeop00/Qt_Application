#ifndef TIMER_H
#define TIMER_H

#include <QDialog>
#include <QTimer>


namespace Ui {
class Timer;
}

class Timer : public QDialog
{
    Q_OBJECT

public:
    explicit Timer(QWidget *parent = nullptr);
    ~Timer();

private:
    Ui::Timer *ui;
    QTimer *timer;
    int totalSeconds = 0;

private slots:
    void btn_start();
    void btn_stop();
    void btn_reset();
    void updateTimer();
};

#endif // TIMER_H
