#include <bits/stdc++.h>
using namespace std;

bool isArmstrong(int n){
  int sum = 0;
  int temp = n;

  int len = to_string(n).length();
  while (temp>0)
  {
    sum+=pow(temp%10, len);
    temp/=10;
  }

  return sum==n?true:false;
  
}
int main(){
  int num;

  cin>>num;
  cout << (isArmstrong(num) ? "true" : "false") << endl;
  return 0;
}