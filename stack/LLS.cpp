#include <bits/stdc++.h>
using namespace std;
template <class T>
class Node{
  public:
    T data;
    Node* next;
    
    Node(T val){
      data = val;
      next = NULL;
    }

};



template <class T>
class Stack{
  Node<T>* head;
  public:

    Stack(){
      head = NULL;
    }

    void push(T val){
      Node<T>* newNode = new Node<T>(val);
      if(head == NULL){
        head = newNode;
      }else{
        newNode->next = head;
        head = newNode;
      }
    }
  
    void pop(){
      Node<T>* temp = head;
      head = head->next;
      temp->next = NULL;
      delete temp;
    }
    T top(){
      return head->data;
    }
    
    bool isEmpty(){
      return head == NULL;
    }
};
int main(){
  stack<int> st;
  st.push(3);
  st.push(2);
  st.push(1);

  while( !st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }
  return 0;
}