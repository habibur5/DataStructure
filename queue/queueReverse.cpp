#include <bits/stdc++.h>
using namespace std;
void reverseQueue(queue<int> &q){
  stack<int> st;
  while(!q.empty()){
    st.push(q.front());
    q.pop();
  }
  while(!st.empty()){
    q.push(st.top());
    st.pop();
  }
}
int main(){
  queue<int> q;
for(auto i :{1,2,3,4,5,6,7,8,9,10}) q.push(i);
reverseQueue(q);
while(!q.empty()) {
  cout<<q.front()<<" ";
  q.pop();
}
  return 0;
}