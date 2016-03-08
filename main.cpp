#include"iostream"
#include"QVect.h"
#include"qmatr.h"

using namespace std;

int main()
{
    int n = 5;
    QMatr b(n);
    QVect c(n*n);

    b.fillen();

    cout<<b<<endl;

    c=b.methodCycle();

    cout<<c<<endl;

    /*QMatr d(n);

    d=c.methodCycle();

    cout<<d;*/
    cout<<"min c : = "<<c.min(0,n*n-1)<<endl;

    cout<<"max c : = "<<c.max(0,n*n-1)<<endl;

    c.sort(0,n*n-1);

    cout<<c<<endl;

    b=c.methodCycle();

    cout<<b<<endl;

    cout<<"min b : ="<<b.min(0,n-1)<<endl;

    cout<<"max b : ="<<b.max(0,n-1)<<endl;

    b.sort(0,n-1);

    cout<<b<<endl;

    cout<<obr(b);

    return 0;
}
