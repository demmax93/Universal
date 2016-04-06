#include"QVect.h"
#include"qmatr.h"
#include<iostream>
#include<cmath>
#include<complex>
using namespace std;

QVect::QVect()
{
    dim=5;
    Xi=new complex<double> [dim];
    for(int i=0;i<dim;i++) {Xi[i]=1;}
}

QVect::QVect(int n)
{
    dim=n;
    Xi=new complex<double> [dim];
    for(int i=0;i<dim;i++){Xi[i]=0;}
}

void QVect::fillen()
{
    for(int i=0;i<dim;i++){
            Xi[i]=i+1;
    }
}

void QVect::fillenElement(int i, complex<double> x)
{
    Xi[i] = x;
}

void QVect::input(int dim)
{
    cout<<"razmernost' vectora = "<<dim<<endl;
    Xi=new complex<double> [dim];
    cout<<"Vvedite koordinati vektora"<<endl;
    for(int i=0;i<dim;i++)
        cin>>Xi[i];
}

void QVect::Show(void)
{
    cout <<"(";
    for(int i=0;i<dim;i++)
    {
        if(i==dim-1)
            cout<<Xi[i].real();
        else cout<<Xi[i].real()<<",";
    }
    cout<<")"<<endl;
}

QVect operator+(const QVect& a1,QVect a2)
{
    QVect a3;
    if(a1.dim == a2.dim)
        for(int i=0;i<a1.dim;i++)
        {
            a3.Xi[i]=a1.Xi[i]+a2.Xi[i];
        }
    else cout<<"Error";
    return a3;
 }

QVect& QVect:: operator +=(QVect a)
{
    if(dim == a.dim)
        for(int i=0;i<a.dim;i++)
        {
            Xi[i]+=a.Xi[i];
        }
    else cout<<"Error";
    return *this;
}

QVect operator -(const QVect& a1,QVect a2)
{
    QVect a3;
    if(a1.dim == a2.dim)
        for(int i=0;i<a1.dim;i++)
        {
            a3.Xi[i]=a1.Xi[i]-a2.Xi[i];
        }
    else cout<<"Error";
    return a3;
}

QVect& QVect:: operator -=(QVect a)
{
    if(dim == a.dim)
        for(int i=0;i<a.dim;i++)
        {
            Xi[i]-=a.Xi[i];
        }
    else cout<<"Error";
    return *this;
}

QVect& QVect:: operator -()
{
    for(int i=0;i<dim;i++)
        Xi[i]-=Xi[i];
    return *this;
}

QVect operator *(complex<double> X, const QVect&  a)
{
    QVect b;
    b.dim=a.dim;
    for(int i=0;i<a.dim;i++)
        {
            b.Xi[i]=a.Xi[i];
            b.Xi[i]*=X;
        }
    return b;
}

QVect& QVect:: operator *=(complex<double> X)
{
    for(int i=0;i<dim;i++)
        Xi[i]*=X;
    return *this;
}

QVect& QVect:: operator /=(complex<double> X)
{
    for(int i=0;i<dim;i++)
        Xi[i]/=X;
    return *this;
}

bool operator == (const QVect& a1,const QVect& a2)
{
    if(a1.dim==a2.dim)
        for(int i=0;i<a1.dim;i++)
        {
            return a1.Xi[i]==a2.Xi[i];
        }
    else return cout<<"Error";
}

bool operator != (const QVect& a1,const QVect& a2)
{
    if(a1.dim==a2.dim)
        for(int i=0;i<a1.dim;i++)
        {
            return a1.Xi[i]!=a2.Xi[i];
        }
    else return cout<<"Error";
}

QVect& QVect :: operator=(const QVect& a)
{
    if(dim==a.dim)
        for(int i=0;i<a.dim;i++)
            Xi[i]=a.Xi[i];
    else cout<<"Error";
    return *this;
}

QVect& QVect :: operator=(const complex<double>* a)
{
    for(int i=0;i<dim;i++)
        Xi[i]=a[i];
    return *this;
}

istream &operator>>(istream &h,QVect& a)
{
    cout<<"razmernost' vectora = "<<a.dim<<endl;
    a.Xi=new complex<double> [a.dim];
    cout<<"Vvedite koordinati vektora"<<endl;
    for(int i=0;i<a.dim;i++)
        cin>>a.Xi[i];
    return h;
}

ostream &operator<<(ostream &h,QVect& a)
{
    cout <<"(";
    for(int i=0;i<a.dim;i++)
    {
        if(i==a.dim-1) cout<<a.Xi[i];
        else cout<<a.Xi[i]<<",";
    }
    cout<<")"<<endl;
    return h;
}

complex<double>& QVect :: operator[](int i)
{
    return Xi[i];
}

complex<double> operator ,(QVect a1, QVect a2)
{
    complex<double> skol=0;
    if(a1.dim == a2.dim)
        for(int i=0;i<a1.dim;i++)
        {
            skol+=a1.Xi[i].real()*a2.Xi[i].real();
        }
    else cout<<"Error";
    return skol;
}

