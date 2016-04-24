/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1271, 786);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 0, 701, 401));
        label->setContextMenuPolicy(Qt::NoContextMenu);
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 90, 111, 291));
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(1);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(960, 510, 171, 51));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(220, 10, 71, 20));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 10, 211, 31));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 50, 84, 23));
        tableWidget_2 = new QTableWidget(centralWidget);
        if (tableWidget_2->columnCount() < 1)
            tableWidget_2->setColumnCount(1);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(150, 90, 111, 291));
        tableWidget_2->setRowCount(0);
        tableWidget_2->setColumnCount(1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1271, 20));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(MainWindow, SIGNAL(iconSizeChanged(QSize)), pushButton_2, SLOT(click()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(The_Slot()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), MainWindow, SLOT(The_Slot2()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "QXoY", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \320\270 \320\275\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\260\320\267\320\274\320\265\321\200\320\275\320\276\321\201\321\202\321\214 \320\262\320\265\320\272\321\202\320\276\321\200\320\260 : n=</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\321\201\321\202\320\270 \320\262\320\265\320\272\321\202\320\276\321\200", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\240\320\265\321\210\320\265\320\275\320\270\320\265 \320\267\320\260\320\264\320\260\321\207\320\270 \320\232\320\276\321\210\320\270 \320\274\320\265\321\202\320\276\320\264\320\276\320\274 \320\255\320\271\320\273\320\265\321\200\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
