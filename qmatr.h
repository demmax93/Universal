#ifndef QMATR_H
#define QMATR_H
#include <iostream>
#include <complex>
using namespace std;

class QVect;

class QMatr
{
    int dim;
    complex<double> **Xi;
    public:
    friend class QVect;
    QMatr();
    QMatr(int);
    void fillen();
    void fillElement(complex<double>,int,int);
    friend QMatr operator +(const QMatr&,QMatr);
    QMatr& operator+=(QMatr);
    friend QMatr operator -(const QMatr&,QMatr);
    QMatr& operator-=(QMatr);
    QMatr& operator-();
    friend QMatr operator*(complex<double>, const QMatr&);
    friend QMatr operator*(const QMatr&, const QMatr&);
    complex<double>* operator[](int);
    complex<double>* col(int);
    complex<double>* diag();
    QMatr transonir(QMatr);
    void transponir(int);
    QMatr minor(int,int);
    friend complex<double> det(QMatr &);
    friend QMatr obr(QMatr &);
    friend QMatr Adj(QMatr &);
    QMatr& operator=(const QMatr&);
    QMatr& operator*=(complex<double>);
    QMatr& operator/=(complex<double>);
    void show(void);
    void fastsort(int,int,int);
    void sort(int,int);
    complex<double> min(int,int);
    complex<double> max(int,int);
    friend istream& operator>>(istream &,const QMatr &);
    friend ostream& operator<<(ostream &,const QMatr &);
    QVect methodStrok();
    QVect methodStrokConverse();
    QVect methodSnake();
    QVect methodCycle();
    void swap_r(int , int);//������ ������� � ���������� ������ �������
    void swap_c(int , int);//������ ������ � ���������� ������� �������
    void nne(int);//��� ���� ����������������
    void funcexp();
    friend void GaussSol(QMatr &, QVect &, QVect &);//����� �����
    void getLU(QMatr &,QMatr &);//�� ����������
    QMatr proisv(QMatr&,QMatr&);//������� ��������� ������� �� �������
    void Jacobi (complex<double>, QVect, QVect);//����� �������� ��������
    bool isSimmetrial(QMatr);//������� ����������� ������� �� ��������������
    QVect wrachenie(QMatr,complex<double>);//����� ����� ��������
};

#endif // QMATR_H
