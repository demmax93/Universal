#include<iostream>
#include<cmath>
#include"qmatr.h"
#include"QVect.h"
#include"complex"

using namespace std;

const double PI = 3.1415926536;

QMatr::QMatr()
{
    dim=5;
    Xi=new complex<double>*[dim];
    for(int i=0;i<dim;i++) Xi[i]=new complex<double> [dim];
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
        {
            if(i==j)
            {
                Xi[i][i]=1;
            }
            else
            {
                Xi[i][j]=0;
            }
        }
}

QMatr::QMatr(int n)
{
    dim=n;
    Xi=new complex<double>*[dim];
    for(int i=0;i<dim;i++) Xi[i]=new complex<double> [dim];
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            {
                Xi[i][j]=0;
            }
}

void QMatr::fillen()
{
    for(int i=0,k=1;i<dim;i++)
        for(int j=0;j<dim;j++,k++)
            {Xi[i][j]=k;}

}

void QMatr::fillElement(complex<double> b,int i,int j)
{
    Xi[i][j]=b;
}

void QMatr :: show(void)
{
    for(int i=0;i<dim;i++,cout<<endl)
        for(int j=0;j<dim;j++)
        {cout<<Xi[i][j].real()<<"\t";}
}

istream& operator>>(istream &h,const QMatr& a)
{   cout<<"razmernost' matrix = "<<a.dim<<"*"<<a.dim<<endl;
    cout<<"Vvedite koordinati matrix"<<endl;
    int k=1;
    for(int i=0;i<a.dim;i++)
        for(int j=0;j<a.dim;j++,k++)
            a.Xi[i][j]=k;
    return h;}

ostream& operator<<(ostream &h,const QMatr& a)
{for(int i=0;i<a.dim;i++,cout<<endl)
        for(int j=0;j<a.dim;j++)
        {cout<<a.Xi[i][j].real()<<"\t";}
 return h;}

QMatr operator+(const QMatr& a1,QMatr a2)
{QMatr a3;
 if(a1.dim == a2.dim)
     for(int i=0;i<a1.dim;i++)
         for(int j=0;j<a1.dim;j++)
         {a3.Xi[i][j]=a1.Xi[i][j]+a2.Xi[i][j];}
     else cout<<"Error";
 return a3;}

QMatr& QMatr:: operator +=(QMatr a)
{if(dim == a.dim)
        for(int i=0;i<a.dim;i++)
            for(int j=0;j<a.dim;j++)
            {Xi[i][j]+=a.Xi[i][j];}
     else cout<<"Error";
 return *this;}

QMatr operator-(const QMatr& a1,QMatr a2)
{QMatr a3;
 if(a1.dim == a2.dim)
     for(int i=0;i<a1.dim;i++)
         for(int j=0;j<a1.dim;j++)
         {a3.Xi[i][j]=a1.Xi[i][j]-a2.Xi[i][j];}
     else cout<<"Error";
 return a3;}

QMatr& QMatr:: operator -=(QMatr a)
{if(dim == a.dim)
        for(int i=0;i<a.dim;i++)
            for(int j=0;j<a.dim;j++)
            {Xi[i][j]-=a.Xi[i][j];}
     else cout<<"Error";
 return *this;}

QMatr& QMatr:: operator -()
{for(int i=0;i<dim;i++)
     for(int j=0;j<dim;j++)
        // Xi[i][j]=-1*Xi[i][j];
return *this;}

QMatr operator *(complex<double> X, const QMatr&  a)
{QMatr b; b.dim=a.dim;
    for(int i=0;i<a.dim;i++)
        for(int j=0;j<a.dim;j++)
        {b.Xi[i][j]=a.Xi[i][j]; b.Xi[i][j]*=X;}
return b;}

