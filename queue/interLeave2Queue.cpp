#include <bits/stdc++.h>
using namespace std;
void interLeave2Queue(queue<int> &q){
  int sz = q.size()/2;
  queue<int>q2;
  while(sz>0){
    q2.push(q.front());
    q.pop();
    --sz;
  }
  while (!q2.empty()){
    q.push(q2.front());
    q2.pop();
    q.push(q.front());
    q.pop();
  }

    while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
  


}
int main(){
  queue<int> q;
  for (int i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
    q.push(i);
  }
  interLeave2Queue(q);



  return 0;


}