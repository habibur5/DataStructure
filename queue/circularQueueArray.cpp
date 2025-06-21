#include <bits/stdc++.h>
using namespace std;

template <class T>
class CircularQueue{
  T* arr;
  int capacity;
  int currentSize;
  int front;
  int rear;

  public:
    CircularQueue(int capacity){
      this->capacity = capacity;
      arr = new T[capacity];
      currentSize = 0;
      front = 0;
      rear = -1;

    }
    void push(T data){
      if(currentSize == capacity) return;
      rear = (rear+1) % capacity;
      arr[rear] = data;
      ++currentSize;
    }
    void pop(){
      front = (front+1) % capacity;
      --currentSize; 
    }

    T fr(){
      return arr[front];
    }
    bool empty(){
      return currentSize == 0;
    }
    
};
int main(){
  CircularQueue<int> cq(5);
  cq.push(1);
  cq.push(2);
  cq.push(3);
  cq.push(4);
  cq.push(5);
  cq.pop();
  cq.push(6);
  cout<<cq.fr();
  
  return 0;
}