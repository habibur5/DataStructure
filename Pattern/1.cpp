#include <bits/stdc++.h>
using namespace std;

/* 

*..
**.
***

*/


int main(){
    int n= 3;
    for(int i = 1; i<=n; i++){
      for(int j = 1; j<=i; j++){
        cout<<"*";
      }
      for(int k = i+1; k<=n; k++){
        cout<<".";
      }
      cout<<endl;
    }
    return 0;
}