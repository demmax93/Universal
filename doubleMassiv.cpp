#include <iostream>

using namespace std;

int main(){
    int *a,*b;
    int n,m;
    cout<<"n = ";
    cin>>n;
    cout<<endl<<"m = ";
    cin>>m;
    a = new int[n];
    b = new int[m];
    for(int i = 0; i < n; i++){
        a[i] = i*i+1;
    }
    for(int i = 0; i < m; i++){
        b[i] = i*i;
    }
    for(int i = 0; i < n; i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    for(int i = 0; i < m; i++){
        cout<<b[i]<<"\t";
    }
    cout<<endl;

    int *c = new int[n+m];
    int kn=0;
    int km=0;
    for(int i = 0; i < n + m; i++){
        if(km < m && kn < n){
            if(a[kn] > b[km]){
                c[i] = b[km];
                km++;
            } else {
                c[i] = a[kn];
                kn++;
            }
        } else{
            if(km == m){
                c[i] = a[kn];
                kn++;
            } else if(kn == n){
                c[i] = b[km];
                km++;
            }
        }

    }

    for(int i = 0; i < n + m; i++){
        cout<<c[i]<<"\t";
    }

    return 0;
}
