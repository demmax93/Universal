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
    if(n > m){
        if(a[m-1] > b[m-1]){
            for(int i = n + m - 1; i >= n - 1; i--){
                c[i] = a[i - m];
            }
            int k=0;
            for(int i = 0; i < m; i++){
                if(a[i] > b[i]){
                    c[k] = b[i];
                    c[k+1] = a[i];
                    k += 2;
                } else {
                    c[k] = a[i];
                    c[k+1] = b[i];
                    k += 2;
                }
            }
        } else if(a[m-1] <= b[m-1]){
            for(int i = n + m - 1; i >= n; i--){
                c[i] = a[i - m];
            }
            int k=0;
            for(int i = 0; i < m; i++){
                if(a[i] > b[i]){
                    c[k] = b[i];
                    c[k+1] = a[i];
                    k += 2;
                } else {
                    c[k] = a[i];
                    c[k+1] = b[i];
                    k += 2;
                }
            }
        }
    } else if(m >= n){
        if(a[n-1] > b[n-1]){
            for(int i = m + n - 1; i >= m - 1; i--){
                c[i] = b[i - n];
            }
            int k=0;
            for(int i = 0; i < n; i++){
                if(a[i] > b[i]){
                    c[k] = b[i];
                    c[k+1] = a[i];
                    k += 2;
                } else {
                    c[k] = a[i];
                    c[k+1] = b[i];
                    k += 2;
                }
            }
        } else if(a[n-1] <= b[n-1]){
            for(int i = m + n - 1; i >= m; i--){
                c[i] = b[i - n];
            }
            int k=0;
            for(int i = 0; i < n; i++){
                if(a[i] > b[i]){
                    c[k] = b[i];
                    c[k+1] = a[i];
                    k += 2;
                } else {
                    c[k] = a[i];
                    c[k+1] = b[i];
                    k += 2;
                }
            }
        }
    }

    for(int i = 0; i < n + m; i++){
        cout<<c[i]<<"\t";
    }

    return 0;
}
