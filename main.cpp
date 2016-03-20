#include "iostream"
#include "QVect.h"
#include "qmatr.h"
#include "cmath"
#include "complex"

using namespace std;

int main()
{
    int n = 5;
    QMatr e(n);
    QVect y(n);
    QVect c(n);

    e.funcexp();
    cout<<e<<endl;

    y.fillen();

    cout<<y<<endl;

    GaussSol(e,c,y);

    cout<<c<<endl;

    complex<double> i (0,1);

    cout<<exp(i);


    return 0;
}
