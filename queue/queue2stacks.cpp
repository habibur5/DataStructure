#include <bits/stdc++.h>
using namespace std;
class Queue{
  stack<int> st1, st2;
public:
  void push(int data){

    while(!st1.empty()){
      st2.push(st1.top());
      st1.pop();
    }
    st1.push(data);
    while(!st2.empty()){
      st1.push(st2.top());
      st2.pop();
    }
  
  }
  void pop(){
    st1.pop();
  }

  int front(){
    return st1.top();
  }

  bool empty(){
    return st1.empty();
  }
};
int main(){
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);

  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }

  return 0;
}