complex<double> QVect::modul(void)
{
    complex<double> summ=0;
    for(int i=0;i<dim;i++) summ+=pow(Xi[i],2);
    return sqrt(summ);
}

complex<double> QVect::max(void)
{
    complex<double> max=abs(Xi[0]);
    for(int i=1;i<dim;i++) if(max.real()<=abs(Xi[i].real())) max=abs(Xi[i]);
    return max;
}

complex<double> QVect::norm(void)
{
    complex<double> summ=0;
    for(int i=0;i<dim;i++) summ+=abs(Xi[i]);
    return summ;
}

void QVect::Izmen(int n)
{
    if(n>dim)
    {
        Xi=new complex<double> [n];
        for(int i=0;i<n;i++) Xi[i]=1;
        dim=n;
    }
    else {
            if(n<dim)
                dim=n;
        }
}

int QVect::Dim()
{
    return dim;
}

QMatr QVect::methodStrok()
{
    int n = sqrt(dim);
    QMatr b(n);
    for(int i=0,k=0;i<n;i++)
        for(int j=0;j<n;j++,k++)
            b.fillElement(Xi[k],i,j);

    return b;
}

QMatr QVect::methodStrokConverse()
{
    int n = sqrt(dim);
    QMatr b(n);

    for (int i = 0,k=0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++, k++)
            {
                b.fillElement(Xi[k],i,j);
            }
        }
        else
        {
            for (int j = n-1; j>=0 ; j--, k++)
            {
                b.fillElement(Xi[k],i,j);
            }
        }

    }
    return b;
}

QMatr QVect::methodSnake()
{
    int n = sqrt(dim);
    QMatr b(sqrt(dim));

    int k=0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i % 2 == 0)
            {
                b.fillElement(Xi[k],i-j,j);
                k++;
            }
            else
            {
                b.fillElement(Xi[k],j,i-j);
                k++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i % 2 == 0)
            {
                if (n % 2 == 0)
                {
                    b.fillElement(Xi[k],n-j+i,j);
                    k++;
                }
                else
                {
                    b.fillElement(Xi[k],j,n-j+i);
                    k++;
                }

            }
            else
            {
                if (n % 2 == 0)
                {
                    b.fillElement(Xi[k],j,n-j+i);
                    k++;
                }
                else
                {
                    b.fillElement(Xi[k],n-j+i,j);
                    k++;
                }
            }
        }
    }

    return b;
}

QMatr QVect::methodCycle()
{
    int n = sqrt(dim);
    QMatr b(n);
    int p = n/2;
	int k = 0;

    for(int i = 1;i <= p; i++)
    {
        for(int j = i-1; j < n-i+1; j++)
        {
            b.fillElement(Xi[k],i-1,j);
            k++;
        }
        for(int j = i; j < n-i+1; j++)
        {
            b.fillElement(Xi[k],j,n-i);
            k++;
        }
        for(int j = n-i-1; j>=i-1; --j)
        {
            b.fillElement(Xi[k],n-i,j);
            k++;
        }
        for(int j = n-i-1;j>=i;j--)
        {
            b.fillElement(Xi[k],j,i-1);
            k++;
        }
    }

    if(n%2==1) b.fillElement(Xi[n*n-1],p,p);

    return b;
}

void QVect::sort(int bi,int li)
{
    int i,j,mode;
    complex<double> temp;
    if (bi>=li) return;
    for (i=bi, j=li, mode=1; i < j; mode >0 ? j-- : i++)
    if (Xi[i].real() > Xi[j].real())
    {
        temp = Xi[i];
        Xi[i] = Xi[j];
        Xi[j]=temp;
        mode = -mode;
    }
    QVect::sort(bi,i-1);
    QVect::sort(i+1,li);
}

complex<double> QVect::min(int bi,int li)
{
    complex<double> lmin,rmin,temp;
    int centr;

    if(bi==li) return Xi[bi];

    if((bi-li)==1 || (li-bi)==1)
    {
        return Xi[bi].real() < Xi[li].real() ? Xi[bi] : Xi[li];
    }

    centr = (bi + li)/2;

    lmin = QVect::min(bi,centr);
    rmin = QVect::min(centr,li);

    return lmin.real() < rmin.real() ? lmin : rmin;
}

complex<double> QVect::max(int bi,int li)
{
    complex<double> lmax,rmax;
    int centr;

    if(bi==li) return Xi[bi];

    if((bi-li)==1 || (li-bi)==1)
    {
        return Xi[bi].real() > Xi[li].real() ? Xi[bi] : Xi[li];
    }

    centr = (bi + li)/2;

    lmax = QVect::max(bi,centr);
    rmax = QVect::max(centr,li);

    return lmax.real() > rmax.real() ? lmax : rmax;
}
