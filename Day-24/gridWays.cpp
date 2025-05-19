#include <bits/stdc++.h>
using namespace std;
int ways(int r, int c, int n, int m,string ans){
  if(r==n-1 && c==m-1){
    cout<<ans<<endl;;
    return 1;
  }

  if(r>= n || c>=m){
    return 0;
  }
  int rightVal = ways(r, c+1, n, m,ans+"R ->");

  int downVal = ways(r+1, c, n, m,ans+"D  ->");

  return rightVal+downVal;
}
int main(){
  int n=3;
  int m = 3;
  string ans = ""; 
  cout<<ways(0,0,n,m,ans)<<endl;
  return 0;
}