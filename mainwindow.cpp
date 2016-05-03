#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qxoy.h"
#include "QVect.h"
#include "qmatr.h"
#include "cmath"
#include "complex"

const double PI = 3.1415926536;
int k = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    XoY1 = new QXoY(ui->label);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::The_Slot(){//функция которая запускается при нажатии на кнопку в интрефейсе "Подсчитать и нарисовать"
    QTableWidgetItem* ptwi = 0;
    QString a = ui->lineEdit->text();//списываем значение с формы на интерфейсе
    int n = a.toInt();
    ui->tableWidget_2->setRowCount(n);
    QMatr e(n);
    QVect y(n);
    QVect c(n);

    e.funcexp();

    QString temp = 0;
    complex<double> tempComp;
    for(int i = 0; i < n; i++){
        temp = ui->tableWidget->item(i, 0)->text();
        tempComp.real(temp.toDouble());
        temp = ui->tableWidget->item(i, 1)->text();
        tempComp.imag(temp.toDouble());
        y.fillenElement(i,tempComp);
    }

    GaussSol(e,c,y);

    for(int i = 0; i < n; i++){
        ptwi = new QTableWidgetItem(QString("%1").arg(c.Xi[i].real(), 0, 'f'));
        ui->tableWidget_2->setItem(i, 0, ptwi);
        ptwi = new QTableWidgetItem(QString("%1").arg(c.Xi[i].imag(), 0, 'f'));
        ui->tableWidget_2->setItem(i, 1, ptwi);
    }
}

void MainWindow::The_Slot2(){
    k=0;
    QString a = ui->lineEdit->text();
    int n = a.toInt();
    ui->tableWidget->setRowCount(n);
    QTableWidgetItem* ptwi = 0;
    complex<double> tempComp;
    for(int i = 0; i < n; i++){
        tempComp.real(rand()/10000.0000);
        tempComp.imag(rand()/10000.0000);
        ptwi = new QTableWidgetItem(QString("%1").arg(tempComp.real(), 0, 'f'));
        ui->tableWidget->setItem(i, 0, ptwi);
        ptwi = new QTableWidgetItem(QString("%1").arg(tempComp.imag(), 0, 'f'));
        ui->tableWidget->setItem(i, 1, ptwi);
    }
}

void MainWindow::The_Slot6(){
    k=0;
    QString a = ui->lineEdit->text();
    int n = a.toInt();
    ui->tableWidget->setRowCount(n);
    QTableWidgetItem* ptwi = 0;
    double temp = -(n/10)/2.0;
    for(int i = 0; i < n; i++){
        ptwi = new QTableWidgetItem(QString("%1").arg(temp, 0, 'f'));
        ui->tableWidget->setItem(i, 0, ptwi);
        ptwi = new QTableWidgetItem(QString("%1").arg(sin(temp), 0, 'f'));
        ui->tableWidget->setItem(i, 1, ptwi);
        temp+=0.1;
    }
}

void MainWindow::The_Slot3(){

    XoY1->InitXoY();//создаем оси координат для графика
    QString a = ui->lineEdit->text();//списываем значение с формы на интерфейсе
    int n = a.toInt();
    QString temp = 0;
    QMatr e(n);
    QVect c(n);
    QVect d(n);
    e.funcexp();
    for(int i = 0; i < n; i++){
        temp = ui->tableWidget_2->item(i, 0)->text();
        c[i].real(temp.toDouble());
        temp = ui->tableWidget_2->item(i, 1)->text();
        c[i].imag(temp.toDouble());
    }
    d = e*c;
    double *x, *yn;
    x = new double[n];
    yn = new double[n];

    for(int i = 0; i < n; i++){
        temp = ui->tableWidget->item(i, 0)->text();
        x[i] = temp.toDouble();
        temp = ui->tableWidget->item(i, 1)->text();
        yn[i] = temp.toDouble();
    }

    XoY1->ShowFnmas(n,x,yn,Qt::red);//рисуем сам график

    for(int i = 0; i < n; i++){
        x[i] = d[i].real();
        yn[i] = d[i].imag();
    }

    XoY1->ShowFnmas(n,x,yn,Qt::black);//рисуем сам график
}

void MainWindow::The_Slot4(){
    QString a = ui->lineEdit->text();//списываем значение с формы на интерфейсе
    int n = a.toInt();
    QTableWidgetItem* ptwi = 0;
    complex<double> tempComp = 0;
    if(k <= n){
        ptwi = new QTableWidgetItem(QString("%1").arg(tempComp.real(), 0, 'f'));
        ui->tableWidget_2->setItem(k, 0, ptwi);
        ptwi = new QTableWidgetItem(QString("%1").arg(tempComp.real(), 0, 'f'));
        ui->tableWidget_2->setItem(k, 1, ptwi);
        k++;
        The_Slot3();
    }
}

void MainWindow::The_Slot5(){
    if(k >= 0) {
        k--;
        QTableWidgetItem* ptwi = 0;
        QString a = ui->lineEdit->text();//списываем значение с формы на интерфейсе
        int n = a.toInt();
        ui->tableWidget_2->setRowCount(n);
        QMatr e(n);
        QVect y(n);
        QVect c(n);

        e.funcexp();

        QString temp = 0;
        complex<double> tempComp;
        for(int i = 0; i < n; i++){
            temp = ui->tableWidget->item(i, 0)->text();
            tempComp.real(temp.toDouble());
            temp = ui->tableWidget->item(i, 1)->text();
            tempComp.imag(temp.toDouble());
            y.fillenElement(i,tempComp);
        }

        GaussSol(e,c,y);

        tempComp = 0;

        for(int i = 0; i < n; i++){
            if(i < k){
                ptwi = new QTableWidgetItem(QString("%1").arg(tempComp.real(), 0, 'f'));
                ui->tableWidget_2->setItem(i, 0, ptwi);
                ptwi = new QTableWidgetItem(QString("%1").arg(tempComp.imag(), 0, 'f'));
                ui->tableWidget_2->setItem(i, 1, ptwi);
            } else{
                ptwi = new QTableWidgetItem(QString("%1").arg(c.Xi[i].real(), 0, 'f'));
                ui->tableWidget_2->setItem(i, 0, ptwi);
                ptwi = new QTableWidgetItem(QString("%1").arg(c.Xi[i].imag(), 0, 'f'));
                ui->tableWidget_2->setItem(i, 1, ptwi);
            }
        }

        The_Slot3();
    }
}

