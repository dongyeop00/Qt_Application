#ifndef PAINTBOARD_H
#define PAINTBOARD_H

#include <QDialog>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QLabel>

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
    bool drawing = false;
    QPoint lastPoint;
    QPen pen;
    QImage image;
    QMenuBar *menuBar;
    QMenu *menu;

private slots:
    void changePenWidth();
};

#endif // PAINTBOARD_H
