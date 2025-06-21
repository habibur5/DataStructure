#include <bits/stdc++.h>
using namespace std;
void push_bottom(stack<int> &st, int val){
  if(st.empty()){
    st.push(val);
    return;
  }
  int temp = st.top();
  st.pop();
  push_bottom(st, val);
  st.push(temp);
}
void reverse(stack<int> &st){
  if(st.empty()){
    return;
  }
  int temp = st.top();
  st.pop();
  reverse(st);
  push_bottom(st,temp);
}
int main(){
  stack<int> st;
  st.push(9);
  st.push(8);
  st.push(7);
  st.push(6);
  st.push(5);
  st.push(4);
  st.push(3);
  st.push(2);
  st.push(1);
  push_bottom(st, 10);
  reverse(st);
  cout<<endl;
  while( !st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }
  return 0;
}