#include "paintboard.h"
#include "ui_paintboard.h"

Paintboard::Paintboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Paintboard)
{
    ui->setupUi(this);

    pen.setColor(Qt::black);
    pen.setWidth(3);

    image = QImage(size(), QImage::Format_ARGB32);
    image.fill(Qt::white);

    menuBar = new QMenuBar(this);
    menuBar->setFixedWidth(800);
    menu = new QMenu("도구");
    QAction *penAction = new QAction("펜 굵기");
    menu->addAction(penAction);
    menuBar->addMenu(menu);

    ui->gridLayout->setSizeConstraint(QLayout::SetFixedSize);
    ui->gridLayout_2->setSizeConstraint(QLayout::SetFixedSize);
    ui->verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
    ui->btn_text->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->btn_fill->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->btn_color->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->btn_pen->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->btn_eraser->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->btn_brush->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->btn_size->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->btn_circle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->btn_square->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->btn_triangle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    connect(ui->btn_size, SIGNAL(clicked(bool)), this, SLOT(changePenWidth()));

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

void Paintboard::changePenWidth(){

    QDialog dialog(this);
    dialog.setWindowTitle("펜 굵기 설정");

    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    // QSlider 객체를 생성합니다.
    QSlider *slider = new QSlider(Qt::Horizontal, &dialog);
    slider->setRange(1, 50);  // 펜 굵기의 범위를 설정합니다.
    slider->setValue(pen.width());  // 현재 펜 굵기로 슬라이더의 값을 설정합니다.
    layout->addWidget(slider);

    // 현재 슬라이더의 값을 표시할 QLabel을 생성합니다.
    QLabel *label = new QLabel(QString::number(slider->value()), &dialog);
    layout->addWidget(label);

    // 슬라이더의 값이 변경될 때 QLabel의 텍스트를 업데이트하는 슬롯을 연결합니다.
    connect(slider, &QSlider::valueChanged, [label](int value) {
        label->setText(QString::number(value));
    });

    QPushButton *okButton = new QPushButton("OK", &dialog);
    layout->addWidget(okButton);

    connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);

    if (dialog.exec() == QDialog::Accepted) {
        int newWidth = slider->value();
        pen.setWidth(newWidth);
    }
}
