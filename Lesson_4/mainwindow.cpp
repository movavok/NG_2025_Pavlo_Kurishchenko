#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeOperation()
{
    workNumber = '2';
    QString htmlOper = QString(
                       "<div align='center'>"
                       "<span style='font-weight:bold; font-size:28pt;'>%1</span>"
                       "</div>"
                       ).arg(QChar(operation));

    ui->te_operation->setText(htmlOper);
}

void MainWindow::changeNumber()
{
    if (workNumber == '1' && lengthNum < 5) {
        firstNumber = firstNumber * 10 + number;
        lengthNum++;
        ui->lcd_firstnum->display(firstNumber);
    }
    else if (workNumber == '2' && lengthNum < 5){
        secondNumber = secondNumber * 10 + number;
        lengthNum++;
        ui->lcd_secondnum->display(secondNumber);
    }
}

void MainWindow::on_b_equal_clicked()
{
    switch (operation) {
    case '+': result = firstNumber + secondNumber; break;
    case '-': result = firstNumber - secondNumber; break;
    case '/': result = firstNumber / secondNumber; break;
    case '*': result = firstNumber * secondNumber; break;
    case '^': result = pow(firstNumber, secondNumber); break;
    case 'v': result = pow(firstNumber, 1.0 / secondNumber); break;
    default: break;
    }
    ui->lcd_result->display(result);
    workNumber = '1';
    firstNumber = 0;
    secondNumber = 0;
    lengthNum = 0;
}

void MainWindow::on_b_plus_clicked(){ operation = '+'; changeOperation();}
void MainWindow::on_b_min_clicked() { operation = '-'; changeOperation();}
void MainWindow::on_b_div_clicked() { operation = '/'; changeOperation();}
void MainWindow::on_b_mult_clicked(){ operation = '*'; changeOperation();}
void MainWindow::on_b_pow_clicked() { operation = '^'; changeOperation();}
void MainWindow::on_b_root_clicked(){ operation = 'v'; changeOperation();}

void MainWindow::on_b_1_clicked(){ number = 1; changeNumber();}
void MainWindow::on_b_2_clicked(){ number = 2; changeNumber();}
void MainWindow::on_b_3_clicked(){ number = 3; changeNumber();}
void MainWindow::on_b_4_clicked(){ number = 4; changeNumber();}
void MainWindow::on_b_5_clicked(){ number = 5; changeNumber();}
void MainWindow::on_b_6_clicked(){ number = 6; changeNumber();}
void MainWindow::on_b_7_clicked(){ number = 7; changeNumber();}
void MainWindow::on_b_8_clicked(){ number = 8; changeNumber();}
void MainWindow::on_b_9_clicked(){ number = 9; changeNumber();}
void MainWindow::on_b_0_clicked(){ number = 0; changeNumber();}

