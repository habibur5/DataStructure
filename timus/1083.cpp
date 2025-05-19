#include <bits/stdc++.h>


using namespace std;


int main(){
    int n;
    string s;
    cin>>n>>s;
    long long int res = 1, size = s.length();

    while(n>=1){
      res*=(n);
      n-=size;
    }
    cout<<res<<endl;
    return 0;
}