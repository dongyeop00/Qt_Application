#ifndef PAINTBOARD_H
#define PAINTBOARD_H

#include <QDialog>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>

namespace Ui {
class Paintboard;
}

class Paintboard : public QDialog
{
    Q_OBJECT

public:
    explicit Paintboard(QWidget *parent = nullptr);
    ~Paintboard();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::Paintboard *ui;
    bool drawing;
    QPoint lastPoint;
    QPen pen;
    QImage image;
};

#endif // PAINTBOARD_H