QMatr operator *(const QMatr& a1, const QMatr& a2)
{QMatr b;
    if(a1.dim==a2.dim)
    {b.dim=a1.dim;
    for(int i=0;i<a1.dim;i++)
        for(int j=0;j<a1.dim;j++)
        {b.Xi[i][j]=a1.Xi[i][j]*a2.Xi[j][i];}}
    else cout<<"Error";
return b;}

QMatr& QMatr:: operator *=(double X)
{for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            Xi[i][j]*=X;
    return *this;}

QMatr& QMatr:: operator /=(double X)
{for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            Xi[i][j]/=X;
    return *this;}

complex<double>* QMatr::operator[](int k)
{
  complex<double> *b;
  b=new complex<double> [dim];
      for(int j=0;j<dim;j++)
          b[j]=Xi[k][j];
  return b;
}

QMatr& QMatr :: operator=(const QMatr& a)
{
    if(dim==a.dim)
    {
        for(int i=0;i<a.dim;i++)
            for(int j=0;j<a.dim;j++)
                Xi[i][j]=a.Xi[i][j];
    }
    else cout<<"Error";

    return *this;
}

complex<double>* QMatr::col(int k)
{
    complex<double> *b;
    b=new complex<double> [dim];
        for(int j=0;j<dim;j++)
            b[j]=Xi[j][k];
 return b;
}

complex<double>* QMatr::diag()
{
    complex<double> *b;
    b=new complex<double> [dim];
        for(int j=0;j<dim;j++)
            b[j]=Xi[j][j];
 return b;
}

QMatr QMatr::transonir(QMatr a)
{
    for(int i=0;i<dim;i++)
    for(int j=0;j<dim;j++)
    {Xi[i][j]=a.Xi[j][i];}
    return *this;
}

void QMatr::transponir(int n)
{
    for (int j=n; j<dim; j++)
    {
        if(Xi[n][j].real()!=0)
        {
            swap_c(n,j);
            break;
        }
    }
}

QMatr QMatr::minor(int n, int m)
{
    QMatr b(dim-1);
    for (int i=0, p=0; p < b.dim; i++, p++)
       for (int j=0, q=0; q < b.dim; j++, q++)
        {
            if(i==n) i++;
            if(j==m) j++;
            b.Xi[p][q] = Xi[i][j];
        }
    return b;
}

complex<double> det(QMatr &A)
{
    complex<double> h=0;
    QMatr B(A);
    for (int k=1; k<=B.dim; k++)
    {
        B.transponir(k-1);
        if(B.Xi[k-1][k-1].real()!=0)
        {
            for (int i=k; i<B.dim; i++)
            {
                h=B.Xi[i][k-1]/B.Xi[k-1][k-1];
                for (int j=0; j<B.dim; j++)
                {
                    B.Xi[i][j]-=h*B.Xi[k-1][j];
                }
                B.Xi[i][k-1]=0;
            }
        }
        else return 0;
    }
    h=1;
    for(int i=0;i<B.dim;i++)
        h*=B.Xi[i][i];
    return h;
}

QMatr Adj(QMatr &A)
{
    double sign;
    QMatr B(A.dim);
    QMatr C(A.dim-1);
    for (int i=0; i<A.dim; i++)
        for (int j=0; j<A.dim; j++)
        {
            ((i+j)%2)==0?(sign=1):(sign=-1);
            C=A.minor(i,j);
            B.Xi[i][j]=sign*det(C);
        }
    return B;
}

QMatr obr(QMatr &A)
{
    QMatr B(A.dim);
    QMatr C(A.dim);
    C.transonir(A);
    complex<double> d=det(A);
    if (d.real()==0)
    {
        cout << "ne syw obrat!!" << endl;
        return 0;
    }
    else {
        B=(Adj(C))/=d;
        return B;
    }
}

QVect QMatr::methodStrok()
{
    QVect b(dim*dim);
	int k = 0;
	int n = dim;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++,k++)
		{
			b[k] = Xi[i][j];
		}
	}
	return b;
}

