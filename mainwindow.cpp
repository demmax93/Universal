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
    for(int i = 0; i < n; i++){
        temp = ui->tableWidget->item(i, 0)->text();
        y.fillenElement(i,temp.toDouble());
    }

    GaussSol(e,c,y);

    QVect d(n);

    d = e*c;

    for(int i = 0; i < n; i++){
        ptwi = new QTableWidgetItem(QString("%1").arg(d.Xi[i].real(), 0, 'f'));
        ui->tableWidget_2->setItem(i, 0, ptwi);
    }

    double *x, *yn;
    x = new double[n];
    yn = new double[n];
    for(int i = 0; i < n; i++){
        x[i] = d.Xi[i].real();
        yn[i] = d.Xi[i].imag();
    }

    XoY1->InitXoY();//создаем оси координат для графика
    XoY1->ShowFnmas(n,x,yn);//рисуем сам график
}

void MainWindow::The_Slot2(){
    QString a = ui->lineEdit->text();
    int n = a.toInt();
    ui->tableWidget->setRowCount(n);
}

