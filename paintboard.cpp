#include "paintboard.h"
#include "ui_paintboard.h"

Paintboard::Paintboard(QWidget *parent) :
    QDialog(parent),
    drawing(false),
    ui(new Ui::Paintboard)
{
    ui->setupUi(this);
    pen.setColor(Qt::black);
    pen.setWidth(3);
    image = QImage(size(), QImage::Format_ARGB32);
    image.fill(Qt::white);
}

Paintboard::~Paintboard()
{
    delete ui;
}

void Paintboard::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect rect = event->rect();
    painter.drawImage(rect, image, rect);
}

void Paintboard::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawing = true;
        lastPoint = event->pos();
    }
}

void Paintboard::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && drawing) {
        QPainter painter(&image);
        painter.setPen(pen);
        painter.drawLine(lastPoint, event->pos());
        lastPoint = event->pos();
        update();
    }
}

void Paintboard::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && drawing) {
        drawing = false;
    }
}
