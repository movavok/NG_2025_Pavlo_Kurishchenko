#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLCDNumber>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void changeOperation();
    void changeNumber();

    void on_b_equal_clicked();

    void on_b_plus_clicked();
    void on_b_min_clicked();
    void on_b_div_clicked();
    void on_b_mult_clicked();
    void on_b_pow_clicked();
    void on_b_root_clicked();

    void on_b_1_clicked();
    void on_b_2_clicked();
    void on_b_3_clicked();
    void on_b_4_clicked();
    void on_b_5_clicked();
    void on_b_6_clicked();
    void on_b_7_clicked();
    void on_b_8_clicked();
    void on_b_9_clicked();
    void on_b_0_clicked();

private:
    Ui::MainWindow *ui;
    char operation = '+';
    char workNumber = '1';
    int number = 0;
    int firstNumber = 0;
    int secondNumber = 0;
    short lengthNum = 0;
    double result = 0;
};
#endif // MAINWINDOW_H
