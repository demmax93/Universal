#ifndef VEKTOR_H
#define VEKTOR_H
#include<iostream>
#include<complex>
using namespace std;

class QMatr;

class QVect
{
    int dim;
    complex<double> *Xi;
    public:
    friend class QMatr;
    QVect();
    QVect(int);
    void fillen();
    friend QVect operator +(const QVect&,QVect);
    QVect& operator+=(QVect);
    friend QVect operator -(const QVect&,QVect);
    QVect& operator-=(QVect);
    QVect& operator-();
    friend QVect operator*(complex<double>, const QVect&);
    QVect& operator*=(double);
    QVect& operator/=(double);
    friend bool operator==(const QVect&, const QVect&);
    friend bool operator!=(const QVect&, const QVect&);
    QVect& operator=(const QVect&);
    QVect& operator=(const double*);
    double& operator[](int);
    friend complex<double> operator,(QVect, QVect);
    friend istream &operator>>(istream &,QVect &);
    friend ostream &operator<<(ostream &,QVect &);
    double modul(void);
    double max(void);
    double norm(void);
    void Show(void);
    void input(int dim);
    void Izmen(int);
    int Dim();
    void sort(int,int);
    double min(int,int);
    double max(int,int);
    QMatr methodStrok();
    QMatr methodStrokConverse();
    QMatr methodSnake();
    QMatr methodCycle();
};
#endif // VEKTOR_H
