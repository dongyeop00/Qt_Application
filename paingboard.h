#ifndef PAINGBOARD_H
#define PAINGBOARD_H

#include <QDialog>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>

namespace Ui {
class Paingboard;
}

class Paingboard : public QDialog
{
    Q_OBJECT

public:
    explicit Paingboard(QWidget *parent = nullptr);
    ~Paingboard();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::Paingboard *ui;
    bool drawing;
    QPoint lastPoint;
    QPen pen;
    QImage image;
};

#endif // PAINGBOARD_H
