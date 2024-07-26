#include "widget.h"
#include "ui_widget.h"

#include "calculator.h"
#include "stopwatch.h"
#include "timer.h"
#include "notepad.h"
#include "paintboard.h"

#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    currentTimer = new QTimer(this);
    leaveWorkTimer = new QTimer(this);

    connect(currentTimer, SIGNAL(timeout()), this, SLOT(currentClock()));
    connect(leaveWorkTimer, SIGNAL(timeout()), this, SLOT(leaveWorkClock()));

    leaveWorkTimer->start(1000);
    currentTimer->start(1000);

    connect(ui->btn_calculator, SIGNAL(clicked(bool)), this, SLOT(btn_calculator()));
    connect(ui->btn_StopWatch, SIGNAL(clicked(bool)), this, SLOT(btn_stopwatch()));
    connect(ui->btn_Timer, SIGNAL(clicked(bool)), this, SLOT(btn_timer()));
    connect(ui->btn_notepad, SIGNAL(clicked(bool)), this, SLOT(btn_notepad()));
    connect(ui->btn_paintBoard, SIGNAL(clicked(bool)), this, SLOT(btn_paintboard()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::currentClock(){
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");

    ui->label_current_time->setText(time_text);
}

void Widget::leaveWorkClock(){
    QTime time = QTime::currentTime();
    QTime targetTime(18,0,0);

    int secondsToTarget = time.secsTo(targetTime);

    if(secondsToTarget < 0){
        secondsToTarget += 24 * 60 * 60;
    }

    int hours = secondsToTarget / 3600;
    int minutes = (secondsToTarget % 3600) / 60;
    int seconds = secondsToTarget % 60;

    QString time_text = QString("%1 : %2 : %3")
                            .arg(hours)
                            .arg(minutes)
                            .arg(seconds);

    ui->label->setText(time_text);
    ui->label->setStyleSheet("color: red");
}

void Widget::btn_calculator(){
    calculator = new Calculator(this);
    calculator->show();

}

void Widget::btn_stopwatch(){
    stopwatch = new Stopwatch(this);
    stopwatch->show();
}

void Widget::btn_timer(){
    timer = new Timer(this);
    timer->show();
}

void Widget::btn_notepad(){
    notepad = new Notepad(this);
    notepad->show();
}

void Widget::btn_paintboard(){
    paintboard = new Paintboard(this);
    paintboard->show();
}

