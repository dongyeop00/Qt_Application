#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>

namespace Ui {
class Calculator;
}

class Calculator : public QDialog
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

    void ProcessNum(int num);
    void ProcessOperation(char get_operation_flag);
    QString ConvertToBinary(int num);
    QString ConvertToOctal(int num);
    QString ConvertToHex(int num);

private slots:
    void btn_1();
    void btn_2();
    void btn_3();
    void btn_4();
    void btn_5();
    void btn_6();
    void btn_7();
    void btn_8();
    void btn_9();
    void btn_0();
    void btn_CE();
    void btn_C();
    void btn_back();
    void btn_Reciprocal();
    void btn_Square();
    void btn_QuareRoot();
    void btn_PlusMinus();
    void btn_Sum();
    void btn_Sub();
    void btn_Mul();
    void btn_Div();
    void btn_Equal();
    void btn_Dot();

private:
    Ui::Calculator *ui;
    char operation_flag = 0;
    char reset_mode = 0;
    char plus_minus_flag = 0;
    char dot_flag = 0;
    double first_num = 0;
};

#endif // CALCULATOR_H
