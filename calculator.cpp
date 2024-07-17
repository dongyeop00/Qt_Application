#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    ui->current->setText("0");
    ui->current->setAlignment(Qt::AlignRight);
    ui->current->setAlignment(Qt::AlignBottom);

    connect(ui->btn_one, SIGNAL(clicked(bool)), this, SLOT(btn_1()));
    connect(ui->btn_two, SIGNAL(clicked(bool)), this, SLOT(btn_2()));
    connect(ui->btn_three, SIGNAL(clicked(bool)), this, SLOT(btn_3()));
    connect(ui->btn_four, SIGNAL(clicked(bool)), this, SLOT(btn_4()));
    connect(ui->btn_five, SIGNAL(clicked(bool)), this, SLOT(btn_5()));
    connect(ui->btn_six, SIGNAL(clicked(bool)), this, SLOT(btn_6()));
    connect(ui->btn_seven, SIGNAL(clicked(bool)), this, SLOT(btn_7()));
    connect(ui->btn_eight, SIGNAL(clicked(bool)), this, SLOT(btn_8()));
    connect(ui->btn_nine, SIGNAL(clicked(bool)), this, SLOT(btn_9()));
    connect(ui->btn_zero, SIGNAL(clicked(bool)), this, SLOT(btn_0()));
    connect(ui->btn_CE, SIGNAL(clicked(bool)), this, SLOT(btn_CE()));
    connect(ui->btn_C, SIGNAL(clicked(bool)), this, SLOT(btn_C()));
    connect(ui->btn_back, SIGNAL(clicked(bool)), this, SLOT(btn_back()));
    connect(ui->btn_reciprocal, SIGNAL(clicked(bool)), this, SLOT(btn_Reciprocal()));
    connect(ui->btn_square, SIGNAL(clicked(bool)), this, SLOT(btn_Square()));
    connect(ui->btn_quareRoot, SIGNAL(clicked(bool)), this, SLOT(btn_QuareRoot()));
    connect(ui->btn_plusminus, SIGNAL(clicked(bool)), this, SLOT(btn_PlusMinus()));
    connect(ui->btn_plus, SIGNAL(clicked(bool)), this, SLOT(btn_Sum()));
    connect(ui->btn_mul, SIGNAL(clicked(bool)), this, SLOT(btn_Mul()));
    connect(ui->btn_sub, SIGNAL(clicked(bool)), this, SLOT(btn_Sub()));
    connect(ui->btn_div, SIGNAL(clicked(bool)), this, SLOT(btn_Div()));
    connect(ui->btn_equal, SIGNAL(clicked(bool)), this, SLOT(btn_Equal()));
    connect(ui->btn_dot, SIGNAL(clicked(bool)), this, SLOT(btn_Dot()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::ProcessNum(int num)
{
    QString currentText = ui->current->text();

    if (!reset_mode) {
        if(currentText == "0"){
            ui->current->setText(QString::number(num));
        }else{
            ui->current->setText(currentText + QString::number(num));
        }
    } else {  // reset_mode == 0
        reset_mode = 0;
        ui->current->setText(QString::number(num));
    }

    int value = ui->current->text().toInt();

    ui->binEdit->setText(ConvertToBinary(value));
    ui->octEdit->setText(ConvertToOctal(value));
    ui->hexEdit->setText(ConvertToHex(value));
}

void Calculator::ProcessOperation(char get_operation_flag)
{
    operation_flag = get_operation_flag;
    reset_mode = 1;
    first_num = ui->current->text().toDouble();

    switch(operation_flag){
    case 1:
        ui->process->setText(QString::number(first_num) + " + ");
        break;
    case 2:
        ui->process->setText(QString::number(first_num) + " - ");
        break;
    case 3:
        ui->process->setText(QString::number(first_num) + " * ");
        break;
    case 4:
        ui->process->setText(QString::number(first_num) + " % ");
        break;
    }

}

// Decimal to Binary
QString Calculator::ConvertToBinary(int value)
{
    QString binaryString = QString::number(value, 2);

    int padding = 4 - (binaryString.length() % 4);

    if (padding != 4) {
        binaryString = QString(padding, '0') + binaryString;
    }

    for (int i = 4; i < binaryString.length(); i += 5) {
        binaryString.insert(i, ' ');
    }

    return binaryString;
}

// Decimal to Octal
QString Calculator::ConvertToOctal(int value)
{
    return QString::number(value, 8);
}

// Decimal to Hex
QString Calculator::ConvertToHex(int value)
{
    return QString::number(value, 16).toUpper();
}

void Calculator::btn_1()
{
    ProcessNum(1);
}

void Calculator::btn_2()
{
    ProcessNum(2);
}

void Calculator::btn_3()
{
    ProcessNum(3);
}

void Calculator::btn_4()
{
    ProcessNum(4);
}

void Calculator::btn_5()
{
    ProcessNum(5);
}

void Calculator::btn_6()
{
    ProcessNum(6);
}

void Calculator::btn_7()
{
    ProcessNum(7);
}

void Calculator::btn_8()
{
    ProcessNum(8);
}

void Calculator::btn_9()
{
    ProcessNum(9);
}

void Calculator::btn_0()
{
    ProcessNum(0);
}

void Calculator::btn_CE()
{
    operation_flag = 0;
    reset_mode = 0;
    plus_minus_flag = 0;
    dot_flag = 0;
    first_num = 0;
    ui->current->setText("0");
    ui->process->setText("");
    ui->binEdit->setText("");
    ui->octEdit->setText("");
    ui->hexEdit->setText("");
}

void Calculator::btn_C()
{
    ui->current->setText("0");
    ui->binEdit->setText("");
    ui->octEdit->setText("");
    ui->hexEdit->setText("");
}

void Calculator::btn_back()
{
    int num = ui->current->text().toInt() / 10;
    ui->current->setText(QString::number(num));

    int value = ui->current->text().toInt();
    ui->binEdit->setText(ConvertToBinary(value));
    ui->octEdit->setText(ConvertToOctal(value));
    ui->hexEdit->setText(ConvertToHex(value));
}

void Calculator::btn_Reciprocal()
{
    double num = 1.0 / ui->current->text().toDouble();
    ui->current->setText(QString::number(num,'f',5));
}

void Calculator::btn_Square()
{
    double num = ui->current->text().toDouble();
    ui->current->setText(QString::number(num*num));
}

void Calculator::btn_QuareRoot()
{
    double num = ui->current->text().toDouble();
    double root = 1.0;

    for(int i=0; i<100; i++){
        root = 0.5 * (root + num/root);
    }

    ui->current->setText(QString::number(root));
}

void Calculator::btn_PlusMinus()
{
    double num = ui->current->text().toDouble();
    if(!plus_minus_flag){
        num = -num;
        ui->current->setText(QString::number(num));
    }else{
        num = +num;
        ui->current->setText(QString::number(num));
    }
}

void Calculator::btn_Sum()
{
    ProcessOperation(1);
}

void Calculator::btn_Sub()
{
    ProcessOperation(2);
}

void Calculator::btn_Mul()
{
    ProcessOperation(3);
}

void Calculator::btn_Div()
{
    ProcessOperation(4);
}

void Calculator::btn_Equal()
{
    double second_num = ui->current->text().toDouble();
    double result = 0;
    QString operation;

    switch(operation_flag){
    case 1: // add
        result = first_num + second_num;
        operation = QString(" + ");
        break;
    case 2: // sub
        result = first_num - second_num;
        operation = QString(" - ");
        break;
    case 3: // mul
        result = first_num * second_num;
        operation = QString(" * ");
        break;
    case 4: // div
        result = first_num / second_num;
        operation = QString(" % ");
        break;
    }

    ui->current->setText(QString::number(result));
    ui->process->setText(QString::number(first_num) + operation + QString::number(second_num) + " = ");

    int value = ui->current->text().toInt();
    ui->binEdit->setText(ConvertToBinary(value));
    ui->octEdit->setText(ConvertToOctal(value));
    ui->hexEdit->setText(ConvertToHex(value));

    reset_mode = 1;
}

void Calculator::btn_Dot()
{
    QString current = ui->current->text();

    dot_flag = 1;

    if(!current.contains('.')){
        ui->current->setText(current + ".");
    }
}





