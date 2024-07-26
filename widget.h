#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

#include "calculator.h"
#include "stopwatch.h"
#include "timer.h"
#include "notepad.h"
#include "paintboard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void currentClock();
    void leaveWorkClock();
    void btn_calculator();
    void btn_stopwatch();
    void btn_timer();
    void btn_notepad();
    void btn_paintboard();

private:
    Ui::Widget *ui;
    Calculator *calculator;
    Stopwatch *stopwatch;
    Timer *timer;
    Notepad *notepad;
    Paintboard *paintboard;
    QTimer *currentTimer;
    QTimer *leaveWorkTimer;
};
#endif // WIDGET_H
