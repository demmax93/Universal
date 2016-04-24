#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "qxoy.h"
//это класс для интерфейса программы,т.е для рисования графика, для вывода таблицы значений и т.п.
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QXoY *XoY1;
    ~MainWindow();
    Ui::MainWindow *ui;

public slots:
    void The_Slot();
    void The_Slot2();

private:

};

#endif // MAINWINDOW_H