QVect QMatr::methodStrokConverse()
{
    QVect b(dim*dim);
	int k = 0;
	int n = dim;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < n; j++, k++)
			{
				b[k] = Xi[i][j];
			}
		}
		else
		{
			for (int j = n-1; j>=0 ; j--, k++)
			{
				b[k] =Xi[i][j];
			}
		}

	}
	return b;
}

QVect QMatr::methodSnake()
{
   QVect b(dim*dim);

    int k = 0;

    int n = dim;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i % 2 == 0)
			{
				b[k]=Xi[i - j][j];
				k++;
			}
			else
			{
				b[k] = Xi[j][i - j];
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
					b[k] = Xi[n - j + i][j];
					k++;
				}
				else
				{
					b[k] = Xi[j][n - j + i];
					k++;
				}

			}
			else
			{
				if (n % 2 == 0)
				{
					b[k] = Xi[j][n - j + i] ;
					k++;
				}
				else
				{
					b[k] = Xi[n - j + i][j];
					k++;
				}
			}
		}
	}

	return b;
}

QVect QMatr::methodCycle()
{
    int n = dim;
    QVect b(dim*dim);
	int p = n/2;
	int k = 0;

    for(int i = 1;i <= p; i++)
    {
        for(int j = i-1; j < n-i+1; j++)
        {
            b[k] = Xi[i-1][j];
            k++;
        }
        for(int j = i; j < n-i+1; j++)
        {
            b[k] = Xi[j][n-i];
            k++;
        }
        for(int j = n-i-1; j>=i-1; --j)
        {
            b[k] = Xi[n-i][j];
            k++;
        }
        for(int j = n-i-1;j>=i;j--)
        {
            b[k] = Xi[j][i-1];
            k++;
        }
    }

    if(n%2==1) b[n*n-1]=Xi[p][p];

	return b;
}

void QMatr::fastsort(int k,int bi,int li)
{
    int i, j;
    double temp, s;

    i=bi;
    j=li;
    s=fabs(Xi[k][(bi+li)/2]);
    do
    {
            while(fabs(Xi[k][i]) < s)
            {
                i++;
            }
            while(fabs(Xi[k][j]) > s)
            {
                j--;
            }
            if(i<=j)
            {
                temp=Xi[k][i];
                Xi[k][i]=Xi[k][j];
                i++;
                Xi[k][j]=temp;
                j--;
            }
     } while (i<=j);
     if (bi<j) QMatr::fastsort(k,bi,j);
     if (li>i) QMatr::fastsort(k,i,li);
}

void QMatr::sort(int bi,int li)
{
    QVect temp(dim);
    for(int k=0;k<dim;k++)
    {
        temp = Xi[k];
        temp.sort(bi,li);
        for(int i = 0; i<dim; i++) Xi[k][i] = temp[i];
    }
}

double QMatr::min(int bi,int li)
{
    QVect temp(dim), min(dim);
    for(int k=0;k<dim;k++)
    {
        temp = Xi[k];
        min[k]= temp.min(bi,li);
    }
    return min.min(bi,li);
}

double QMatr::max(int bi,int li)
{
    QVect temp(dim), max(dim);
    for(int k=0;k<dim;k++)
    {
        temp = Xi[k];
        max[k]= temp.max(bi,li);
    }
    return max.max(bi,li);
}

void QMatr::swap_r(int n, int m)
{
    double b;
    for (int j=0; j<dim; j++)
    {
        b=Xi[n][j];
        Xi[n][j]=Xi[m][j];
        Xi[m][j]=b;
    }
}
void QMatr::swap_c(int n, int m)
{
    double b;
    for (int i=0; i<dim; i++)
    {
        b=Xi[i][n];
        Xi[i][n]=Xi[i][m];
        Xi[i][m]=b;
    }
}

void QMatr::nne(int n)
{
    for (int j=n; j<dim; j++)
    {
        if(Xi[n][j]!=0)
        {
            swap_c(n,j);
            break;
        }
    }
}

