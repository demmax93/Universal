#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qxoy.h"
#include "QVect.h"
#include "qmatr.h"
#include "cmath"
#include "complex"

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
    QString a = ui->lineEdit->text();
    int n = a.toInt();
    ui->tableWidget->setRowCount(n);
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

