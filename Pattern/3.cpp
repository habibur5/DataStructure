#include <bits/stdc++.h>
using namespace std;
int main(){
    int n= 3;
    for(int i = 1; i<=n; i++){

      for(int k =1; k<=n-i; k++){
        cout<<".";
      }
      for(int j = 1; j<=i; j++){
        cout<<"*";
      }
      for(int j = 1; j<=i-1; j++){
        cout<<"*";
      }
      for(int k =1; k<=n-i; k++){
        cout<<".";
      }
      
      
      cout<<endl;
      cout<<endl;
    }
    return 0;
}