#include <bits/stdc++.h>
using namespace std;

class Stack{
  queue<int> q1;
  queue<int> q2;
  public:
    void push(int data){
      while (!q1.empty()){
        q2.push(q1.front());
        q1.pop();
      }
      q1.push(data);
      while (!q2.empty()){
        q1.push(q2.front());
        q2.pop();
      }
      
    }
    void pop(){
      q1.pop();
    }
    int top(){
      return q1.front();
    }

    bool empty(){
      return q1.empty();
    }

};
int main(){
  Stack st;
  st.push(1);
  st.push(2);
  st.push(3);

  while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }
  return 0;
}