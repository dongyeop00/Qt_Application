#include "timer.h"
#include "ui_timer.h"

#include <QMessageBox>

Timer::Timer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Timer),
    timer(new QTimer(this))
{
    ui->setupUi(this);

    connect(ui->btn_start, SIGNAL(clicked(bool)), this, SLOT(btn_start()));
    connect(ui->btn_stop, SIGNAL(clicked(bool)), this, SLOT(btn_stop()));
    connect(ui->btn_reset, SIGNAL(clicked(bool)), this, SLOT(btn_reset()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));

    ui->btn_stop->setEnabled(false);
}

Timer::~Timer()
{
    delete ui;
}

void Timer::btn_start()
{
    ui->btn_start->setEnabled(false);
    ui->btn_stop->setEnabled(true);

    int hour = ui->hourBox->value();
    int min = ui->MinBox->value();
    int second = ui->SecBox->value();

    totalSeconds = hour*3600 + min*60 + second;

    if(!timer->isActive()){
        timer->start(1000);
    }
}

void Timer::btn_stop()
{
    ui->btn_start->setEnabled(true);
    ui->btn_stop->setEnabled(false);

    if(timer->isActive()){
        timer->stop();
    }
}

void Timer::btn_reset()
{
    ui->hourBox->setValue(0);
    ui->MinBox->setValue(0);
    ui->SecBox->setValue(0);
    ui->btn_start->setEnabled(true);
    ui->btn_stop->setEnabled(false);
    totalSeconds=0;
}

void Timer::updateTimer()
{
    if(totalSeconds > 0){
        totalSeconds--;
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;

        ui->hourBox->setValue(hours);
        ui->MinBox->setValue(minutes);
        ui->SecBox->setValue(seconds);
    } else {
        timer->stop();
        QMessageBox::information(this, "Timer", "Time's up!");
    }
}
