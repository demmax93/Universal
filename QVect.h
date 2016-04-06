#ifndef VEKTOR_H
#define VEKTOR_H
#include<iostream>
#include<complex>
using namespace std;

class QMatr;

class QVect
{
    public:
    int dim;
    complex<double> *Xi;
    friend class QMatr;
    QVect();
    QVect(int);
    void fillen();
    void fillenElement(int, complex<double>);
    friend QVect operator +(const QVect&,QVect);
    QVect& operator+=(QVect);
    friend QVect operator -(const QVect&,QVect);
    QVect& operator-=(QVect);
    QVect& operator-();
    friend QVect operator*(complex<double>, const QVect&);
    QVect& operator*=(complex<double>);
    QVect& operator/=(complex<double>);
    friend bool operator==(const QVect&, const QVect&);
    friend bool operator!=(const QVect&, const QVect&);
    QVect& operator=(const QVect&);
    QVect& operator=(const complex<double>*);
    complex<double>& operator[](int);
    friend complex<double> operator,(QVect, QVect);
    friend istream &operator>>(istream &,QVect &);
    friend ostream &operator<<(ostream &,QVect &);
    complex<double> modul(void);
    complex<double> max(void);
    complex<double> norm(void);
    void Show(void);
    void input(int dim);
    void Izmen(int);
    int Dim();
    void sort(int,int);
    complex<double> min(int,int);
    complex<double> max(int,int);
    QMatr methodStrok();
    QMatr methodStrokConverse();
    QMatr methodSnake();
    QMatr methodCycle();
};
#endif // VEKTOR_H
