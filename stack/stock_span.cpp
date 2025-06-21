#include <bits/stdc++.h>
using namespace std;

void stockSpanProblem(vector<int>stock, vector<int> span){
  stack<int>s;
  s.push(0);
  span[0] = 1;
  for(int i = 1; i<stock.size(); i++){
    int current = stock[i];
    while(!s.empty() && current>= stock[s.top()] ){
      s.pop();
    }
    if(s.empty()){
      span[i] = i+1;
    }else{
      int preHigh = s.top();
      span[i] = i-preHigh;
    }
  }
  for(auto it:span){
    cout<<it<<" ";
  }
  cout<<endl;
}

int main(){
  vector<int>stock = {100,80,60,70,60,85,100};
  vector<int> span(7,0);
  stockSpanProblem(stock, span);

  return 0;
}