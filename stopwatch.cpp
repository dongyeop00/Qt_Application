#include "stopwatch.h"
#include "ui_stopwatch.h"

Stopwatch::Stopwatch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stopwatch),
    timer(new QTimer(this))
{
    ui->setupUi(this);

    connect(ui->btn_start, &QPushButton::clicked, this, &Stopwatch::btn_start);
    connect(ui->btn_stop, &QPushButton::clicked, this, &Stopwatch::btn_stop);
    connect(ui->btn_reset, &QPushButton::clicked, this, &Stopwatch::btn_reset);
    connect(ui->btn_lap, &QPushButton::clicked, this, &Stopwatch::btn_lap);
    connect(timer, &QTimer::timeout, this, &Stopwatch::update_display);

    ui->watch->setText("00:00:00.000");
    ui->btn_stop->setEnabled(false);
}

Stopwatch::~Stopwatch()
{
    delete ui;
}

void Stopwatch::btn_start()
{
    ui->btn_start->setEnabled(false);
    ui->btn_stop->setEnabled(true);

    if (!timer->isActive()) {
        timer->start(10); // 10 ms 간격
        startTime = QTime::currentTime(); // 시작 시간 기록
    }
}

void Stopwatch::btn_stop()
{
    ui->btn_start->setEnabled(true);
    ui->btn_stop->setEnabled(false);

    if (timer->isActive()) {
        timer->stop();
        elapsedTime += startTime.msecsTo(QTime::currentTime()); // 현재 시간과 시작 시간의 차이를 추가
    }
}

void Stopwatch::btn_reset()
{
    ui->btn_start->setEnabled(true);
    ui->btn_stop->setEnabled(false);

    timer->stop();
    elapsedTime = 0;
    ui->watch->setText("00:00:00.000");
    ui->listWidget->clear();
}

void Stopwatch::btn_lap()
{
    ui->listWidget->addItem(ui->watch->text());
}

void Stopwatch::update_display()
{
    int totalElapsed = elapsedTime + startTime.msecsTo(QTime::currentTime()); // 총 경과 시간 계산
    int milliseconds = totalElapsed % 1000;
    int seconds = (totalElapsed / 1000) % 60;
    int minutes = (totalElapsed / (1000 * 60)) % 60;
    int hours = (totalElapsed / (1000 * 60 * 60)) % 24;

    ui->watch->setText(QString("%1:%2:%3.%4")
                            .arg(hours, 2, 10, QChar('0'))
                            .arg(minutes, 2, 10, QChar('0'))
                            .arg(seconds, 2, 10, QChar('0'))
                            .arg(milliseconds, 3, 10, QChar('0')));
}
