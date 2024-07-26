#include "paingboard.h"
#include "ui_paingboard.h"

Paingboard::Paingboard(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::Paingboard)
{
    ui->setupUi(this);
    pen.setColor(Qt::black);
    pen.setWidth(3);
    image = QImage(size(), QImage::Format_ARGB32);
    image.fill(Qt::white);
}

Paingboard::~Paingboard()
{
    delete ui;
}

void Paingboard::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect rect = event->rect();
    painter.drawImage(rect, image, rect);
}

void Paingboard::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawing = true;
        lastPoint = event->pos();
    }
}

void Paingboard::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && drawing) {
        QPainter painter(&image);
        painter.setPen(pen);
        painter.drawLine(lastPoint, event->pos());
        lastPoint = event->pos();
        update();
    }
}

void Paingboard::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && drawing) {
        drawing = false;
    }
}
