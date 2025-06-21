#include <bits/stdc++.h>
using namespace std;
template<class T>
class Node{
  public:
    T data;
    Node* next;
    Node(T data){
      this->data = data;
      this->next = NULL;
    }
};

template<class T>
class Queue{
  Node<T> * head;
  Node<T> *tail;
  public:
    Queue(){
      head = tail = NULL;
    }

    void push(T data){
      Node<T>* newNode = new Node<T>(data);
      if(head == NULL){
        head = tail = newNode;
      }else{
        tail->next = newNode;
        tail = newNode;
      }

    }
    void pop(){
      Node<T>* temp = head;
      head = head->next;
      temp->next = NULL;
      delete temp;
    }
    T front(){
      return head->data;
    }
    bool empty(){
      return head==NULL;
    }
};

int main(){
  Queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);

  while(! q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }

  return 0;
}