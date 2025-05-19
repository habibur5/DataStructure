#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        double n;
        cin>>n;
        if(sqrt(8.0*n-7) == (int)sqrt(8.0*n-7)){
            cout<<"1 ";
        }else{
            cout<<"0 ";
        }
    }
    return 0;
}
// 1209. Triangular Numbers
// https://acm.timus.ru/problem.aspx?space=1&num=1209