void QMatr::funcexp ()
{
    complex<double> i (0,1);
    for(int k = 0; k < dim; k++)
        for(int j = 0; j < dim; j++)
        {
            Xi[k][j] = exp((2*PI*k*j*i)/dim);
        }
}

void GaussSol (QMatr &A, QVect &X, QVect &B)
{
    double h=0;
    QMatr A1(A);
    QVect B1(B);
    for (int k=1; k<=A1.dim; k++)
    {
        A1.nne(k-1);
        if(A1.Xi[k-1][k-1]!=0)
        {
            for (int i=k; i<A1.dim; i++)
            {
                h=A1.Xi[i][k-1]/A1.Xi[k-1][k-1];
                for (int j=0; j<A1.dim; j++)
                {
                    A1.Xi[i][j]-=h*A1.Xi[k-1][j];
                }
                A1.Xi[i][k-1]=0;
                B1[i]-=h*B1[k-1];
            }
        }
        else
            {
                cout << "nednorod resh";
                break;
            }
    }
    for (int i=A1.dim-1; i>=0; i--)
    {
        h=0;
        for (int j=A1.dim-1; j>i; j--)
            h+=X[j]*A1.Xi[i][j];
        X[i]=(B1[i]-h)/A1.Xi[i][i];
    }

}
void QMatr:: getLU(QMatr&L, QMatr& U)
{
    U=*this;
    int n=dim;

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            L[j][i]=U[j][i]/U[i][i];

    for(int k = 1; k < n; k++)
    {
        for(int i = k-1; i < n; i++)
            for(int j = i; j < n; j++)
                L[j][i]=U[j][i]/U[i][i];

        for(int i = k; i < n; i++)
            for(int j = k-1; j < n; j++)
                U[i][j]=U[i][j]-L[i][k-1]*U[k-1][j];
    }

}

QMatr QMatr:: proisv(QMatr&L,QMatr&U)
{
    int n=dim;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                Xi[i][j]+=L[i][k]*U[k][j];
    return *this;
}

void QMatr:: Jacobi (double eps, QVect F, QVect X)
{
        int N=dim;
        QVect TempX;
        double norm; // норма, определяемая как наибольшая разность компонент столбца иксов соседних итераций.
        do {
                for (int i = 0; i < N; i++) {
                        TempX[i] =- F[i];
                        for (int g = 0; g < N; g++) {
                                if (i != g)
                                        TempX[i] += Xi[i][g] * X[g];
                        }
                        TempX[i] /= -Xi[i][i];
                }
                norm = fabs(X[0] - TempX[0]);
                for (int h = 0; h < N; h++) {
                        if (fabs(X[h] - TempX[h]) > norm)
                                norm = fabs(X[h] - TempX[h]);
                        X[h] = TempX[h];
                }
        } while (norm > eps);
}

bool QMatr :: isSimmetrial(QMatr coefficients) {
    int numberOfEquation=coefficients.dim;
    bool result = true;
    int i, j;
    for ( i = 0; i < numberOfEquation; i++ ) {
        for ( j = i + 1; j < numberOfEquation; j ++ ) {
            if ( coefficients[i][j] != coefficients[j][i] ) {
                result = false;
                break;
                }
            }
        if (!result) break;
    }
    return result;
}

QVect QMatr:: wrachenie(QMatr coefficients, double precision ) {
    int numberOfEquation=coefficients.dim;
    int result = 1;
    int i, j, k;
    int maxI, maxJ;
    QVect lamda(3);
    double max, fi;
    QMatr solution(coefficients.dim);
    QMatr matricaPoworota(coefficients.dim), temp(coefficients.dim);
    double fault = 0.0;
    for ( i = 0; i < numberOfEquation; i ++ ) {
        for ( j = i + 1; j < numberOfEquation; j ++ ) {
            fault += coefficients[i][j]*coefficients[i][j];
        }
    }
    fault = sqrt( 2*fault );
    while ( fault > precision ) {
        max = 0.0;
        for ( i = 0; i < numberOfEquation; i ++ ) {
            for ( j = i + 1; j < numberOfEquation; j ++ ) {
                if ( coefficients[i][j] > 0 && coefficients[i][j] > max ) {
                    max = coefficients[i][j];
                    maxI = i;
                    maxJ = j;
                }
                else if ( coefficients[i][j] < 0 && - coefficients[i][j] > max ) {
                        max = - coefficients[i][j];
                        maxI = i;
                        maxJ = j;
                    }
            }
        }
        for ( i = 0; i < numberOfEquation; i ++ ){
            for ( j = 0; j < numberOfEquation; j ++ ){
                matricaPoworota[i][j] = 0;
                }
            matricaPoworota[i][i] = 1;
        }
        if ( coefficients[maxI][maxI] == coefficients[maxJ][maxJ] ) {
            matricaPoworota[maxI][maxI] = matricaPoworota[maxJ][maxJ] = matricaPoworota[maxJ][maxI] = sqrt( 2.0 ) / 2.0;
            matricaPoworota[maxI][maxJ] = - sqrt( 2.0 ) / 2.0;
        }
        else {
            fi = 0.5 * atan( ( 2.0 * coefficients[maxI][maxJ] ) / ( coefficients[maxI][maxI] - coefficients[maxJ][maxJ] ) );
            matricaPoworota[maxI][maxI] = matricaPoworota[maxJ][maxJ] = cos( fi );
            matricaPoworota[maxI][maxJ] = - sin( fi );
            matricaPoworota[maxJ][maxI] = sin( fi );
        }
        for ( i = 0; i < numberOfEquation; i ++ ) {
            for ( j = 0; j < numberOfEquation; j ++ ) {
                temp[i][j] = 0.0;
                }
        }
        for ( i = 0; i < numberOfEquation; i ++ ) {
            for ( j = 0; j < numberOfEquation; j ++ ) {
                for ( k = 0; k < numberOfEquation; k ++ ) {
                    temp[i][j] += matricaPoworota[k][i] * coefficients[k][j];
                }
            }
        }
        for ( i = 0; i < numberOfEquation; i ++ ) {
            for ( j = 0; j < numberOfEquation; j ++ ) {
                coefficients[i][j] = 0.0;
            }
        }
        for ( i = 0; i < numberOfEquation; i ++ ) {
            for ( j = 0; j < numberOfEquation; j ++ ) {
                for ( k = 0; k < numberOfEquation; k ++ ) {
                    coefficients[i][j] += temp[i][k] * matricaPoworota[k][j];
                }
            }
        }
        fault = 0.0;
        for ( i = 0; i < numberOfEquation; i ++ ) {
            for ( j = i + 1; j < numberOfEquation; j ++ ) {
                fault += coefficients[i][j]*coefficients[i][j];
            }
        }
        fault = sqrt( 2*fault );
        for ( i = 0; i < numberOfEquation; i ++ ) {
            for ( j = 0; j < numberOfEquation; j ++ ) {
                temp[i][j] = 0.0;
            }
        }
        for ( i = 0; i < numberOfEquation; i ++ ) {
            for ( j = 0; j < numberOfEquation; j ++ ) {
                for ( k = 0; k < numberOfEquation; k ++ ) {
                    temp[i][j] += solution[i][k] * matricaPoworota[k][j];
                }
            }
        }
        *this=temp;
        for ( i = 0; i < numberOfEquation; i ++ ) {
            for ( j = 0; j < numberOfEquation; j ++ ) {
                solution[i][j] = temp[i][j];
            }
        }
        result++;
    }
    for(i=0;i<numberOfEquation;i++) {
            lamda[i]=coefficients[i][i];
    }
    return lamda;
}






